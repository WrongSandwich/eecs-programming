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
#include "QuadHashTable.h"
#include "DoubleHashTable.h"

Executive::Executive(std::string fileName)
{
  std::ifstream inFile;
  inFile.open(fileName);
  if (inFile.is_open())
  {
    //TODO: Correctly populate hash tables
  }
  //TODO: throw error if file won't open
  inFile.close();
  userInterface();
}

Executive::~Executive()
{
}

void Executive::userInterface()
{
  int userInput = 0;
  while (userInput != 7)
  {
    std::cout << "Please choose one of the following commands:\n";
    std::cout << "1- Insert\n2- Delete\n3- FindByRating\n4- SearchByRating\n";
    std::cout << "5- SearchByPrice\n6- Print\n7- Exit\n>";
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
      std::cout << "Enter the data to be inserted: "\n\n>;
      std::cin >> temp;
      std::cout << '\n\n';
      if (std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be a valid string. Returning to main menu...\n";
      }
      else
      {
        // Move data into appropriate variables
        std::stringstream in(temp);
        std::string name, price;
        int rating;
        in >> name;
        in >> rating;
        in >> price;
        // Attempt to insert into quad
        std::cout << "Quadratic probing: " << name;
        if (quad.findByName(name) != -1)
        {
          std::cout << " is duplicated, can't be added to the hash table.\n\n";
        }
        else if (quad.insert(name, rating, price))
        {
          std::cout << " is inserted into the hash table.\n\n";
        }
        else
        {
          std::cout << " could not be inserted into the hash table.\n\n";
        }
        // Attempt to insert into double
        std::cout << "Double hashing: " << name;
        if (double.findByName(name) != -1)
        {
          std::cout << " is duplicated, can't be added to the hash table.\n\n";
        }
        else if (double.insert(name, rating, price))
        {
          std::cout << " is inserted into the hash table.\n\n";
        }
        else
        {
          std::cout << " could not be inserted into the hash table.\n\n";
        }
      }
    }
    else if (userInput == 2) //Delete
    {
      std::string temp;
      std::cout << "Enter a restauraunt to be deleted:\n\n>";
      std::cin >> temp;
      std::cout << '\n\n';
      if (std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be an int. Returning to main menu...\n";
      }
      else
      {
        // Remove from quad
        std::cout << "Quadratic probing: " << temp;
        if (quad.remove(temp))
        {
          std::cout << " is deleted from the hash table";
        }
        else
        {
          std::cout << " could not be found in the hash table";
        }
        // Remove from double
        std::cout << "Double hashing: " << temp;
        if (double.remove(temp))
        {
          std::cout << " is deleted from the hash table";
        }
        else
        {
          std::cout << " could not be found in the hash table";
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
        int location = hashTable->find(temp);
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
      hashTable->print();
    }
    else if (userInput == 5) //Exit
    {
      std::cout << "Exiting\n";
    }
    else //Invalid input
    {
      std::cout << "Please enter a valid menu option\n";
    }
    std::cout << "------------------------------------------------------\n";
  }
}
