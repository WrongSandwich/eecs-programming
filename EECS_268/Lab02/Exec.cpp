/*******************************************************************************
*@author  Evan Trout
*@file    Exec.cpp
*@date    09/19/2018
*@brief   Executive class implementation file. Constructor reads input file into
*         an array of commands, then run() executes them.
*******************************************************************************/

#include "Exec.h"
#include "WebBrowser.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

Exec::Exec(std::string file)
{
  std::ifstream inFile;
  inFile.open(file);
  if(inFile.is_open())
  {
    commArray = new std::string[1];
    int arraySize = 1;
    inFile >> commArray[0];
    std::string* nextArray = nullptr;
    for (int i = 2; !inFile.eof(); i++)
    {
      nextArray = new std::string[i];
      for (int j = 0; j < (i-1); j++)
      {
        nextArray[j] = commArray[j];
      }
      inFile >> nextArray[(i-1)];
      delete[] commArray;
      commArray = nextArray;
      nextArray = nullptr;
      arraySize = i;
    }
    size = arraySize;
    inFile.close();
  }
}

void Exec::run()
{
  std::string command;
  std::string address;
  for (int i = 0; i < size; i++)
  {
    command = commArray[i];
    //NAVIGATE
    if (command == "NAVIGATE")
    {
      i++;
      address = commArray[i];
      wb.navigateTo(address);
    }
    //BACK
    else if (command == "BACK")
    {
      wb.back();
    }
    //FORWARD
    else if (command == "FORWARD")
    {
      wb.forward();
    }
    //HISTORY
    else if (command == "HISTORY")
    {
      wb.printHistory();
    }
  }
  delete[] commArray;
}
