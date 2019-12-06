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
    chooseType(fileName);
  }
  else
  {
    throw std::runtime_error("ERROR: Could not open file");
  }
}

Executive::~Executive()
{
}

void Executive::chooseType(std::string fileName)
{
  int userInput = 0;
  while (userInput != 3)
  {
    std::cout << "Please choose the data structure you'd like to construct:\n";
    std::cout << "1- Disjoint Set\n2- Graph\n3- Exit\n>";
    std::cin >> userInput;

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

    if (userInput == 1) //Disjoint Set
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
        throw std::runtime_error("Could not open file");
      }
    }
    else if (userInput == 2) // Graph
    {
      //Construct 2D array for passing
      std::ifstream inFile;
      inFile.open(fileName);
      if (inFile.is_open())
      {
        int size = 0;
        inFile >> size;
        int **array = new int *[size];
        for (int i = 0; i < size; i++)
        {
          array[i] = new int[size];
        }
        for (int i = 0; i < size; i++)
        {
          for (int j = 0; j < size; j++)
          {
            inFile >> array[i][j];
          }
        }
        graph.buildGraph(size, array);
        graphInterface();
      }
      else
      {
        throw std::runtime_error("Could not open file");
      }
    }
    else if (userInput == 3) // Exit
    {
      std::cout << "Exiting...\n";
    }
    else
    {
      std::cout << "Please enter a valid menu option\n";
    }
    std::cout << "------------------------------------------------------\n";
  }
}

void Executive::graphInterface()
{
  int userInput = 0;
  while (userInput != 5)
  {
    std::cout << "Please choose one of the following commands:\n";
    std::cout << "1- BFS\n2- DFS\n3- Kruskal MST\n4- Prim MST\n5- Exit\n>";
    std::cin >> userInput;
    if (userInput == 1) //BFS
    {
      graph.BFS();
    }
    else if (userInput == 2) //DFS
    {
      graph.DFS();
    }
    else if (userInput == 3) //Kruskal
    {

    }
    else if (userInput == 4) //Prim
    {

    }
    else if (userInput == 5) //Exit
    {
      std::cout << "Exiting.......\n";
    }
    else if (userInput == 6) //Print (debugging)
    {
      graph.printGraph();
    }
    else
    {
      std::cout << "Please enter a valid menu option\n";
    }
    std::cout << "------------------------------------------------------\n";
  }
  graph.printGraph();
}

void Executive::userInterface()
{
  int userInput = 0;
  bool setBuilt = false;
  while (userInput != 6)
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
      int temp;
      std::cout << "Enter the element you want to find:\n>";
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
      set.find_timer(temp);
    }
    else if (userInput == 4) //Path_Compression
    {
      int temp;
      std::cout << "Enter the element on whose set you want to perform path compression:\n>";
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
      set.pathCompress(temp);
      std::cout << "Path compression has been done successfully";
    }
    else if (userInput == 5) //Exit
    {
      std::cout << "Exiting...\n";
    }
    else if (userInput == 6) // experiment
    {
      set.runExperiment();
    }
    else //Invalid input
    {
      std::cout << "Please enter a valid menu option\n";
    }
    std::cout << "------------------------------------------------------\n";
  }
}
