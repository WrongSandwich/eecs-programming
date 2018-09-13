#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListInterface.h"
#include "Node.h"

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
   LinkedList();
   LinkedList(const LinkedList<ItemType>& aList);
   ~LinkedList();

   bool isEmpty() const;
   int getLength() const;
   void insert(int newPosition, const ItemType& newEntry) throw (PrecondViolatedExcep);
   void remove(int position) throw (PrecondViolatedExcep);
   void clear();

   ItemType getEntry(int position) const throw(PrecondViolatedExcep);

   void setEntry(int position, const ItemType& newEntry)
                               throw(PrecondViolatedExcep);
};

#include "LinkedList.cpp"
#endif
