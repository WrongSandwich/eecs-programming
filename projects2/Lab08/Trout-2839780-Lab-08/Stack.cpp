/*******************************************************************************
*@author  Evan Trout
*@file    Stack.cpp
*@date    09/20/2018
*@brief   Implementation file for the Stack class. Creates and maintains a call
*         stack for functions in a QProcess. Derived from StackInterface.
*******************************************************************************/

#include <iostream>
#include <string>

#include "PrecondViolationExcep.h"
#include "StackInterface.h"

template<class ItemType>
Stack<ItemType>::Stack() : topPtr(nullptr)
{}

template<class ItemType>
Stack<ItemType>::Stack(const Stack<ItemType>& aStack)
{
  Node<ItemType>* origChainPtr = aStack.topPtr;
  if (origChainPtr == nullptr)
  {
    topPtr = nullptr;
  }
  else
  {
    topPtr = new Node<ItemType>();
    topPtr->setItem(origChainPtr->getItem());
    //Point to first node in new chain
    Node<ItemType>* newChainPtr = topPtr;
    //Advance original chain ptr
    origChainPtr = origChainPtr->getNext();
    //Copy remaining nodes
    while (origChainPtr != nullptr)
    {
      //get next item from original chain
      ItemType nextItem = origChainPtr->getItem();
      //Create a new node containing the next item
      Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
      //Link new node to end of new chain
      newChainPtr->setNext(newNodePtr);
      //Advance pointer to new last node
      newChainPtr = newChainPtr->getNext();
      //Advance original chain pointer
      origChainPtr = origChainPtr->getNext();
    }
    newChainPtr->setNext(nullptr);
  }
}

template<class ItemType>
Stack<ItemType>::~Stack()
{
  while (!isEmpty())
    pop();
}

template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
  return topPtr == nullptr;
}

//Adds entry to top of stack
//Do not need to throw PrecondViolationExcep because I used link implementation,
//cannot become too large to add more items
template<class ItemType>
void Stack<ItemType>::push(const ItemType& newEntry)
{
  Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry, topPtr);
  topPtr = newNodePtr;
  newNodePtr = nullptr;
}

//Removes the top of the stack if it's not empty
template<class ItemType>
void Stack<ItemType>::pop() throw (PrecondViolationExcep)
{
  if (!isEmpty())
  {
    Node<ItemType>* nodeToDeletePtr = topPtr;
    topPtr = topPtr->getNext();
    nodeToDeletePtr->setNext(nullptr);
    delete nodeToDeletePtr;
    nodeToDeletePtr = nullptr;
  }
  else throw PrecondViolationExcep ("Stack is empty");
}

//Returns the top of the stack if it's not empty.
template<class ItemType>
ItemType Stack<ItemType>::peek() const throw (PrecondViolationExcep)
{
  if (!isEmpty())
  {
    return topPtr->getItem();
  }
  else throw PrecondViolationExcep ("Stack is empty");
}
