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
#include "PrecondViolationExcep.h"
#include "QProcess.h"

template<class ItemType>
class Queue : public QueueInterface<ItemType>
{
private:
  LinkedList<QProcess<std::string>> llQueue;
public:
  //Default constructor
  Queue();

  ~Queue();
  /** Sees whether this queue is empty.
  @return True if the queue is empty, or false if not. */

  bool isEmpty() const;

  /** Adds a new entry to the back of this queue.
  @post If the operation was successful, newEntry is at the back of the queue.
  @param newEntry  The object to be added as a new entry.
  @throw PrecondViolationExcep if no memory available for the new item */

  void enqueue(const ItemType& newEntry) throw (PrecondViolationExcep);

  /** Removes the front of this queue.
  @post If the operation was successful, the front of the queue has been removed.
  @throw PrecondViolationExcep if the queue is empty when called */

  void dequeue() throw (PrecondViolationExcep);

  /** Returns the front of this queue.
  @pre The queue is not empty.
  @post The front of the queue has been returned, and the queue is unchanged.
  @throw PrecondViolationExcep if the queue is empty when called */

  ItemType peekFront() const throw (PrecondViolationExcep);

  /** Combines Stack.push, enqueue, and dequeue into a single function to make
  *   my job easier
  *   @param functionName: Name of the function that will be pushed
  *   @post functionName is pushed to the relevant stack, and the process with
  *         that stack is moved to the back of the queue
  */
  void backOfTheLine(std::string functionName) throw (PrecondViolationExcep);

  /** Returns the name of the process at the front of the queue
  * @pre the queue is not empty.
  * @return the name of the process at the front of the queue.
  */

  std::string getName() const throw (PrecondViolationExcep);
};

#include "Queue.cpp"
#endif
