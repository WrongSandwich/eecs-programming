/*******************************************************************************
*@author  Evan Trout
*@file    main.cpp
*@date    08/30/19
*@brief   Main file, calls the executive class's constructor and catches exceptions
*******************************************************************************/

#include <iostream>
#include "Executive.h"
#include <string>
#include <stdexcept>

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
    try {
      Executive ex(argv[1]); //creation of executive object
    }
    catch(std::exception const& e)
    {
      std::cout << "Error: " << e.what() << '\n';
    }
  }
  return(0);
}
