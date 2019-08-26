/*******************************************************************************
*@author  Evan Trout
*@file    Executive.cpp
*@date    12/06/18
*@brief   Implementation file for Executive class, which stores input commands
*         in an array then uses them to build and modify a binary search tree.
*******************************************************************************/


#include "Executive.h"
#include "BinarySearchTree.h"
#include "NotFoundException.h"
#include "InvalidSetEntryRequest.h"
#include "Task.h"
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>

Executive::Executive(std::string fileName)
{
  



  dataLength = 0;
  pos = -1;
  execTime = 0;
  inputData = nullptr;
  std::string* newArray = nullptr;
  std::ifstream inFile;
  inFile.open(fileName);
  if (inFile.is_open())
  {
    int i = 1;
    newArray = new std::string[i];
    inFile >> newArray[dataLength];
    inputData = newArray;
    i++;
    newArray = nullptr;
    while (!inFile.eof())
    {
      dataLength++;
      newArray = new std::string[i];
      for (int j = 0; j < dataLength; j++)
      {
        newArray[j] = inputData[j];
      }
      inFile >> newArray[dataLength]; //New array is complete
      delete[] inputData;
      inputData = newArray;
      i++;
      newArray = nullptr;
    }
  }
  inFile.close();
  treeMaker();
}

Executive::~Executive()
{
  delete[] inputData;
}

void Executive::treeMaker()
{
  while (pos < (dataLength-1))
  {
    std::cout << "===============\n";
    execTime++;
    pos++;
    if (inputData[pos] == "add")
    {
      //Add a task if it's not already been added to the tree
      std::string name;
      int ID, estimatedTime;
      pos++;
      ID = std::stoi(inputData[pos]);
      pos++;
      name = inputData[pos];
      pos++;
      estimatedTime = std::stoi(inputData[pos]);
      Task newTask(ID, name, estimatedTime, execTime);
      bool addAttempt;
      addAttempt = taskTree.add(newTask);
      if (addAttempt == false)
      {
        std::cout << "Runtime Error: Add attempt failed (task already exists)\n";
      }
      else
      {
        std::cout << "ADD: Task " << ID << " successfully added to tree\n";
      }
    }
    else if (inputData[pos] == "finish")
    {
      //Remove task from BST and report its statistics and time finishing
      //Or throw error if it cannot be found
      int ID;
      pos++;
      ID = std::stoi(inputData[pos]);
      if (taskTree.contains(ID))
      {
        if (taskTree.getEntry(ID).hasStarted())
        {
          std::cout << "FINISH: ";
          taskTree.getEntry(ID).printStats();
          std::cout << "Time removed: " << execTime << '\n';
          taskTree.remove(ID);
        }
        else
        {
          std::cout << "FINISH: Runtime Error: Finish attempt failed (task not yet started)\n";
        }
      }
      else
      {
        std::cout << "FINISH: Not Found Exception: Finish attempt failed (task cannot be found)\n";
      }
    }
    else if (inputData[pos] == "started")
    {
      //Report if task has started or not, and if it is not present.
      int ID;
      pos++;
      ID = std::stoi(inputData[pos]);
      if (taskTree.contains(ID))
      {
        if (!taskTree.getEntry(ID).hasStarted())
        {
          std::cout << "STARTED: Task " << ID << " has not yet started\n";
        }
        else
        {
          std::cout << "STARTED: Task " << ID << " has started\n";
        }
      }
      else
      {
        std::cout << "STARTED: Task " << ID << " has not been added\n";
      }
    }
    else if (inputData[pos] == "start")
    {
      //Locate and start task, then print its statistics
      //Report error if not found or already started
      int ID;
      pos++;
      ID = std::stoi(inputData[pos]);
      std::cout << "START: ";
      if (taskTree.contains(ID))
      {
        if (taskTree.getEntry(ID).hasStarted() == false)
        {
          //taskTree.getEntry(ID).startTask(execTime);
          Task tempTask = taskTree.getEntry(ID);
          tempTask.startTask(execTime);
          taskTree.setEntry(ID, tempTask);
        }
        else
        {
          std::cout << "Runtime Error: Start attempt failed (task already started)\n";
        }
      }
      else
      {
        std::cout << "Not Found Exception: Start attempt failed (task not found)\n";
      }
    }
    else if (inputData[pos] == "taskPresent")
    {
      //If task is present, print its statistics, if not print a message
      int ID;
      pos++;
      ID = std::stoi(inputData[pos]);
      std::cout << "TASK PRESENT: ";
      if (taskTree.contains(ID))
      {
        taskTree.getEntry(ID).printStats();
      }
      else
      {
        std::cout << "Task " << ID << " has not been added\n";
      }
    }
    else if (inputData[pos] == "height")
    {
      std::cout << "HEIGHT: Current tree height: " << taskTree.getHeight() << '\n';
    }
    else if (inputData[pos] == "numberNodes")
    {
      std::cout << "NUMBER OF NODES: Current tree node count: " << taskTree.getNumberOfNodes() << '\n';
    }
    else if (inputData[pos] == "flush")
    {
      //Postorder traverse and either start task if not started
      //Or finish it if it has been started
      //std::cout << "Flushing tree\n";
      //taskTree.postorderTraverse(flush);
      //So I know this has to be postorder but I cannot for the life of me figure
      //out how to write the visit function correctly...
      std::cout << "FLUSH: Warning: I couldn't figure out how to implement flush\n";
      std::cout << "All flushes will be skipped :/\n";
    }
    else
    {
      std::cout << "Input Error: Invalid command call\n";
    }
  }
  std::cout << "===============\n";
}

/*************************
static void flush(Task& target)
{
  if (target.hasStarted())
  {
    target.printStats();
    std::cout << "Time removed: " << execTime << '\n';
    remove(target.getID());
  }
  else
  {
    target.startTask(execTime);
  }
}
*******************/
