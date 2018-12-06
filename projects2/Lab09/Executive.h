/*******************************************************************************
*@author  Evan Trout
*@file    Executive.h
*@date    12/06/18
*@brief   Header file for Executive class, which stores input commands
*         in an array then uses them to build and modify a binary search tree.
*******************************************************************************/


#ifndef EXECUTIVE
#define EXECUTIVE

#include "Task.h"
#include "BinarySearchTree.h"
#include <stdexcept>
#include "NotFoundException.h"
#include "InvalidSetEntryRequest.h"
#include <string>

class Executive
{
private:
  std::string* inputData;
  int dataLength;
  int pos;
  int execTime;
  BinarySearchTree<int, Task> taskTree;
public:
  /**
* @pre constructor is called with valid file name
* @post constructs an instance of Executive and populates inputData with the
*       contents of fileName, then calls treeMaker
* @param fileName: fileName to be opened that contains the commands
**/
  Executive(std::string fileName);

  /**
* @pre instance of Executive class is deallocated
* @post frees all memory associated with the Executive instance
**/
  ~Executive();

  /**
* @pre Executive constructor finishes successfully and calls treeMaker
* @post reads the commands from inputData and  calls the appropriate commands on
        taskTree
**/
  void treeMaker();
  //static void flush(Task& target);
};
#endif
