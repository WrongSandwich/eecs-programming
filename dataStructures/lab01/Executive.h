/*******************************************************************************
*@author  Evan Trout
*@file    Executive.h
*@date    08/30/19
*@brief   Header file for Executive class, which creates and modifies a
*         DoublyLinkedList based on user input
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
* @post constructs an instance of Executive and populates dll with data, then calls userInterface
* @param fileName: fileName to be opened that contains the data
**/
  Executive(std::string fileName);

  /**
* @pre instance of Executive class is deallocated
* @post frees all memory associated with the Executive instance
**/
  ~Executive();

/**
* @pre Executive constructor finishes successfully and calls userInterface
* @post Runs the user interface and interacts with dll based on user input
**/
  void userInterface();
};
#endif
