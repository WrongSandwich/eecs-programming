/*******************************************************************************
*@author  Evan Trout
*@file    main.cpp
*@date    09/21/2018
*@brief   Main file, calls the executive class's constructor.
*******************************************************************************/

#include <iostream>
#include "Fibonacci.h"
#include <string>

int main(int argc, char* argv[])
{
  if(argc < 3)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     Fibonacci fib(argv[1], argv[2]); //creation of executive object
  }
  return(0);
}
