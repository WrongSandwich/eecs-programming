/*******************************************************************************
*@author  Evan Trout
*@file    Node.h
*@date    8/26/2019
*@brief   Header file for the Node class. Template class that creates
*         a single node with an item of ItemType and pointers to the next and
*         previous items in the chain. Used by DoublyLinkedList class.
*******************************************************************************/

#ifndef NODE_H
#define NODE_H

template<class ItemType>
class Node
{
private:
  ItemType item;
  Node<ItemType>* next;
  Node<ItemType>* prev;
public:
  /**
  * @post creates a Node and initializes next to nullptr
  * @return returns the node
  */
  Node();

  /**
  * @param anItem, an object of some class that will be item for the new node
  * @post creates a Node, with next set to nullptr and anItem as item
  * @return returns the node
  */
  Node(const ItemType& anItem);

  /**
  * @param anItem (see constructor above)
  * @param nextNodePtr, a pointer to a node that will be used as next
  * @param prevNodePtr, a pointer to a node that will be used as prev
  * @post creates a Node, with pointers set and anItem as item
  * @return returns the node
  */
  Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr);

  /**
  * @param anItem, an object of some class that will be put in the node
  * @post item is set to anItem
  */
  void setItem(const ItemType& anItem);

  /**
  * @param nextNodePtr, a pointer to a node that will be placed next in the chain
  * @post next will point to the same node as nextNodePtr
  */
  void setNext(Node<ItemType>* nextNodePtr);

  /**
  * @param prevNodePtr, a pointer to a node that will be placed previous in the chain
  * @post prev will point to the same node as prevNodePtr
  */
  void setPrev(Node<ItemType>* prevNodePtr);

  /**
  * @return returns item for the current node
  */
  ItemType getItem() const;

  /**
  * @return returns a pointer to the destination of next
  */
  Node<ItemType>* getNext() const;

  /**
  * @return returns a pointer to the destination of prev
  */
  Node<ItemType>* getPrev() const;
};

#include "Node.cpp"

#endif
