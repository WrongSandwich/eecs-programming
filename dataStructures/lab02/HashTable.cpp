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
