/*******************************************************************************
*@author  Evan Trout
*@file    Executive.cpp
*@date    10/24/19
*@brief   Implementation file for Executive class, which creates and modifies a
*         MinMaxHeap
*******************************************************************************/

#include "Executive.h"
#include "SkewHeap.h"
#include <string>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <fstream>
#include <iostream>

Executive::Executive(std::string fileName)
{

  std::ifstream inFile;
  inFile.open(fileName);
  if (inFile.is_open())
  {
    int temp;
    bool success = true;
    while (inFile >> temp)
    {
      success = heap.insert(temp);
      if (!success)
      {
        throw std::runtime_error("Heap building failed -> please remove duplicate/invalid elements from input file");
      }
    }
    userInterface();
  }
  else
  {
    throw std::runtime_error("ERROR: Could not open file");
  }
}

Executive::~Executive()
{
}

void Executive::userInterface()
{
  int userInput = 0;
  while (userInput != 4)
  {
    std::cout << "Please choose one of the following commands:\n";
    std::cout << "1- Insert\n2- DeleteMin\n3- LevelOrder\n4- Exit\n>";
    std::cin >> userInput;
    std::cout << '\n';

    //Validation of user input.

    while (std::cin.fail())
    {
      std::cin.clear(); // unset failbit
      // skip bad input up to the next newline
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Sorry, your input did not seem to be an int. Try again: ";
      std::cin >> userInput;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //END OF VALIDATION

    if (userInput == 1) //Insert
    {
      int temp;
      std::cout << "Enter an integer value to be inserted into the binomial heap:\n>";
      std::cin >> temp;

      while (std::cin.fail())
      {
        std::cin.clear(); // unset failbit
        // skip bad input up to the next newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be an int. Try again: ";
        std::cin >> temp;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      if (heap.insert(temp))
      {
        std::cout << temp << " has been inserted successfully!\n";
      }
      else
      {
        std::cout << "Failed to insert value " << temp << "\n";
      }
    }
    else if (userInput == 2) //DeleteMin
    {
      if (heap.deleteMin())
      {
        std::cout << "Minimum element was successfully deleted.\n";
      }
      else
      {
        std::cout << "Minimum element could not be deleted. \n";
      }
    }
    else if (userInput == 3) //Levelorder
    {
      std::cout << "Local Level Order:\n\n";
      heap.levelorder();
      std::cout << "\n";
    }
    else if (userInput == 4) //Exit
    {
      std::cout << "Exiting...\n";
    }
    else //Invalid input
    {
      std::cout << "Please enter a valid menu option\n";
    }
    std::cout << "------------------------------------------------------\n";
  }
}
