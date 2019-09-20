/*******************************************************************************
*@author  Evan Trout
*@file    Node.cpp
*@date    8/26/2019
*@brief   Implementation file for the Node class. Template class that creates
*         a single node with an item of ItemType and pointers to the next and
*         previous items in the chain. Used by DoublyLinkedList class.
*******************************************************************************/

#include "Node.h"

template<class ItemType>
Node<ItemType>::Node() : next(nullptr), prev(nullptr)
{
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr), prev(nullptr)
{
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr)
                    : item(anItem), next(nextNodePtr), prev(prevNodePtr)
{
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
  item = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
  next = nextNodePtr;
}

template<class ItemType>
void Node<ItemType>::setPrev(Node<ItemType>* prevNodePtr)
{
  prev = prevNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
  return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
  return next;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getPrev() const
{
  return prev;
}
