/*******************************************************************************
*@author  Evan Trout
*@file    Executive.cpp
*@date    09/25/19
*@brief   Implementation file for Executive class, which creates and modifies a
*         BinarySearchTree
*******************************************************************************/

#include "Executive.h"
#include <string>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <fstream>
#include <iostream>
#include "BinarySearchTree.h"

Executive::Executive(std::string fileName)
{
  std::ifstream inFile;
  inFile.open(fileName);
  if (inFile.is_open())
  {
    int temp;
    while (inFile >> temp)
    {
      if (!tree.addItem(temp))
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
  while (userInput != 11)
  {
    std::cout << "Please choose one of the following commands:\n";
    std::cout << "1- Is tree full?\n2- Add item\n3- Delete\n4- Check if leaf\n";
    std::cout << "5- Print leaves\n6- Print tree height\n7- Preorder\n";
    std::cout << "8- Postorder\n9- Inorder\n10- Levelorder\n11- Exit\n>";
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

    if (userInput == 1) //IsFull
    {
      if (tree.isFull())
      {
        std::cout << "True\n\n";
      }
      else
      {
        std::cout << "False\n\n";
      }
    }
    else if (userInput == 2) //AddItem
    {
      int temp;
      std::cout << "Please enter the value which you want to enter into the tree:\n>";
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

      if (tree.addItem(temp))
      {
        std::cout << "Value inserted successfully!\n\n";
      }
      else
      {
        std::cout << "Failed to insert value\n\n";
      }
    }
    else if (userInput == 3) //Delete
    {
      int pop = tree.remove();
      std::cout << "The last value is " << pop << ", and it has been deleted\n\n";
    }
    else if (userInput == 4) //Leaf
    {
      int temp;
      std::cout << "Please enter the value which you want to test as a leaf node:\n>";
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

      if (tree.leaf(temp))
      {
        std::cout << "The node with value " << temp << " is a leaf node\n\n";
      }
      else
      {
        std::cout << "The node with value " << temp << " is not a leaf node\n\n";
      }
    }
    else if (userInput == 5) //PrintLeaf
    {
      std::cout << "The leaf nodes are: ";
      tree.printLeaf();
      std::cout << "\n\n";
    }
    else if (userInput == 6) //PrintTreeHeight
    {
      std::cout << "The height of the tree is ";
      tree.printTreeHeight();
      std::cout << "\n\n";
    }
    else if (userInput == 7) //Preorder
    {
      std::cout << "Printing the tree in preorder: ";
      tree.preorder();
      std::cout << "\n\n";
    }
    else if (userInput == 8) //Postorder
    {
      std::cout << "Printing the tree in postorder: ";
      tree.postorder();
      std::cout << "\n\n";
    }
    else if (userInput == 9) //Inorder
    {
      std::cout << "Printing the tree in inorder: ";
      tree.inorder();
      std::cout << "\n\n";
    }
    else if (userInput == 10) //Levelorder
    {
      std::cout << "Printing the tree in levelorder: ";
      tree.levelorder();
      std::cout << "\n\n";
    }
    else if (userInput == 11) //Exit
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
