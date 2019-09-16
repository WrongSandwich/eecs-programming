/*******************************************************************************
*@author  Evan Trout
*@file    DoubleHashTable.h
*@date    09/16/2019
*@brief   Header file for DoubleHashTable class. Creates and maintains a
*         hash table of Reviews with quadratic hashing.
*******************************************************************************/

#ifndef DOUBLE_HASH_TABLE_H
#define DOUBLE_HASH_TABLE_H

#include <string>
#include "Review.h"

class DoubleHashTable
{
private:
  Review *table; //Pointer to array of Reviews
  int bucketSize; //Tracks the number of buckets
  int probeCount; //Tracks the probe count when hashing
  int constR; //Value of the constant R, used in hPlus
public:
  /**
  * @post creates a Review table with bucketSize 31, initializes all ratings and bools
  * @return the initialized DoubleHashTable
  */
  DoubleHashTable();

  /**
  * @post deallocates memory so hash table can close successfully
  */
  ~DoubleHashTable();

  /**
  * @params name, rating, price: the fields of the new Review for the hash table
  * @post searches for the target, and adds it if not found
  * @return true if successfully added, otherwise false
  */
  bool insert(std::string name, int rating, std::string price);

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
  * @return the ascii value of the string plus the probeCount^2, mod bucketSize
  */
  int hashFunction(std::string target);

  /**
  * @param target: string that is being searched for
  * @post searches hash table for given target
  * @return the number of the bucket that the item is found in, or -1 if not found
  */
  int findByName(std::string target);

  /**
  * @param rating: rating that's being searched for
  * @post prints all matches to given rating
  */
  void searchByRating(int rating);

  /**
  * @param price: price that's being searched for
  * @post prints all matches to given price
  */
  void searchByPrice(std::string price);
};

#endif
