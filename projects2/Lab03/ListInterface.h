/*******************************************************************************
*@author  Evan Trout
*@file    ListInterface.h
*@date    09/19/2018
*@brief   Pure abstract template class used as a parent class for LinkedList.
*******************************************************************************/

#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H
#include <stdexcept>

template <typename T>
class ListInterface
{
public:
  /**
  * @post All memory allocated by the implementing class should be freed.
  * This is an empty definition since it is a virtual destructor.
  */
  virtual ~ListInterface(){}

  /**
  * @return 1 if the list is empty, 0 if the list is not
  */
  virtual bool isEmpty() const = 0;

  /**
  * @return the length of the linked list
  */
  virtual int getLength() const = 0;

  /**
  * @param position: 1 <= position <= length, a place to insert a new node
  * @param newEntry: A new entry to put in the list
  * @post A new node is inserted into the list at the given position.
  */
  virtual void insert(int position,const T& newEntry) throw (std::runtime_error) = 0;

  /**
  * @param position: 1 <= position <= length, a node the user wants to remove
  * @post The node at the given position is removed
  */
  virtual void remove(int position) throw (std::runtime_error) = 0;

  /**
  * @post Removes all entries in the list
  */
  virtual void clear() = 0;

  /**
  * @param position: 1 <= position <= length, a node the user wants to learn the
  *                  contents of
  * @return the value in the node(type varies based on type of list)
  */
  virtual T getEntry(int position) const throw (std::runtime_error) = 0;

  /**
  * @pre The position is between 1 and the list's length
  * @post The entry at the given position is replaced with the new entry
  * @param position:  1<= position <= length
  * @param newEntry: A new entry to put in the list
  **/
  virtual void setEntry(int position, const T& newEntry) throw (std::runtime_error) = 0;
};

#endif
