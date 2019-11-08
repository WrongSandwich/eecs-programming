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
    inFile.close();
    skew.buildHeap(fileName);
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
    std::cout << "1- Insert\n2- Merge\n3- Delete\n4- Find\n";
    std::cout << "5- Preorder\n6- Inorder\n7- Postorder\n";
    std::cout << "8- Levelorder\n9- Exit\n>";
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
      std::cout << "Enter an integer value to be inserted into the min-skew heap:\n>";
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

      if (skew.insert(temp))
      {
        std::cout << temp << " has been inserted successfully!\n";
        if (skew.isSwapped())
        {
          std::cout << "Subtrees have been swapped. The new level order traversal is:\n";
          skew.levelorder();
          std::cout << "\n";
        }
      }
      else
      {
        std::cout << "Failed to insert value " << temp << "\n";
      }
    }
    else if (userInput == 2) //Merge
    {
      int temp1, temp2, temp3;
      std::cout << "Enter the three elements for the tree H2:\n";
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
      std::cin >> temp3;
      while (std::cin.fail())
      {
        std::cin.clear(); // unset failbit
        // skip bad input up to the next newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be an int. Try again: ";
        std::cin >> temp3;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      bool success = skew.showMerge(temp1, temp2, temp3);
      if (success)
      {
        std::cout << "Trees H1 and H2 have been merged to form new tree H3. The new level order traversal for tree H3 is:\n";
        skew.levelorder();
        std::cout << "\n";
      }
      else
      {
        std::cout << "Merge was unsuccessful. Make sure none of your elements are already present in the tree.\n";
      }
    }
    else if (userInput == 3) //Delete
    {
      int temp;
      std::cout << "Enter the element to be deleted:\n>";
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

      if (skew.remove(temp))
      {
        std::cout << "The element " << temp << " was successfully deleted from the min-skew heap\n";
      }
      else
      {
        std::cout << "Failed to delete the element " << temp << " from the min-skew heap\n";
      }
    }
    else if (userInput == 4) //Find
    {
      int temp;
      std::cout << "Enter the element to search for:\n>";
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

      if (skew.isPresent(temp))
      {
        std::cout << "The element " << temp << " has been found in the min-skew heap\n";
      }
      else
      {
        std::cout << "Failed to find the element " << temp << " in the min-skew heap\n";
      }
    }
    else if (userInput == 5) //Preorder
    {
      skew.preorder();
      std::cout << "\n";
    }
    else if (userInput == 6) //Inorder
    {
      skew.inorder();
      std::cout << "\n";
    }
    else if (userInput == 7) //Postorder
    {
      skew.postorder();
      std::cout << "\n";
    }
    else if (userInput == 8) //Levelorder
    {
      skew.levelorder();
      std::cout << "\n";
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
