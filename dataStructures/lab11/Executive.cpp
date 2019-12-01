/*******************************************************************************
*@author  Evan Trout
*@file    Executive.cpp
*@date    10/24/19
*@brief   Implementation file for Executive class, which creates and modifies a
*         MinMaxHeap
*******************************************************************************/

#include "Executive.h"
#include "DisjointSet.h"
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
    int count = 0;
    int temp;
    while (inFile >> temp)
    {
      count++;
    }
    if (count > 0)
    {
      set.loadArray(fileName, count);
    }
    else
    {
      throw std::runtime_error("ERROR: No elements in file");
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
  bool setBuilt = false;
  while (userInput != 5)
  {
    std::cout << "Please choose one of the following commands:\n";
    std::cout << "1- MakeSet\n2- StartUnion\n3- Find_Timer\n";
    std::cout << "4- Path_Compression\n5- Exit\n>";
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

    if (userInput == 1) //MakeSet
    {
      if (setBuilt)
      {
        std::cout << "The disjoint sets have already been constructed; please choose another option\n";
      }
      else
      {
        set.makeSet();
        setBuilt = true;
        std::cout << "The disjoint sets have been constructed\n";
      }
    }
    else if (userInput == 2) //StartUnion
    {
      std::cout << "Enter the representative elements for the two sets which you wish to union:\n>";
      int temp1, temp2;
      std::cin >> temp1;
      while (std::cin.fail())
      {
        std::cin.clear(); // unset failbit
        // skip bad input up to the next newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be an int. Try again: ";
        std::cin >> temp1;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << '>';
      std::cin >> temp2;
      while (std::cin.fail())
      {
        std::cin.clear(); // unset failbit
        // skip bad input up to the next newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be an int. Try again: ";
        std::cin >> temp2;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      int result = set.unionDS(temp1, temp2);
      if (result == -1)
      {
        std::cout << "One or both of the given values could not be found; union aborted\n";
      }
      else if (result == -2)
      {
        std::cout << "The given elements are already in the same set; union aborted\n";
      }
      else
      {
        std::cout << "Union on " << temp1 << " and " << temp2 << " has been completed.";
        std::cout << "The representative element is " << result << '\n';
      }
    }
    else if (userInput == 3) //Find_timer
    {
      std::cout << "This option is under construction\n";
    }
    else if (userInput == 4) //Path_Compression
    {
      std::cout << "This option is under construction\n";
    }
    else if (userInput == 5) //Exit
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
