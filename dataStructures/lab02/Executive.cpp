/*******************************************************************************
*@author  Evan Trout
*@file    Executive.cpp
*@date    08/30/19
*@brief   Implementation file for Executive class, which creates and modifies a
*         DoublyLinkedList based on user input
*******************************************************************************/

#include "Executive.h"
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
    std::string temp;
    while (inFile >> temp)
    {
      hashTable.insert(temp);
    }
  }
  inFile.close();
  userInterface();
}

Executive::~Executive()
{
}

void Executive::userInterface()
{
  int userInput = 0;
  while (userInput != 5)
  {
    std::cout << "Please choose one of the following commands:\n";
    std::cout << "1- Insert\n2- Delete\n3- Find\n4- Print\n5- Exit\n";
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
      std::string temp;
      std::cout << "Enter an element to be inserted: ";
      std::cin >> temp;
      if (std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be a valid string. Returning to main menu...\n";
      }
      else
      {
        bool success = hashTable.insert(temp);
        if (success)
        {
          std::cout << temp << " is added to the hash table.\n";
        }
        else
        {
          std::cout << temp << " was not added successfully.\n"
        }
        
      }
    }
    else if (userInput == 2) //Delete
    {
      std::string temp;
      std::cout << "Enter an element to be removed: ";
      std::cin >> temp;
      std::cout << '\n';
      if (std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be an int. Returning to main menu...\n";
      }
      else
      {
        bool success = hashTable.remove(temp);
        if (success)
        {
          std::cout << temp << " is removed from the hash table.\n";
        }
        else
        {
          std::cout << temp << " could not be found in the hash table.\n";
        }
      }
    }
    else if (userInput == 3) //Find
    {
      std::string temp;
      std::cout << "Enter an element to be found: ";
      std::cin >> temp;
      std::cout << '\n';
      if (std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be an int. Returning to main menu...\n";
      }
      else
      {
        int location = hashTable.find(temp);
        if (location != -1)
        {
          std::cout << temp << " is found at location " << location << ".\n";
        }
        else
        {
          std::cout << temp << " is not found.\n";
        }
      }    
    }
    else if (userInput == 4) //Print
    {
      hashTable.print();
    }
    else if (userInput == 5) //Exit
    {
      std::cout << "Exiting";
    }
    else //Invalid input
    {
      std::cout << "Please enter a valid menu option\n";
    }
  }
}