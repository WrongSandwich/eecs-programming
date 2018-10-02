/*******************************************************************************
*@author  Evan Trout
*@file    Fibonacci.h
*@date    09/30/2018
*@brief   Header file for the executive class Fibonacci. Constructor
*         reads flag and target from command line, then calls ith or verify
*         depending on the flag. ith and verify use the fib function to
*         accomplish their task.
*******************************************************************************/
#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <string>

class Fibonacci
{
public:
  /**
  * @param flag: indicates which type of function the Fibonacci should perform
  * @param targetStr: the number that will be used
  * @post creates an instance of Fibonacci and calls the relevant function
  */
  Fibonacci(std::string flag, std::string targetStr);

  /**
  * @pre called when a Fibonacci is created with the flag "-i"
  * @param target: the index of the Fibonacci sequence to be printed
  * @post calls fib for the target index and prints the returned result
  */
  void ith(int target);

  /**
  * @pre called when a Fibonacci is created with the flag "-v"
  * @param target: the number to be checked for in the Fibonacci sequence
  * @post Checks the Fibonacci sequence for target and prints the result
  */
  void verify(int target);

  /**
  * @pre called with an index i by either ith or verify
  * @param i: the index of the Fibonacci sequence requested
  * @return the ith index of the Fibonacci sequence.
  */
  int fib(int i);
};

#endif
