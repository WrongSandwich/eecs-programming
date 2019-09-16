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
  LinkedList<std::string> *table; //Pointer to array of LinkedLists
  int numEntries; //Tracks the total number of entries
  int bucketSize; //Tracks the number of buckets
  double loadFactor; //Tracks the load factor
public:
  /**
  * @post creates a LinkedList and sets headPtr to nullptr and itemCount to 0
  * @return the initialized LinkedList
  */
  HashTable();
  
  /**
  * @param entries: space-separated list of strings to add to hash table
  * @param n: the number of entries
  * @post creates a hash table and populates it with the given entries
  */
  HashTable(std::string entries, int n);
  
  /**
  * @post deallocates memory so hash table can close successfully
  */
  ~HashTable();
  
  /**
  * @param newEntry: the string being added to the hash table
  * @post searches for the target, and adds it if not found
  * @return true if successfully added, otherwise false
  */
  bool insert(std::string newEntry);
  
  /**
  * @param target: the string being removed from the hash table
  * @post searches for the target, and deletes it if found
  * @return true if successfully deleted, otherwise false
  */
  bool remove(std::string target);
  
  /**
  * @post prints the contents of the hash table
  */
  void print();
  
  /**
  * @param target: the string for which the hash function is being calculated
  * @return the ascii value of the string, mod bucketSize
  */
  int hashFunction(std::string target);
  
  /**
  * @pre function is called when load factor becomes greather than 1
  * @post rehashes table
  */
  void rehash();
  
  /**
  * @param key: string that is being searched for
  * @post searches hash table for given key
  * @return the number of the bucket that the item is found in, or -1 if not found
  */
  int find(std::string key);
  
  /**
  * @param n: number to start from
  * @return the smallest prime number greater than n
  */
  int getNextPrime(int n);
  
  /**
  * @post updates the load factor value
  */
  void updateLoadFactor();
};

#endif