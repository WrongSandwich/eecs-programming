#include <iostream>
#include <string>
#include <stdexcept>

#include "LinkedList.h"
#include "Node.h"
#include "ListInterface.h"

template<class ItemType>
Node<itemType>* LinkedList<itemType>::getNodeAt(int position) const
{
  if ((position>0) && (position<=itemCount))
  {
    int p = 1;
    Node<itemType>* ptr = headPtr;
    while(p!=position)
    {
      p++;
      ptr = ptr->getNext();
    }
    return ptr;
  }
  else return nullptr;
}


//See LinkedList.h and main on 268 site

template <class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr)
{
}

template <class ItemType> //Create a deep copy of a linked list
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList);
{
  int length = aList.getLength();
  for (int i = 1; i <= length; i++)
  {
    insert(i, aList.getEntry(i));
  }
}

template <class ItemType>
LinkedList<ItemType>::~LinkedList()
{
  clear();
}

template <class ItemType>
bool LinkedList<ItemType>::isEmpty() const;
{
  if (headPtr == nullptr) //If headPtr is nullptr then list is empty
  {
    return true;
  }
  else return false;
}

template <class ItemType>
int LinkedList<ItemType>::getLength() const;
{
  return itemCount;
}

template <class ItemType>
void LinkedList<ItemType>::insert(int newPosition, const itemType& newEntry) throw (std::runtime_error)
{
  //Must first confirm that insertion is valid (pos is not too high or low)
  //Main has this list start at pos 1 which is why 0 is not allowed
  if (newPosition > 0) && (newPosition <= (itemCount + 1))
  {
    Node<itemType>* n = new Node<itemType>(newEntry);
    if (headPtr == nullptr) //Checking if list is empty, also could check itemCount
    {
      headPtr = n; //Make this node the new head
      itemCount = 1;
    }
    else if (newPosition == 1) //Adding something to head of list
    {
      n->setNext(headPtr);
      headPtr = n;
      itemCount++;
    }
    else
    {
      Node<ItemType>* prev = getNodeAt(pos-1);
      n->setNext(prev->getNext()); //Setting n's pointer to next item in list
      prev->setNext(n);//Setting prev's pointer to point to new addition
      itemCount++;
    }
  }
  else throw std::runtime_error("error");
}

template <class ItemType>
void LinkedList<ItemType>::remove(int position) throw (std::runtime_error)
{
  if (position > 0) && (position <= itemCount) //Checking that position is valid
  {
    if (isEmpty = true) //List is empty
    {
      throw std::runtime_error("error")
    }
    else if (position == 1)
    {
      Node<ItemType>* newHead = getNodeAt(position+1); //getNode in position 2
      delete[] headPtr; //delete current head
      headPtr = newHead; //Make second position new head
      itemCount = itemCount - 1;
    }
    else
    {
      Node<ItemType>* prev = getNodeAt(position-1);
      Node<ItemType>* next = getNodeAt(position+1);
      Node<ItemType>* target = getNodeAt(position);
      delete[] target;
      prev->setNext(next);
      itemCount = itemCount - 1;
    }
  }
  else throw std::runtime_error("error");
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
                                    throw (std:runtime_error)
{
  if ((position > 0) && (position <= itemCount))
  {
    Node<ItemType>* targetNode = getNodeAt(position);
    targetNode->setItem(newEntry);
  }
  else throw std::runtime_error("error");
}
