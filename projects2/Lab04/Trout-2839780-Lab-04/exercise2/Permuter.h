/*******************************************************************************
*@author  Evan Trout
*@file    Permuter.h
*@date    10/02/2018
*@brief   Header file for the executive class Permuter. Constructor
*         takes the given string and stores it and its size, then calls run(),
*         which in turn calls the iterative permuter.
*******************************************************************************/

#ifndef PERMUTER_H
#define PERMUTER_H

#include <string>

class Permuter
{
private:
  std::string origStr;
  std::string str;
  std::string prefix;
  int strLength;
public:
  /**
  * @param origStr: a user-inputted string to permute
  * @post the given string is saved and run() is called with its length
  * @return the constructor Permuter
  */
  Permuter(std::string origStr);

  /**
  * @param length: the length of the given string
  * @pre the Permuter has been created with a valid string, and has called run()
  * @post initializes prefix and spot, then calls permute
  */
  void run(int length);

  /**
  * @param length: the length of the given string
  * @param spot: the current location within the prefix string
  * @post adds and removes characters from prefix and str and recursively calls
  *       itself in order to print all permutations of the given string
  */
  void permute(int length, int spot);
};

#endif
