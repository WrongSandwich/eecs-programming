/*******************************************************************************
*@author  Evan Trout
*@file    main.cpp
*@date    10/04/2018
*@brief   Main file, calls the MapReader's function and then constructs a
*         flooder and its floodBase function using the output.
*******************************************************************************/

#include <iostream>
#include "Executive.h"
#include <string>
#include <stdexcept>

int main(int argc, char* argv[])
{
  if(argc < 3)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
    try {
      Executive exec(argv[1], argv[2]);
    }
    catch(std::exception const& e)
    {
      std::cout << "Error: " << e.what() << '\n';
    }
  }
  return(0);
}
