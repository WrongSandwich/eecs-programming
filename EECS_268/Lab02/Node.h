/*******************************************************************************
*@author  Evan Trout
*@file    Node.h
*@date    09/19/2018
*@brief   Header file for the Node class. Template class that creates
*         a single node with an item of ItemType and a pointer to the next item
*         in the chain. Used by LinkedList class.
*******************************************************************************/

#ifndef NODE_H
#define NODE_H

template<class ItemType>
class Node
{
private:
  ItemType item;
  Node<ItemType>* next;
public:
  Node();
  Node(const ItemType& anItem);
  Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
  void setItem(const ItemType& anItem);
  void setNext(Node<ItemType>* nextNodePtr);
  ItemType getItem() const;
  Node<ItemType>* getNext() const;
};

#include "Node.cpp"

#endif
