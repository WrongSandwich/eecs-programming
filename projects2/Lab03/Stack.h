/*******************************************************************************
*@author  Evan Trout
*@file    Stack.h
*@date    09/20/2018
*@brief   Header file for the Stack class. Creates and maintains a call stack
*         for functions from the queue class. Derived from StackInterface.
*******************************************************************************/

#ifndef STACK_H
#define STACK_H

#include "StackInterface.h"
#include "PrecondViolationExcep.h"
#include "Node.h"


template<class ItemType>
class Stack : public StackInterface<ItemType>
{
private:
  Node<ItemType>* topPtr;
public:
  Stack();
  Stack(const Stack<ItemType>& aStack);
  ~Stack();

  /** Sees whether this stack is empty.
   @return True if the stack is empty, or false if not. */

  bool isEmpty() const;

  /** Adds a new entry to the top of this stack.
   @post If the operation was successful, newEntry is at the top of the stack.
   @param newEntry The object to be added as a new entry.
   @throw PrecondViolationExcep if stack size would be over 100 */

  void push(const ItemType& newEntry) throw (PrecondViolationExcep);

 /** Removes the top of this stack.
 @pre The stack is not empty.
   @post If the operation was successful, the top of the stack has been removed.
   @throw PrecondViolationExcep if the stack is empty when called */

  void pop() throw (PrecondViolationExcep);

  /** Returns the top of this stack.
   @pre The stack is not empty.
   @post The top of the stack has been returned, and the stack is unchanged.
   @return The top of the stack.
   @throw PrecondViolationExcep if the stack is empty when called */

  ItemType peek() const throw (PrecondViolationExcep);
};

#include "Stack.cpp"
#endif
