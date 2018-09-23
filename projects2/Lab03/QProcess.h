/*******************************************************************************
*@author  Evan Trout
*@file    QProcess.h
*@date    09/21/2018
*@brief   Header file for the QProcess class. Used by Queue class to create a
*         process and its associated stack of functions.
*******************************************************************************/

#ifndef QPROCESS_H
#define QPROCESS_H

#include "Stack.h"

//Note: using this as a template class but this will only be used for strings
template<class ItemType>
class QProcess
{
private:
  Stack<ItemType> processStack;
  ItemType processName;
public:
  QProcess();
  QProcess(ItemType& name);
  bool isEmpty() const;
  void push(const ItemType& functionName);
  void pop();
  ItemType peek() const;
  ItemType getName() const;
};

#include "QProcess.cpp"
#endif
