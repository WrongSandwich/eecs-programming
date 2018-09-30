/*******************************************************************************
*@author  Evan Trout
*@file    Checker.cpp
*@date    09/29/2018
*@brief   Header file for the executive class Checker. Constructor
*         reads command line argument class's members, then run() removes filler
*         characters and checks to see if the resulting string is even in length
*         before sending it to test(). Test then checks char-by-char to confirm
*         the string is balanced.
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
  * @param file: a string to be checked for balance
  * @post the given string is saved to be used by run() and test()
  * @return the constructed Checker, with string and its length saved as members
  */
  Checker(std::string fileName);

  /**
  * @pre the Checker has been created successfully with a valid string and length
  * @post Removes filler from string, then checks if it's even before sending to test()
  */
  void run();

  /**
  * @pre run() pares down the string and sends it to test
  * @post recursively checks to see if string is balanced and prints result
  */
  void test();
};

#endif
