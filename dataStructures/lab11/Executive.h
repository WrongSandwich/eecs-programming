/*******************************************************************************
*@author  Evan Trout
*@file    Executive.h
*@date    10/24/19
*@brief   Header file for Executive class, which creates and modifies a
*         MinMaxHeap
*******************************************************************************/


#ifndef EXECUTIVE
#define EXECUTIVE

#include <string>
#include "DisjointSet.h"
#include "Graph.h"

class Executive
{
private:
  DisjointSet set;
  Graph graph;
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

  void chooseType(std::string fileName);

  void graphInterface();

/**
* @pre Executive constructor finishes successfully and calls userInterface
* @post Runs the user interface and interacts with HashTable based on user input
**/
  void userInterface();

};
#endif
