/*******************************************************************************
*@author  Evan Trout
*@file    HashTable.cpp
*@date    09/09/2019
*@brief   Implementation file for HashTable class. Creates and maintains a
*         hash table of strings.
*******************************************************************************/

#include "HashTable.h"
#include "LinkedList.h"

#include <iostream>
#include <string>
#include <sstream>

HashTable::HashTable()
{
  numEntries = 0;
  bucketSize = 1;
  table = new LinkedList<std::string>[bucketSize];
  updateLoadFactor();
}

HashTable::HashTable(std::string entries, int n)
{
  bucketSize = (int)((double)n * 1.25);
  bucketSize = getNextPrime(bucketSize);
  table = new LinkedList<std::string>[bucketSize];
  std::stringstream in(entries);
  std::string temp;
  while (in >> temp)
  {
    insert(temp);
  }
}

HashTable::~HashTable()
{
  delete [] table;
  table = nullptr;
}

bool HashTable::insert(std::string newEntry)
{
  int address = hashFunction(newEntry);
  int position = table[address].search(newEntry);
  if (position != 0)
  {
    // Item was found, can't add duplicate
    return false;
  }
  else
  {
    table[address].insert(1, newEntry);
    numEntries++;
    updateLoadFactor();
    if(loadFactor > 1)
    {
      rehash();
    }
    return true;
  }
}

bool HashTable::remove(std::string target)
{
  int address = hashFunction(target);
  int position = table[address].search(target);
  if (position == 0)
  {
    // item not found, can't remove
    return false;
  }
  else
  {
    table[address].remove(position);
    numEntries--;
    return true;
  }
}

void HashTable::print()
{
  for (int i = 0; i < bucketSize; i++)
  {
    std::cout << i << ":";
    table[i].print();
    std::cout << '\n';
  }
}

int HashTable::hashFunction(std::string target)
{
  // This is the only time I use a string method and it's just to have it represented
  // as a char array, pls don't take my points
  int value = 0;
  for (int i = 0; i < target.length(); i++)
  {
    value += int(target[i]);
  }
  int hash = (int)value % bucketSize;
  return hash;
}

void HashTable::rehash()
{
  // Move data to temp table
  std::string* tempTable = new std::string[numEntries];
  // Copy LinkedList data to temp array
  int cur = 0;
  for (int i = 0; i < bucketSize; i++)
  {
    int bucketLength = table[i].getLength();
    for (int j = 1; j <= bucketLength; j++)
    {
      tempTable[cur] = table[i].getEntry(j);
      cur++;
    }
  }
  // Calculate new bucket size
  bucketSize = bucketSize * 2;
  bucketSize = getNextPrime(bucketSize);
  // Create new table using bucket size
  delete [] table;
  table = nullptr;
  table = new LinkedList<std::string>[bucketSize];
  int newEntries = numEntries;
  numEntries = 0;
  for (int i = 0; i < newEntries; i++)
  {
    insert(tempTable[i]);
  }
  // Delete tempTable
  delete [] tempTable;
  tempTable = nullptr;
  updateLoadFactor();
  // Report success
  std::cout << "Hash table is rehashed.\n";
}

int HashTable::find(std::string key)
{
  for (int i = 0; i < bucketSize; i++)
  {
    if (table[i].search(key))
    {
      // key is found, return location
      return (i);
    }
  }
  // return 0 bc key could not be found
  return -1;
}

int HashTable::getNextPrime(int n)
{
  bool prime = false;
  while (!prime)
  {
    bool flag = false;
    for (int i = 2; i <= n/2; ++i)
    {
      if (n % i == 0)
      {
        flag = true;
        break;
      }
    }
    if (flag) // not prime
    {
      n++;
    }
    else
    {
      prime = true;
      return n;
    }
  }
}

void HashTable::updateLoadFactor()
{
  loadFactor = (double)numEntries/(double)bucketSize;
}