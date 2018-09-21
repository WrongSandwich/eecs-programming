/*******************************************************************************
*@author  Evan Trout
*@file    QProcess.cpp
*@date    09/21/2018
*@brief   Implementation file for the QProcess class. Used by Queue class to
*         create a process and its associated stack of functions.
*******************************************************************************/

#include "Stack.h"
#include "QProcess.h"

template<class ItemType>
QProcess<ItemType>::QProcess()
{}

template<class ItemType>
QProcess<ItemType>::QProcess(ItemType& name) : processName(name)
{}

template<class ItemType>
bool QProcess<ItemType>::isEmpty() const
{
  return processStack.isEmpty();
}

template<class ItemType>
void QProcess<ItemType>::push(const ItemType& functionName)
{
  processStack.push(functionName);
}

template<class ItemType>
void QProcess<ItemType>::pop()
{
  processStack.pop();
}

template<class ItemType>
ItemType QProcess<ItemType>::peek() const
{
  return processStack.peek();
}

template<class ItemType>
ItemType QProcess<ItemType>::getName() const
{
  return processName;
}
