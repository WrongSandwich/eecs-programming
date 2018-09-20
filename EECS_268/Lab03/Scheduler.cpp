/*******************************************************************************
*@author  Evan Trout
*@file    Scheduler.cpp
*@date    09/20/2018
*@brief   Implementation file for the executive class Scheduler. Constructor
*         reads inputfile into an array of commands, then run() executes them.
*         Modeled after Exec class from Lab02.
*******************************************************************************/

#include "Scheduler.h"
#include "Queue.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

Scheduler::Scheduler(std::string fileName)
{
  std::ifstream inFile;
  inFile.open(fileName); //Open given file
  if(inFile.is_open())
  {
    commArray = new std::string[1]; //Create an initial array for the first command
    int arraySize = 1;
    inFile >> commArray[0];
    std::string* nextArray = nullptr;
    //Creates a second array and makes it 1 unit larger and fills with next command
    //Then repeats this process until a full array of commands has been created
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

void Scheduler::run()
{
  std::string command;
  std::string processName;
  std::string functionName;
  for (int i = 0; i < size; i++)
  {
    command = commArray[i];
    //START
    if (command == "START")
    {
      i++;
      processName = commArray[i];
    }
    else if (command == "RUN")
    {
      i++;
      functionName = commArray[i];
    }
    else if (command == "RETURN")
    {
      
    }
  }
}
