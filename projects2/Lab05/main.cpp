/*******************************************************************************
*@author  Evan Trout
*@file    main.cpp
*@date    10/04/2018
*@brief   Main file, calls the executive class's constructor and run().
*******************************************************************************/

#include <iostream>
#include "MapReader.h"
#include "Flood.h"
#include <string>

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     MapReader mapRead(argv[1]); //creation of MapReader object
     Flood flooder(mapRead.getMap(), mapRead.getRows(), mapRead.getCols(),  mapRead.getWater());
     flooder.recurseFlood(mapRead.getStartRow(), mapRead.getStartCol());
  }
  return(0);
}
