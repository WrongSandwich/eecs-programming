/*******************************************************************************
*@author  Evan Trout
*@file    main.cpp
*@date    09/21/2018
*@brief   Main file, calls the executive class's constructor.
*******************************************************************************/

#include <iostream>
#include "Permuter.h"
#include <string>

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     Permuter perm(argv[1]); //creation of executive object
  }
  return(0);
}
