/*******************************************************************************
*@author  Evan Trout
*@file    Fibonacci.cpp
*@date    09/30/2018
*@brief   Implementation file for the executive class Fibonacci. Constructor
*         reads flag and target from command line, then calls ith or verify
*         depending on the flag. ith and verify use the fib function to
*         accomplish their task.
*******************************************************************************/
#include "Fibonacci.h"
#include <iostream>
#include <string>

Fibonacci::Fibonacci(std::string flag, std::string targetStr)
{
  int target = std::stoi(targetStr);
  if (flag == "-i")
  {
    ith(target);
  }
  else if (flag == "-v")
  {
    verify(target);
  }
  else
  {
    std::cout << "ERROR: Please enter a valid flag\n";
  }
}

void Fibonacci::ith(int target)
{
  std::cout << fib(target) << '\n';
}

void Fibonacci::verify(int target)
{
  int j = 0;
  int i = 0;
  do
  {
    j = fib(i);
    i++;
  } while (j < target);
  if (j == target)
  {
    std::cout << target << " is in the sequence\n";
  }
  else
  {
    std::cout << target << " is not in the sequence\n";
  }
}

int Fibonacci::fib(int i)
{
  if (i == 0)
  {
    return 0;
  }
  else if (i == 1)
  {
    return 1;
  }
  else
  {
    return (fib(i-1) + fib(i-2));
  }
}
