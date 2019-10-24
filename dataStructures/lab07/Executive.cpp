/*******************************************************************************
*@author  Evan Trout
*@file    Executive.cpp
*@date    09/25/19
*@brief   Implementation file for Executive class, which creates and modifies a
*         MinHeap and MaxHeap
*******************************************************************************/

#include "Executive.h"
#include "MinMaxHeap.h"
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
    inFile.close();
    mmHeap.buildHeap(fileName);
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
  while (userInput != 6)
  {
    std::cout << "Please choose one of the following commands:\n";
    std::cout << "1- Insert\n2- Delete\n3- MinLevels\n4- MaxLevels\n";
    std::cout << "5- PrintHeap\n6- Exit\n>";
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
      std::cout << "Please enter the integer which you want to enter into the tree:\n>";
      std::cin >> temp;

      while (std::cin.fail())
      {
        std::cin.clear(); // unset failbit
        // skip bad input up to the next newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be an int. Try again: ";
        std::cin >> userInput;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      if (mmHeap.insert(temp))
      {
        std::cout << temp << " has been inserted successfully!\n";
      }
      else
      {
        std::cout << "Failed to insert value " << temp << "\n";
      }
    }
    else if (userInput == 2) //Delete
    {
      int temp;
      std::cout << "Please enter the integer which you want removed from the tree:\n>";
      std::cin >> temp;

      while (std::cin.fail())
      {
        std::cin.clear(); // unset failbit
        // skip bad input up to the next newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be an int. Try again: ";
        std::cin >> userInput;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      
      if (mmHeap.remove(temp))
      {
        std::cout << temp << " has been removed successfully!\n";
      }
      else
      {
        std::cout << "Failed to remove value " << temp << "\n";
      }
    }
    else if (userInput == 3) //MinLevel
    {
      mmHeap.printMinElements();
      std::cout << "\n";
    }
    else if (userInput == 4) //MaxLevel
    {
      mmHeap.printMaxElements();
      std::cout << "\n";
    }
    else if (userInput == 5) //Level_Order
    {
      mmHeap.levelorder();
      std::cout << "\n";
    }
    else if (userInput == 6) //Exit
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
