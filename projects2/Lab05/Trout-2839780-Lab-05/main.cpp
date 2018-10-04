/*******************************************************************************
*@author  Evan Trout
*@file    main.cpp
*@date    10/04/2018
*@brief   Main file, calls the MapReader's function and then constructs a
*         flooder and its floodBase function using the output.
*******************************************************************************/

#include <iostream>
#include "MapReader.h"
#include "Flood.h"
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
      MapReader mapRead(argv[1]); //creation of MapReader object
      Flood flooder(mapRead.getMap(), mapRead.getRows(), mapRead.getCols(),  mapRead.getWater()); //creation of Flood object
      flooder.floodBase(mapRead.getStartRow(), mapRead.getStartCol()); //begin recursive flooding
    }
    catch(std::exception const& e)
    {
      std::cout << "Error: " << e.what() << '\n';
    }

  }
  return(0);
}
