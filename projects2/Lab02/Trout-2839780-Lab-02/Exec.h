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
  /**
  * @param file: a string with a valid file name to be opened
  * @post the given file is opened and the commands read and put in commArray
  * @return the constructed Exec, with commands in commArray and a valid size
  */
  Exec(std::string fileName);

  /**
  * @pre the Exec has been created successfully with a valid commArray and size
  * @post Reads and carries out the commands from commArray
  */
  void run();
};

#endif
