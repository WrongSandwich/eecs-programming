/*******************************************************************************
*@author  Evan Trout
*@file    Exec.h
*@date    09/19/2018
*@brief   Header file for the executive class. Constructor reads input file into
*         an array of commands, then run() executes them.
*******************************************************************************/

#ifndef EXEC_H
#define EXEC_H
#include <string>
#include "WebBrowser.h"

class Exec
{
private:
  std::string fileName;
  WebBrowser wb;
  std::string* commArray;
  int size;
public:
  Exec(std::string fileName);
  void run();
};

#endif
