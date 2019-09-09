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


HashTable::HashTable(std::string[] entries, int n)
{
  bucketSize = (int)((double)n * 1.25);
  bucketSize = getNextPrime(bucketSize);
  table = new LinkedList<std::string>[bucketSize];
  for (int i = 0; i < entries.size(); i++)
  {
    insert(entries[i]);
  }
}

HashTable::~HashTable()
{
  delete [] table;
  table = nullptr;
}

//TODO: add search function
bool HashTable::insert(std::string newEntry)
{
  int address = hashFunction(newEntry);
  if (table[address].search(newEntry))
  {
    return false;
  }
  else
  {
    table[address].insert(1, newEntry);
    numEntries++;
    return true;
  }
}

//TODO: alter remove to be search-based
bool HashTable::delete(std::string target)
{
  int address = hashFunction(target);
  if (table[address].remove(newEntry))
  {
    numEntries--;
    return true;
  }
  else
  {
    return false;
  }
}

void HashTable::print()
{
  for (int i = 0; i < table.size(); i++)
  {
    std::cout << i << ":";
    table[i].print();
    std::endl;
  }
}

int HashTable::hashFunction(std::string target)
{
  double value = atof(target);
  int hash = (int)(value % bucketSize);
  return hash;
}

void HashTable::rehash()
{
  // Move data to temp table
  std::string* tempTable = new std::string[numEntries];
  for (int i = 0; i < table.size(); i++)
  {
    //TODO: Retrieve items from each LinkedList
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
