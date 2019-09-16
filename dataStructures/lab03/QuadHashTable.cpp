/*******************************************************************************
*@author  Evan Trout
*@file    QuadHashTable.cpp
*@date    09/16/2019
*@brief   Implementation file for QuadHashTable class. Creates and maintains a
*         hash table of Reviews with quadratic hashing.
*******************************************************************************/

#include "QuadHashTable.h"
#include "Review.h"

#include <iostream>
#include <string>

QuadHashTable::QuadHashTable()
{
  bucketSize = 31;
  table = new Review[31];
  for (int i = 0; i < bucketSize; i++)
  {
    table[i].rating = 0;
    table[i].deleted = false;
  }
}

QuadHashTable::~QuadHashTable()
{
  delete [] table;
  table = nullptr;
}

bool QuadHashTable::insert(std::string name, int rating, std::string price)
{
  for (probeCount = 0; probeCount < 31; probeCount++)
  {
    int hash = hashFunction(name);
    if (table[hash].rating == 0)
    {
      table[hash].name = name;
      table[hash].rating = rating;
      table[hash].price = price;
      return true;
    }
  }
  return false; //No empty spots
}

bool QuadHashTable::remove(std::string target)
{
  int address = findByName(target);
  if (address == -1)
  {
    return false;
  }
  else
  {
    table[address].name = "";
    table[address].rating = 0;
    table[address].price = "";
    table[address].deleted = true;
    return true;
  }
}

void QuadHashTable::print()
{
  for (int i = 0; i < bucketSize; i++)
  {
    std::cout << i << ": " << table[i].name << ", " << table[i].rating;
    std::cout << ", " << table[i].price << '\n';
  }
}

int QuadHashTable::hashFunction(std::string target)
{
  int value = 0;
  for (int i = 0; i < target.length(); i++)
  {
    value += int(target[i]); // Calculating ascii value of name
  }
  int hash = (value + probeCount^2) % bucketSize;
  return hash;
}

int QuadHashTable::findByName(std::string target)
{
  for (probeCount = 0; probeCount < 31; probeCount++)
  {
    int hash = hashFunction(target);
    if (table[hash].name == target)
    {
      return hash;
    }
    // location is empty and hasn't been deleted -> never filled
    else if (table[hash].deleted == false && table[hash].rating == 0)
    {
      return -1;
    }
  }
  return -1;
}

void QuadHashTable::searchByRating(int rating)
{
  for (int i = 0; i < bucketSize; i++)
  {
    if (table[i].rating == rating)
    {
      std::cout << table[i].name << " ";
    }
  }
  std::cout << '\n';
}

void QuadHashTable::searchByPrice(std::string price)
{
  for (int i = 0; i < bucketSize; i++)
  {
    if (table[i].price == price)
    {
      std::cout << table[i].name << " ";
    }
  }
  std::cout << '\n';
}
