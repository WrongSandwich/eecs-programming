/*******************************************************************************
*@author  Evan Trout
*@file    Executive.cpp
*@date    10/29/19
*@brief   Implementation file for Executive class, which creates and modifies a
*         Leftist Heap
*******************************************************************************/

#include "Executive.h"
#include "LeftistHeap.h"
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
    lheap.buildHeap(fileName);
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
    std::cout << "1- Insert\n2- Merge\n3- Deletemin\n4- Findmin\n";
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
      std::cout << "Enter an integer value to be inserted into the leftist heap:\n>";
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

      if (lheap.insert(temp))
      {
        std::cout << temp << " has been inserted successfully!\n";
        if (lheap.isSwapped())
        {
          std::cout << "Subtrees have been swapped. The new level order traversal is:\n";
          lheap.levelorder();
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
      bool success = lheap.showMerge(temp1, temp2, temp3);
      if (success)
      {
        std::cout << "Trees H1 and H2 have been merged to form new tree H3. The new level order traversal for tree H3 is:\n";
        lheap.levelorder();
        std::cout << "\n";
      }
      else
      {
        std::cout << "Merge was unsuccessful. Make sure none of your elements are already present in the tree.\n";
      }
    }
    else if (userInput == 3) //Deletemin
    {
      int temp = lheap.deleteMin();
      if (temp == -1)
      {
        std::cout << "Tree is empty; cannot delete an element\n";
      }
      else
      {
        std::cout << "The minimum value " << temp << " has been deleted, and the tree has been rearranged.\n";
        lheap.levelorder();
        std::cout << "\n";
      }   
    }
    else if (userInput == 4) //Findmin
    {
      int temp = lheap.findMin();
      if (temp == -1)
      {
        std::cout << "Tree is empty; cannot find an element\n";
      }
      else
      {
        std::cout << "The minimum element is " << temp << "\n";
      }
    }
    else if (userInput == 5) //Preorder
    {
      lheap.preorder();
      std::cout << "\n";
    }
    else if (userInput == 6) //Inorder
    {
      lheap.inorder();
      std::cout << "\n";
    }
    else if (userInput == 7) //Postorder
    {
      lheap.postorder();
      std::cout << "\n";
    }
    else if (userInput == 8) //Levelorder
    {
      lheap.levelorder();
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
