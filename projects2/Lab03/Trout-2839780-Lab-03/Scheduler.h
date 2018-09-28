/*******************************************************************************
*@author  Evan Trout
*@file    Scheduler.h
*@date    09/20/2018
*@brief   Header file for the executive class Scheduler. Constructor reads input
*         file into an array of commands, then run() executes them. Modeled
*         after Exec class from Lab02.
*******************************************************************************/

#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <string>
#include "Queue.h"

class Scheduler
{
private:
  std::string fileName;
  Queue<QProcess<std::string>> processQueue;
  std::string* commArray;
  int size;
public:
  /**
  * @param file: a string with a valid file name to be opened
  * @post the given file is opened and the commands read and put in commArray
  * @return the constructed Scheduler, with commands in commArray and a valid size
  */
  Scheduler(std::string fileName);

  /**
  * @pre the Scheduler has been created successfully with a valid commArray and size
  * @post Reads and carries out the commands from commArray
  */
  void run();
};

#endif
