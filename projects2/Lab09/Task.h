/*******************************************************************************
*@author  Evan Trout
*@file    Task.h
*@date    11/27/18
*@brief   Header file for Task class, which is used to store an individual
*         task's multiple variable values for use in a BinarySearchTree.
*******************************************************************************/

#ifndef TASK
#define TASK

#include <string>

class Task
{
private:
  int taskID;
  std::string taskName;
  int estimatedTimeToComplete;
  int timeAddedToBST;
  int timeStarted;
public:

  Task();

  /**
  * @pre Constructor is called with valid arguments
  * @post Task is created with given arguments
  * @param newID: an ID to be used for taskID
  * @param newName: a name to be used for taskName
  * @param newEstimate: an int to be used for estimatedTimeToComplete
  * @param currentTime: an int to be used for timeAddedToBST
  **/
  Task(int newID, std::string newName, int newEstimate, int currentTime);

  /**
  * @post Prints formatted stats in one of two ways, dependent on if the task
  *       has been started
  **/
  void printStats();

  /**
  * @return taskID
  **/
  int getID();

  /**
  * @pre Task has not yet started (timeStarted = -1)
  * @post Starts task by setting startTime to currentTime
  * @param currentTime: int that represents the current time
  **/
  void startTask(int currentTime);

  bool hasStarted();

  bool operator==(const int& rightHandSide);

  bool operator>(const int& rightHandSide);

  bool operator<(const int& rightHandSide);
};
#endif
