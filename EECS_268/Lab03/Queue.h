/*******************************************************************************
*@author  Evan Trout
*@file    Queue.h
*@date    09/20/2018
*@brief   Header file for the Queue class. Creates and maintains a process queue
*         for functions from the executive class. Derived from QueueInterface.
*******************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include "QueueInterface.h"
#include "LinkedList.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class Queue : public QueueInterface
{
private:
  LinkedList<std::string> llQueue;
public:
   ~QueueInterface();
   /** Sees whether this queue is empty.
    @return True if the queue is empty, or false if not. */

   bool isEmpty() const;

   /** Adds a new entry to the back of this queue.
    @post If the operation was successful, newEntry is at the back of the queue.
    @param newEntry  The object to be added as a new entry.
    @throw PrecondViolatedExcep if no memory available for the new item */

   void enqueue(const ItemType& newEntry) throw (PrecondViolatedExcep);

   /** Removes the front of this queue.
    @post If the operation was successful, the front of the queue has been removed.
    @throw PrecondViolatedExcep if the queue is empty when called */

   void dequeue() throw (PrecondViolatedExcep);

   /** Returns the front of this queue.
    @pre The queue is not empty.
    @post The front of the queue has been returned, and the queue is unchanged.
    @throw PrecondViolatedExcep if the queue is empty when called */

   ItemType peekFront() const throw (PrecondViolatedExcep);
};

#include "Queue.cpp"
#endif