/*******************************************************************************
*@author  Evan Trout
*@file    Executive.cpp
*@date    09/16/19
*@brief   Implementation file for Executive class, which creates and modifies a
*         DoubleHashTable and QuadHashTable
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
    std::string temp = "";
    std::string storage = "";
    int count = 0;
    while (inFile >> temp)
    {
      storage.append(temp);
      storage.pop_back(); // removes last char in string (a comma)
      storage.append(" ");
      count++;
    }
    if (count % 3 == 0) // make sure there's a proper number of elements
    {
      // use a stringstream to read in the items one by one
      // then add each set of three to the array
      std::stringstream in(storage);
      std::string temp, name, price;
      int rating = 0;
      int tracker = 1;
      while (in >> temp)
      {
        if (tracker == 1)
        {
          name = temp;
        }
        if (tracker == 2)
        {
          rating = stoi(temp);
        }
        if (tracker == 3)
        {
          price = temp;
          quad.insert(name, rating, price);
          dbl.insert(name, rating, price);
          tracker = 0;
        }
        tracker++;
      }
      inFile.close();
      userInterface();
    }
    else
    {
      std::cout << "ERROR: Input file contains incorrect number of elements\n\n";
    }
  }
  else 
  {
    std::cout << "ERROR: Could not open file\n\n";
  }
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
    std::cout << "1- Insert\n2- Delete\n3- FindByName\n4- SearchByRating\n";
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
      std::cout << "Enter the data to be inserted in the following format: name rating price \n\n>";
      std::getline(std::cin, temp);
      std::cout << '\n';
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
        // Attempt to insert into dbl
        std::cout << "Double hashing: " << name;
        if (dbl.findByName(name) != -1)
        {
          std::cout << " is duplicated, can't be added to the hash table.\n\n";
        }
        else if (dbl.insert(name, rating, price))
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
      std::cout << '\n';
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
          std::cout << " is deleted from the hash table\n\n";
        }
        else
        {
          std::cout << " could not be found in the hash table\n\n";
        }
        // Remove from dbl
        std::cout << "Double hashing: " << temp;
        if (dbl.remove(temp))
        {
          std::cout << " is deleted from the hash table\n\n";
        }
        else
        {
          std::cout << " could not be found in the hash table\n\n";
        }
      }
    }
    else if (userInput == 3) //Find by name
    {
      std::string temp;
      std::cout << "Enter a restaurant name to search for: \n\n>";
      std::cin >> temp;
      std::cout << '\n';
      if (std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be a string. Returning to main menu...\n";
      }
      else
      {
        // Search in quad
        std::cout << "Quadratic probing: " << temp;
        int quadAddress = quad.findByName(temp);
        if (quadAddress == -1)
        {
          std::cout << " could not be found\n\n";
        }
        else
        {
          std::cout << " has been found at location " << quadAddress << "\n\n";
        }
        // Search in dbl
        std::cout << "Double hashing: " << temp;
        int dblAddress = dbl.findByName(temp);
        if (dblAddress == -1)
        {
          std::cout << " could not be found\n\n";
        }
        else
        {
          std::cout << " has been found at location " << dblAddress << "\n\n";
        }
      }
    }
    else if (userInput == 4) //Search by rating
    {
      int temp;
      std::cout << "Enter a rating from 1-5 to search for: \n\n>";
      std::cin >> temp;
      std::cout << '\n';
      if (std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be an int. Returning to main menu...\n";
      }
      else if (temp < 1 || temp > 5)
      {
        std::cout << "Please enter a valid rating from 1-5. Returning to main menu...\n\n";
      }
      else
      {
        // Search in quad
        std::cout << "Quadratic probing: ";
        quad.searchByRating(temp);
        // Search in dbl
        std::cout << "Double hashing: ";
        dbl.searchByRating(temp);
      }
    }
    else if (userInput == 5) //Search by price
    {
      std::string temp;
      std::cout << "Enter your price range: \n\n>";
      std::cin >> temp;
      std::cout << '\n';
      if (std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be a string. Returning to main menu...\n";
      }
      else
      {
        // Search in quad
        std::cout << "Quadratic probing: ";
        quad.searchByPrice(temp);
        // Search in dbl
        std::cout << "Double hashing: ";
        dbl.searchByPrice(temp);
      }
    }
    else if (userInput == 6) // print
    {
      // Print in quad
      std::cout << "Quadratic probing: \n";
      quad.print();
      std::cout << "\n\n";
      // Print in dbl
      std::cout << "Double hashing: \n";
      dbl.print();
      std::cout << "\n\n";
    }
    else if (userInput == 7)
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
