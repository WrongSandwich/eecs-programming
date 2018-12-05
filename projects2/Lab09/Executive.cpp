#include "Executive.h"
#include "BinarySearchTree.h"
#include <string>
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

Executive::treeMaker()
{
  execTime++;
  pos++;
  if (pos < dataLength)
  {
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
      Task newTask = new Task(ID, name, estimatedTime, execTime);
      bool addAttempt;
      addAttempt = taskTree.add(newTask);
      if (addAttempt == false)
      {
        //THROW SOME KIND OF ERROR
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
        taskTree.getEntry(ID).printStats();
        std::cout << "Time removed: " << execTime << '\n';
        taskTree.remove(ID);
      }
      //else throw some sort of error
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
          std::cout << "Task " << ID << " has not yet started\n";
        }
        else
        {
          std::cout << "Task " << ID << " has started\n";
        }
      }
      else
      {
        std::cout << "Task " << ID << " has not been added\n";
      }
    }
    else if (inputData[pos] == "start")
    {
      //Locate and start task, then print its statistics
      //Report error if not found or already started
      int ID;
      pos++;
      ID = std::stoi(inputData[pos]);
      if (taskTree.contains(ID))
      {
        if (!taskTree.getEntry(ID).hasStarted())
        {
          taskTree.getEntry(ID).startTask(execTime);
          std::cout << "Task " << ID << "was successfully started\n";
          taskTree.getEntry(ID).printStats();
        }
        //else report an error
      }
      //else report an error
    }
    else if (inputData[pos] == "taskPresent")
    {
      //If task is present, print its statistics, if not print a message
      int ID;
      pos++;
      ID = std::stoi(inputData[pos]);
      if (taskTree.contains(ID))
      {
        taskTree.getEntry(ID).printStats();
      }
      else
      {
        std::cout << "Task " << ID << "has not been added\n";
      }
    }
    else if (inputData[pos] == "height")
    {
      std::cout << "Current tree height: " << taskTree.getHeight() << '\n';
    }
    else if (inputData[pos] == "numberNodes")
    {
      std::cout << "Current tree node count: " << taskTree.getNumberOfNodes() << '\n';
    }
    else if (inputData[pos] == "flush")
    {
      //Postorder traverse and either start task if not started
      //Or finish it if it has been started
      taskTree.postorderTraverse(flush);
    }
  }
}

static void flush(Task& target)
{
  if (target.hasStarted())
  {
    //HOW THE FUCK DO I DO THIS
  }
  else
  {
    target.startTask(execTime);
  }
}
