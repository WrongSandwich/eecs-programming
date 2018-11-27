/*******************************************************************************
*@author  Evan Trout
*@file    Task.cpp
*@date    11/27/18
*@brief   Implementation file for Task class, which is used to store an individual
*         task's multiple variable values for use in a BinarySearchTree.
*******************************************************************************/

#include <iostream>
#include "Task.h"
#include <string>

Task::Task(int newID, std::string newName, int newEstimate, int currentTime)
{
  taskID = newID;
  taskName = newName;
  estimatedTimeToComplete = newEstimate;
  timeAddedToBST = currentTime;
  timeStarted = -1;
}

void Task::printStats()
{
  if (timeStarted == -1)
  {
    std::cout << "Task ID: " << taskID << '\n';
    std::cout << "Task Name: " << taskName << '\n';
    std::cout << "Time added to tree: " << timeAddedToBST << '\n';
    std::cout << "Task has not yet started\n";
  }
  else
  {
    std::cout << "Task ID: " << taskID << '\n';
    std::cout << "Task Name: " << taskName << '\n';
    std::cout << "Time added to tree: " << timeAddedToBST << '\n';
    std::cout << "Time started: " << timeStarted << '\n';
    std::cout << "Estimated time to completion: " << estimatedTimeToComplete << '\n';
  }
}

int Task::getID()
{
  return taskID;
}

void Task::startTask(int currentTime)
{
  timeStarted = currentTime;
}
