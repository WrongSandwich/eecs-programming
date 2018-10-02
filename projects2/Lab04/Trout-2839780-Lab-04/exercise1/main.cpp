/*******************************************************************************
*@author  Evan Trout
*@file    main.cpp
*@date    09/21/2018
*@brief   Main file, calls the executive class's constructor and run().
*******************************************************************************/

#include <iostream>
#include "Checker.h"
#include <string>

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     Checker check(argv[1]); //creation of executive object
     check.run(); //handles the calling of all other member methods
  }
  return(0);
}
