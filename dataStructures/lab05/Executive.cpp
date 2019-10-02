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
  while (userInput != 11)
  {
    std::cout << "Please choose one of the following commands:\n";
    std::cout << "1- Add item\n2- Delete\n3- Check if leaf\n4- Print leaves\n";
    std::cout << "5- Print tree height\n6- Preorder\n7- Postorder\n";
    std::cout << "8- Inorder\n9- Levelorder\n10- Search for an item\n11- Exit\n>";
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

    if (userInput == 1) //AddItem
    {
      char temp;
      std::cout << "Please enter the character which you want to enter into the tree:\n>";
      std::cin >> temp;

      while (std::cin.fail())
      {
        std::cin.clear(); // unset failbit
        // skip bad input up to the next newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be an char. Try again: ";
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
    else if (userInput == 2) //Delete
    {
      char temp;
      std::cout << "Please enter the character which you want to delete from the tree:\n>";
      std::cin >> temp;

      while (std::cin.fail())
      {
        std::cin.clear(); // unset failbit
        // skip bad input up to the next newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be an char. Try again: ";
        std::cin >> userInput;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      if (tree.remove(temp))
      {
        std::cout << "Value deleted successfully!\n\n";
      }
      else
      {
        std::cout << "Failed to delete value. The character is not present in the tree\n\n";
      }
    }
    else if (userInput == 3) //Leaf
    {
      char temp;
      std::cout << "Please enter the value which you want to test as a leaf node:\n>";
      std::cin >> temp;

      while (std::cin.fail())
      {
        std::cin.clear(); // unset failbit
        // skip bad input up to the next newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be a char. Try again: ";
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
    else if (userInput == 4) //PrintLeaf
    {
      std::cout << "The leaf nodes are: ";
      tree.printLeaf();
      std::cout << "\n\n";
    }
    else if (userInput == 5) //PrintTreeHeight
    {
      std::cout << "The height of the tree is ";
      tree.printTreeHeight();
      std::cout << "\n\n";
    }
    else if (userInput == 6) //Preorder
    {
      std::cout << "Printing the tree in preorder: ";
      tree.preorder();
      std::cout << "\n\n";
    }
    else if (userInput == 7) //Postorder
    {
      std::cout << "Printing the tree in postorder: ";
      tree.postorder();
      std::cout << "\n\n";
    }
    else if (userInput == 8) //Inorder
    {
      std::cout << "Printing the tree in inorder: ";
      tree.inorder();
      std::cout << "\n\n";
    }
    else if (userInput == 9) //Levelorder
    {
      std::cout << "Printing the tree in levelorder: ";
      tree.levelorder();
      std::cout << "\n\n";
    }
    else if (userInput == 10) //Search item
    {
      char temp;
      std::cout << "Please enter the character which you want to search for:\n>";
      std::cin >> temp;

      while (std::cin.fail())
      {
        std::cin.clear(); // unset failbit
        // skip bad input up to the next newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Sorry, your input did not seem to be an char. Try again: ";
        std::cin >> userInput;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      if (tree.searchElement(temp))
      {
        std::cout << temp << " has been found in the tree\n\n";
      }
      else
      {
        std::cout << temp << " could not be found in the tree\n\n";
      }
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
