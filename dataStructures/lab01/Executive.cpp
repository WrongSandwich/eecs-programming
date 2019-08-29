/*******************************************************************************
*@author  Evan Trout
*@file    Executive.cpp
*@date    12/06/18
*@brief   Implementation file for Executive class, which stores input commands
*         in an array then uses them to build and modify a binary search tree.
*******************************************************************************/


#include "Executive.h"
#include "DoublyLinkedList.h"
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>

Executive::Executive(std::string fileName)
{
  std::ifstream inFile;
  inFile.open(fileName);
  if (inFile.is_open())
  {
    int temp;
    while (!inFile.eof())
    {
      inFile >> temp;
      dll.insert(temp);
    }
  }
  inFile.close();
  userInterface();
}

Executive::~Executive()
{}

void Executive::userInterface()
{
  int userInput = 0;
  while (userInput != 9) {
    std::cout << "Choose from one of the options below:\n";
    std::cout << "1. Insert\n2. Delete\n3. Find smallest number\n4. Find largest number\n";
    std::cout << "5. Average\n6. Merge 2 lists\n7. Print\n8. Reverse list\n9. Exit\n";
    std::cin >> userInput;
    if (userInput == 1) //Insert
    {
      int temp;
      std::cout << "Enter element to be inserted in list: ";
      std::cin >> temp;
      dll.insert(temp);
    }
    else if (userInput == 2) //Delete
    {
      int temp;
      std::cout << "Enter the number to be deleted: ";
      std::cin >> temp;
      bool success = dll.remove(temp);
      if (success)
      {
        std::cout << "Delete was successful\n";
      }
      else
      {
        std::cout << "Delete failed. Number was not found in the list\n";
      }
    }
    else if (userInput == 3) //Find smallest number
    {
      std::cout << "Smallest number: " << dll.smallest() << '\n';
    }
    else if (userInput == 4) //Find largest number
    {
      std::cout << "Largest number: " << dll.largest() << '\n';
    }
    else if (userInput == 5) //Average
    {
      std::cout << "List average: " << dll.average() << '\n';
    }
    else if (userInput == 6) //Merge 2 lists
    {
      std::string userList;
      std::cout << "Enter new list to be merged: \n";
      std::cin >> userList;
      dll.merge(userList);
      dll.print();
    }
    else if (userInput == 7) //Print
    {
      std::cout << "List: ";
      dll.print();
      std::cout << '\n';
    }
    else if (userInput == 8) //Reverse list
    {
      dll.reverseList();
      dll.print();
    }
    else if (userInput == 9) //Exit
    {
      std::cout << "Exiting\n";
    }
    else //Invalid input
    {
      std::cout << "Please enter a valid menu option\n";
    }
  }
}