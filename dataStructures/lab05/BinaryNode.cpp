/*******************************************************************************
*@author  Evan Trout
*@file    BinaryNode.cpp
*@date    11/14/2018
*@brief   Implementation file for the BinaryNode class. Creates a special type
*         of node used for the BinaryNodeTree class. Header created by Carrano
*         and Henry.
*******************************************************************************/

//CONSTRUCTORS

template<class ItemType>
BinaryNode<ItemType>::BinaryNode() : leftChildPtr(nullptr), rightChildPtr(nullptr)
{}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem) : item(anItem),
                                leftChildPtr(nullptr), rightChildPtr(nullptr)
{}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr,
                                BinaryNode<ItemType>* rightPtr)
{
  item = anItem;
  leftChildPtr = leftPtr;
  rightChildPtr = rightPtr;
}

//OTHER METHODS
template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
  item = anItem;
}

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
  return item;
}

template<class ItemType>
int BinaryNode<ItemType>::getKey() const
{
  return int(item);
}

template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const //Determines if this node is a dead end
{
  return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const
{
  return leftChildPtr;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const
{
  return rightChildPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr)
{
  leftChildPtr = leftPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr)
{
  rightChildPtr = rightPtr;
}
