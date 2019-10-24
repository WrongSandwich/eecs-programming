/*******************************************************************************
*@author  Evan Trout
*@file    Executive.h
*@date    09/25/19
*@brief   Header file for Executive class, which creates and modifies a
*         MinHeap and MaxHeap
*******************************************************************************/


#ifndef EXECUTIVE
#define EXECUTIVE

#include <string>
#include "MinHeap.h"
#include "MaxHeap.h"

class Executive
{
private:
  MinHeap minHeap;
  MaxHeap maxHeap;
public:
  /**
* @pre constructor is called with valid file name
* @post constructs an instance of Executive and calls HashTable constructor with data, then calls userInterface
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
* @post Runs the user interface and interacts with HashTable based on user input
**/
  void userInterface();
};
#endif
