/*******************************************************************************
*@author  Evan Trout
*@file    LinkedList.cpp
*@date    09/19/2018
*@brief   Implementation file for LinkedList class. Creates and maintains a
*         linked list of nodes that is used by the WebBrowser class. Derived
*         from ListInterface class.
*******************************************************************************/

#include <iostream>
#include <string>
#include <stdexcept>

#include "Node.h"

Node<int>* DoublyLinkedList::getNodeAt(int position) const
{
  if ((position>0) && (position<=itemCount))
  {
    int p = 1;
    Node<ItemType>* ptr = headPtr;
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
    insert(i, copyValue);
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

bool DoublyLinkedList::remove(int search)
{
  Node<int>* target = search(search);
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
    }
    else
    {
      headPtr = nextNode;
    }
    if (nextNode != nullptr)
    {
      nextNode->setPrev(prevNode);
    }
    else
    {
      tailPtr = prevNode;
    }
    delete target;
    itemCount--;
  }
}

template <class ItemType>
void LinkedList<ItemType>::clear() //Removes all entries in the list
{
  Node<ItemType>* nodeToDeletePtr = headPtr;
  while (headPtr != nullptr)
  {
    headPtr = headPtr->getNext(); //Move headPtr to next node
    nodeToDeletePtr->setNext(nullptr); //Clear ptr of target node
    delete nodeToDeletePtr; //Delete node contents
    nodeToDeletePtr = headPtr; //Bring nodeToDeletePtr up to headPtr
  }
  itemCount = 0;
}

template <class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw (std::runtime_error)
{
  if ((position > 0) && (position <= itemCount))
  {
    Node<ItemType>* targetNode = getNodeAt(position);
    return targetNode->getItem();
  }
  else throw std::runtime_error("error");
}

template <class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)
                                    throw (std::runtime_error)
{
  if ((position > 0) && (position <= itemCount))
  {
    Node<ItemType>* targetNode = getNodeAt(position);
    targetNode->setItem(newEntry);
  }
  else throw std::runtime_error("error");
}
