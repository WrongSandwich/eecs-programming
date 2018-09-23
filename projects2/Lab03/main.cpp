/*******************************************************************************
*@author  Evan Trout
*@file    main.cpp
*@date    09/21/2018
*@brief   Main file, calls the executive class's constructor and run().
*******************************************************************************/

#include <iostream>
#include "Scheduler.h"
#include <string>

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     Scheduler ex(argv[1]); //creation of executive object
     ex.run(); //handles the calling of all other member methods
  }
  return(0);
}
