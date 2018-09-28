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
  /** Default constructor
  * @post Creates a QProcess and initializes its processStack
  */
  QProcess();

  /** Parametrized constructor with a process name
  * @post Creates a QProcess and sets processName to be the given name
  * @param name: An item of some class (in this case string) to become processName
  */
  QProcess(ItemType& name);

  /** Runs the stack's isEmpty function
  * @post Runs processStack.isEmpty() and returns the result
  * @return the result of processStack.isEmpty()
  */
  bool isEmpty() const;

  /** Runs the stack's push function with a given function name
  * @post Runs processStack.push with the given function name
  * @param functionName: the name of the function the client wants to push
  */
  void push(const ItemType& functionName);

  /** Runs the stack's pop function
  * @post Runs processStack.pop() function
  */
  void pop();

  /** Runs the stack's peek function and returns the result
  * @post Runs processStack.peek() and returns the resulting function name
  * @return The functionName returned by processStack.peek()
  */
  ItemType peek() const;

  /** Returns processName
  * @post Returns processName
  * @return processName
  */
  ItemType getName() const;
};

#include "QProcess.cpp"
#endif
