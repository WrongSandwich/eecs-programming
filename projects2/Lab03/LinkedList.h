/*******************************************************************************
*@author  Evan Trout
*@file    LinkedList.h
*@date    09/19/2018
*@brief   Header file for the LinkedList class. Creates and maintains a
*         linked list of nodes that is used by the WebBrowser class. Derived
*         from ListInterface class.
*******************************************************************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListInterface.h"
#include "Node.h"
#include <string>
#include <stdexcept>

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node in the chain;
                            // (contains the first entry in the list)
   int itemCount;           // Current count of list items

   // Locates a specified node in this linked list.
   // @pre  position is the number of the desired node;
   //       position >= 1 and position <= itemCount.
   // @post  The node is found and a pointer to it is returned.
   // @param position  The number of the node to locate.
   // @return  A pointer to the node at the given position.
   Node<ItemType>* getNodeAt(int position) const;

public:
  /**
  * @post creates a LinkedList and sets headPtr to nullptr and itemCount to 0
  * @return the initialized LinkedList
  */
   LinkedList();

   /**
   * @post creates a deep copy of a LinkedList aList
   * @param aList: a LinkedList the user wants to create a copy of
   * @return the copy of aList
   */
   LinkedList(const LinkedList<ItemType>& aList);

   /**
   * @post all memory is freed and the WebBrowser is deleted
   */
   ~LinkedList();

   /**
   * @return 1 if the list is empty, 0 if the list is not
   */
   bool isEmpty() const;

   /**
   * @return the length of the LinkedList
   */
   int getLength() const;

   /**
   * @param position: 1 <= position <= length, a place to insert a new node
   * @param newEntry: A new entry to put in the list
   * @post A new node is inserted into the list at the given position.
   */
   void insert(int newPosition, const ItemType& newEntry) throw (std::runtime_error);

   /**
   * @param position: 1 <= position <= length, a node the user wants to remove
   * @post The node at the given position is removed
   */
   void remove(int position) throw (std::runtime_error);

   /**
   * @post Removes all entries in the list
   */
   void clear();

   /**
   * @param position: 1 <= position <= length, a node the user wants to learn the
   *                  contents of
   * @return the object in the node of type ItemType
   */
   ItemType getEntry(int position) const throw(std::runtime_error);

   /**
   * @pre The position is between 1 and the list's length
   * @post The entry at the given position is replaced with the new entry
   * @param position:  1<= position <= length
   * @param newEntry: A new entry to put in the list
   **/
   void setEntry(int position, const ItemType& newEntry) throw(std::runtime_error);
};

#include "LinkedList.cpp"
#endif
