/*******************************************************************************
*@author  Evan Trout
*@file    HashTable.h
*@date    09/09/2019
*@brief   Header file for HashTable class. Creates and maintains a
*         hash table of strings.
*******************************************************************************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <stdexcept>

#include "LinkedList.h"

class HashTable
{
private:
  LinkedList<std::string> *table;
  int numEntries;
  int bucketSize;
public:
  HashTable();
  HashTable(std::string* entries, int n);
  ~HashTable();
  bool insert(std::string newEntry);
  bool remove(std::string target);
  void print();
  int hashFunction(std::string target);
  void rehash();
  int find(std::string key);
  int getNextPrime(int n);
};

#endif