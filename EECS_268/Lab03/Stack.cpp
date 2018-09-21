/*******************************************************************************
*@author  Evan Trout
*@file    Stack.cpp
*@date    09/20/2018
*@brief   Implementation file for the Stack class. Creates and maintains a call
*         stack for functions from the queue class. Derived from StackInterface.
*******************************************************************************/

#include <iostream>
#include <string>

#include "PrecondViolationExcep.h"
#include "LinkedList.h"
#include "StackInterface.h"

template<class ItemType>
Stack<ItemType>::Stack()
{}

template<class ItemType>
Stack<ItemType>::~Stack()
{

}

template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
  return llStack.isEmpty();
}

//Adds entry to top of stack
template<class ItemType>
void Stack<ItemType>::push(const ItemType& newEntry) throw (PrecondViolationExcep)
{
  if (llStack.getLength () < 100)
  {
    llStack.insert(1, newEntry);
  }
  else throw PrecondViolationExcep ("Stack is full");
}

//Removes the top of the stack if it's not empty
template<class ItemType>
void Stack<ItemType>::pop() throw (PrecondViolationExcep)
{
  if (llStack.isEmpty() == false)
  {
    llStack.remove(1);
  }
  else throw PrecondViolationExcep ("Stack is empty");
}

//Returns the top of the stack if it's not empty.
template<class ItemType>
ItemType Stack<ItemType>::peek() const throw (PrecondViolationExcep)
{
  if (llStack.isEmpty() == false)
  {
    return llStack.getEntry(1);
  }
  else throw PrecondViolationExcep ("Stack is empty");
}
