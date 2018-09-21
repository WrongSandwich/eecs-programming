/*******************************************************************************
*@author  Evan Trout
*@file    Queue.cpp
*@date    09/20/2018
*@brief   Implementation file for the Queue class. Creates and maintains a
*         process queuefor functions from the executive class. Derived from
*         QueueInterface.
*******************************************************************************/

#include <iostream>
#include <string>

#include "LinkedList.h"
#include "QProcess.h"
#include "QueueInterface.h"

template<class ItemType>
Queue<ItemType>::~Queue()
{

}


template<class ItemType>
bool Queue<ItemType>::isEmpty() const
{
  return llQueue.isEmpty();
}

//Adds a new entry to back of queue
template<class ItemType>
void Queue<ItemType>::enqueue(const ItemType& newEntry) throw (PrecondViolationExcep)
{
  if (llQueue.getLength() < 100)
  {
    int newPosition = llQueue.getLength() + 1;
    llQueue.insert(newPosition, newEntry);
  }
  else throw PrecondViolationExcep("Queue is full");
}

//Removes the front of the queue
template<class ItemType>
void Queue<ItemType>::dequeue() throw (PrecondViolationExcep)
{
  if (llQueue.isEmpty() == false)
  {
    llQueue.remove(1);
  }
  else throw PrecondViolationExcep("Queue is empty");
}

//Returns the front of the queue if not empty
template<class ItemType>
ItemType Queue<ItemType>::peekFront() const throw (PrecondViolationExcep)
{
  if (llQueue.isEmpty() == false)
  {
    return llQueue.getEntry(1);
  }
  else throw PrecondViolationExcep("Queue is empty");
}
