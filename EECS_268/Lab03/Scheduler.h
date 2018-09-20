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
  Queue processQueue;
  std::string* commArray;
  int size;
public:
  Scheduler(std::string fileName);
  void run();
}
