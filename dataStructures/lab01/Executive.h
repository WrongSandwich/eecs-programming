/*******************************************************************************
*@author  Evan Trout
*@file    Executive.h
*@date    12/06/18
*@brief   Header file for Executive class, which stores input commands
*         in an array then uses them to build and modify a binary search tree.
*******************************************************************************/


#ifndef EXECUTIVE
#define EXECUTIVE

#include <stdexcept>
#include <string>
#include "DoublyLinkedList.h"

class Executive
{
private:
  DoublyLinkedList dll;
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
  void userInterface();
  //static void flush(Task& target);
};
#endif
