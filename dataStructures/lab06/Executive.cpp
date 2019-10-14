/*******************************************************************************
*@author  Evan Trout
*@file    Executive.cpp
*@date    09/25/19
*@brief   Implementation file for Executive class, which creates and modifies a
*         MinHeap and MaxHeap
*******************************************************************************/

#include "Executive.h"
#include "MinHeap.h"
#include <string>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <fstream>
#include <iostream>

Executive::Executive(std::string fileName)
{
  //TODO: Update infiling
  std::ifstream inFile;
  inFile.open(fileName);
  if (inFile.is_open())
  {
    char temp;
    while (inFile >> temp)
    {
      bool success = tree.addItem(temp);
      if (!success)
      {
        throw std::runtime_error("ERROR: Invalid item in data file, please fix and run again");
      }
    }
    inFile.close();
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
  while (userInput != 9)
  {
    std::cout << "Please choose one of the following commands:\n";
    std::cout << "1- Insert\n2- Delete\n3- PQ_Highest\n4- PQ_Lowest\n";
    std::cout << "5- Level_Order\n6- Time_Delete\n7- Time_HighestPQ\n";
    std::cout << "8- Time_LowestPQ\n9- Exit\n>";
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

      if (minHeap.insert(temp))
      {
        std::cout << temp << "has been inserted successfully!\n\n";
      }
      else
      {
        std::cout << "Failed to insert value " << temp << "\n\n";
      }
    }
    else if (userInput == 2) //Delete
    {
      int temp = minHeap.remove();
      if (temp == -1)
      {
        std::cout << "ERROR: Heap is empty, cannot remove\n\n";
      }
      else
      {
        std::cout << "The highest priority element is " << temp << " and it has been deleted\n\n";
      }
    }
    else if (userInput == 3) //PQ_Highest
    {
      int temp = minHeap.pq_highest();
      if (temp == -1)
      {
        std::cout << "ERROR: Heap is empty\n\n";
      }
      else
      {
        std::cout << "The highest priority element is " << temp << "\n\n";
      }
    }
    else if (userInput == 4) //PQ_Lowest
    {
      int temp = minHeap.pq_lowest();
      if (temp == -1)
      {
        std::cout << "ERROR: Heap is empty\n\n";
      }
      else
      {
        std::cout << "The lowest priority element is " << temp << "\n\n";
      }
    }
    else if (userInput == 5) //Level_Order
    {
      minHeap.levelorder();
      std::cout << "\n\n";
    }
    else if (userInput == 6) //Time_Delete
    {
      int temp = minHeap.time_delete_pq();
      if (temp == -1)
      {
        std::cout << "ERROR: Heap is empty, cannot remove\n\n";
      }
      else
      {
        std::cout << "The highest priority element is " << temp << " and it has been deleted\n\n";
      }
    }
    else if (userInput == 7) //Time_HighestPQ
    {
      int temp = minHeap.time_highest_pq();
      if (temp == -1)
      {
        std::cout << "ERROR: Heap is empty\n\n";
      }
      else
      {
        std::cout << "The highest priority element is " << temp << "\n\n";
      }
    }
    else if (userInput == 8) //Time_LowestPQ
    {
      int temp = minHeap.time_lowest_pq();
      if (temp == -1)
      {
        std::cout << "ERROR: Heap is empty\n\n";
      }
      else
      {
        std::cout << "The lowest priority element is " << temp << "\n\n";
      }
    }
    else if (userInput == 9) //Exit
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
