/*******************************************************************************
*@author  Evan Trout
*@file    QProcess.h
*@date    09/21/2018
*@brief   Header file for the QProcess class. Used by Queue class to create a
*         process and its associated stack of functions.
*******************************************************************************/

#ifndef QPROCESS_H
#define QPROCESS_H

class QProcess
{
private:
  Stack processStack;
  std::string processName;
public:

};

#include "QProcess.cpp"
#endif
