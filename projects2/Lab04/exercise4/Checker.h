/*******************************************************************************
*@author  Evan Trout
*@file    Checker.cpp
*@date    09/29/2018
*@brief   Header file for the executive class Checker. Constructor
*         reads command line argument class's members, then run() checks to see
*         if it's balanced.
*******************************************************************************/

#ifndef CHECKER_H
#define CHECKER_H

#include <string>

class Checker
{
private:
  std::string fileName;
  std::string origStr;
  std::string str;
  int strLength;

public:
  /**
  * @param file: a string of parentheses to be checked
  * @post the given string is saved to be used by run() and test()
  * @return the constructed Checker, with string and its length saved as members
  */
  Checker(std::string fileName);

  /**
  * @pre the Checker has been created successfully with a valid string and length
  * @post Checks if array is of even length, and if so calls test()
  */
  void run();

  /**
  * @pre run() determines that the length of the string is even and can be tested
  * @post recursively checks to see if string is balanced and prints result
  */
  void test();
};

#endif
