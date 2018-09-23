/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 10
 * Description: Create a program that reads and allows the user to interact with DMV records.
 * Date: 04/16/18
 * ------------------------------------------------------------------------------- */
#include "DMV.h"
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
  if(argc > 1)
  {
    std::string fileName = argv[1];
    std::ifstream inFile;
    inFile.open(fileName);
    if (inFile.is_open())
    {
      inFile.close();
      DMV myDMV(fileName);
      myDMV.run();
    }
    else
    {
      std::cout << "ERROR: Please enter a valid file name\n";
    }
  }
  else
  {
    std::cout << "ERROR: Please enter a valid file name\n";
  }
  return(0);
}
