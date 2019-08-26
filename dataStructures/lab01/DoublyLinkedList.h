/*******************************************************************************
*@author  Evan Trout
*@file    DoublyLinkedList.h
*@date    08/26/2019
*@brief   Header file for the DoublyLinkedList class. Creates and maintains a
*         doubly linked list of nodes containing ints.
*******************************************************************************/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "Node.h"
#include <stdexcept>

class DoublyLinkedList
{
private:
   Node<int>* headPtr; // Pointer to first node in the chain
   Node<int>* tailPtr; // Pointer to last node in the chain
   int itemCount;           // Current count of list items

   // Locates a specified node in this linked list.
   // @pre  position is the number of the desired node;
   //       position >= 1 and position <= itemCount.
   // @post  The node is found and a pointer to it is returned.
   // @param position  The number of the node to locate.
   // @return  A pointer to the node at the given position.
   Node<int>* getNodeAt(int position) const;

   Node<int>* search(int search) const;

public:
  /**
  * @post creates a LinkedList and sets headPtr to nullptr, tailPtr to nullptr, and itemCount to 0
  * @return the initialized LinkedList
  */
   DoublyLinkedList();

   /**
   * @post creates a deep copy of a LinkedList aList
   * @param aList: a LinkedList the user wants to create a copy of
   * @return the copy of aList
   */
   DoublyLinkedList(const DoublyLinkedList& aList);

   /**
   * @post all memory is freed and the LinkedList is deleted
   */
   ~DoublyLinkedList();

   /**
   * @return 1 if the list is empty, 0 if the list is not
   */
   bool isEmpty() const;

   /**
   * @return the length of the LinkedList
   */
   int getLength() const;

   /**
   * @param newEntry: A new entry to put in the list
   * @post A new node is inserted into the list at the tail.
   */
   void insert(const int& newEntry);

   /**
   * @param search: a value the user wants to remove
   * @post If found, the first node containing the given value is removed
   * @return True if node deleted, False if no match found
   */
   bool remove(int search) throw (std::runtime_error);

   /**
   * @post Removes all entries in the list
   */
   void clear();

   /**
   * @param position: 1 <= position <= length, a node the user wants to learn the
   *                  contents of
   * @return the object in the node of type ItemType
   */
   int getEntry(int position) const throw(std::runtime_error);

   /**
   * @pre The position is between 1 and the list's length
   * @post The entry at the given position is replaced with the new entry
   * @param position:  1<= position <= length
   * @param newEntry: A new entry to put in the list
   **/
   void setEntry(int position, const int& newEntry) throw(std::runtime_error);

   /**
   * @return the smallest element from the list
   **/
   int smallest();

   /**
   * @return the largest element from the list
   **/
   int largest();

   /**
   * @return the average of all the elements of the list
   **/
   double average();

   /**
   * @pre a valid DoublyLinkedList is passed
   * @post The provided list is merged with this list in an ascending list
   * @param aList: a list to be merged with this one
   **/
   void merge(const DoublyLinkedList& aList);

   /**
   * @post prints the contents of the list
   **/
   void print();

   /**
   * @post returns the reversed list of the original list
   **/
   void reverseList();
};

#endif
