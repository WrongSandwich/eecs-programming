/*******************************************************************************
*@author  Evan Trout
*@file    DoublyLinkedList.cpp
*@date    08/26/2019
*@brief   Implementation file for DoublyLinkedList class. Creates and maintains a
*         doubly linked list of nodes containing ints.
*******************************************************************************/

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

#include "Node.h"
#include "DoublyLinkedList.h"

Node<int>* DoublyLinkedList::getNodeAt(int position) const
{
  if ((position>0) && (position<=itemCount))
  {
    int p = 1;
    Node<int>* ptr = headPtr;
    while(p!=position)
    {
      p++;
      ptr = ptr->getNext();
    }
    return ptr;
  }
  else return nullptr;
}

Node<int>* DoublyLinkedList::search(int search) const
{
  Node<int>* ptr = headPtr;
  while (ptr != nullptr)
  {
    if (ptr->getItem() == search)
    {
      return ptr;
    }
    ptr = ptr->getNext();
  }
  return nullptr;
}

DoublyLinkedList::DoublyLinkedList()
{
  headPtr = nullptr;
  tailPtr = nullptr;
  itemCount = 0;
}

//Create a deep copy of a linked list
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& aList)
{
  itemCount = aList.getLength();
  int copyValue;
  for (int i = 1; i <= itemCount; i++)
  {
    copyValue = aList.getEntry(i);
    insert(copyValue);
  }
}

DoublyLinkedList::~DoublyLinkedList()
{
  clear();
}

bool DoublyLinkedList::isEmpty() const
{
  if (headPtr == nullptr) //If headPtr is nullptr then list is empty
  {
    return true;
  }
  else return false;
}

int DoublyLinkedList::getLength() const
{
  return itemCount;
}

void DoublyLinkedList::insert(const int& newEntry)
{
  Node<int>* n = new Node<int>(newEntry);
  if (headPtr == nullptr)
  {
    headPtr = n;
    tailPtr = n;
    itemCount = 1;
  }
  else
  {
    n->setPrev(tailPtr);
    tailPtr->setNext(n);
    tailPtr = n;
    itemCount++;
  }
}

bool DoublyLinkedList::remove(int searchInt)
{
  Node<int>* target = search(searchInt);
  if (target == nullptr)
  {
    return false;
  }
  else
  {
    Node<int>* prevNode = target->getPrev();
    Node<int>* nextNode = target->getNext();
    // No adjacent nodes -> now an empty list
    if (prevNode != nullptr)
    {
      prevNode->setNext(nextNode);
      target->setPrev(nullptr);
    }
    else
    {
      headPtr = nextNode;
    }
    if (nextNode != nullptr)
    {
      nextNode->setPrev(prevNode);
      target->setNext(nullptr);
    }
    else
    {
      tailPtr = prevNode;
    }
    delete target;
    itemCount--;
  }
}

void DoublyLinkedList::clear() //Removes all entries in the list
{
  Node<int>* nodeToDeletePtr = headPtr;
  while (headPtr != nullptr)
  {
    headPtr = headPtr->getNext(); //Move headPtr to next node
    nodeToDeletePtr->setNext(nullptr); //Clear ptr of target node
    delete nodeToDeletePtr; //Delete node contents
    nodeToDeletePtr = headPtr; //Bring nodeToDeletePtr up to headPtr
  }
  itemCount = 0;
}

int DoublyLinkedList::getEntry(int position) const
{
  if ((position > 0) && (position <= itemCount))
  {
    Node<int>* targetNode = getNodeAt(position);
    return targetNode->getItem();
  }
}

void DoublyLinkedList::setEntry(int position, const int& newEntry)
{
  if ((position > 0) && (position <= itemCount))
  {
    Node<int>* targetNode = getNodeAt(position);
    targetNode->setItem(newEntry);
  }
}

int DoublyLinkedList::smallest()
{
  Node<int>* ptr = headPtr;
  if (ptr == nullptr)
  {
    return -1;
  }
  int smallest = ptr->getItem();
  while (ptr != nullptr)
  {
    int cur = ptr->getItem();
    if (cur < smallest)
    {
      smallest = cur;
    }
    ptr = ptr->getNext();
  }
  return smallest;
}

int DoublyLinkedList::largest()
{
  Node<int>* ptr = headPtr;
  if (ptr == nullptr)
  {
    return -1;
  }
  int largest = ptr->getItem();
  while (ptr != nullptr)
  {
    int cur = ptr->getItem();
    if (cur > largest)
    {
      largest = cur;
    }
    ptr = ptr->getNext();
  }
  return largest;
}

double DoublyLinkedList::average()
{
  Node<int>* ptr = headPtr;
  if (ptr == nullptr)
  {
    return 0.0;
  }
  int total = 0;
  while (ptr != nullptr)
  {
    total += ptr->getItem();
    ptr = ptr->getNext();
  }
  double average = (double)total/(double)itemCount;
  return average;
}

void DoublyLinkedList::merge(const std::string& aList)
{
  // Convert string to a second dll
  DoublyLinkedList tempList;
  std::stringstream in(aList);
  int temp;
  while(in >> temp) {
    tempList.insert(temp);
  }
}

void DoublyLinkedList::print()
{
  Node<int>* ptr = headPtr;
  while (ptr != nullptr)
  {
    int cur = ptr->getItem();
    std::cout << cur << " ";
    ptr = ptr->getNext();
  }
}

void DoublyLinkedList::reverseList()
{
  Node<int>* tempPtr = headPtr;
  headPtr = tailPtr;
  tailPtr = tempPtr;
  Node<int>* ptr = tailPtr;
  while (ptr != nullptr)
  {
    tempPtr = ptr->getNext();
    ptr->setNext(ptr->getPrev());
    ptr->setPrev(tempPtr);
    ptr = ptr->getPrev();
  }
}

void DoublyLinkedList::sort()
{
  int min = smallest();
  Node<int>* newHeadPtr = new Node<int>(min);
  itemCount++;
  remove(min);
  Node<int>* ptr = newHeadPtr;
  Node<int>* newNode;
  while (!isEmpty())
  {
    min = smallest();
    newNode = new Node<int>(min);
    itemCount++;
    newNode->setPrev(ptr);
    ptr->setNext(newNode);
    remove(min);
    newNode = nullptr;
    ptr = ptr->getNext();
  }
  headPtr = newHeadPtr;
  newHeadPtr = nullptr;
  tailPtr = ptr;
  ptr = nullptr;
  newNode = nullptr;
}