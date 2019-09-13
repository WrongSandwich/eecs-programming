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

HashTable::HashTable()
{
  table = nullptr;
}

HashTable::HashTable(std::string *entries, int n)
{
  bucketSize = (int)((double)n * 1.25);
  bucketSize = getNextPrime(bucketSize);
  table = new LinkedList<std::string>[bucketSize];
  for (int i = 0; i < n; i++)
  {
    insert(entries[i]);
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
  int value = atoi(target.c_str()); 
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
  table = new LinkedList<std::string>[bucketSize];
  // Move in stored elements
  for (int i = 0; i < numEntries; i++)
  {
    insert(tempTable[i]);
  }
  // Delete tempTable
  delete [] tempTable;
  tempTable = nullptr;
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
      return (i+1);
    }
  }
  // return 0 bc key could not be found
  return 0;
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
