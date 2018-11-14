/*******************************************************************************
*@author  Evan Trout
*@file    BinaryNodeTree.cpp
*@date    11/14/18
*@brief   Implementation file for the BinaryNodeTree class. Creates a tree of
*         BinaryNode instances and contains member functions for interaction
*         with and manipulation of the Binary Tree.
*******************************************************************************/

#include "BinaryNode.h"
#include "BinaryTreeInterface.h"
#include "PrecondViolationExcep.h"

#include <iostream>

//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
  if (subTreePtr == nullptr)
  {
    return 0;
  }
  else
  {
    return (1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr())));
  }
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
{
  if (subTreePtr == nullptr)
  {
    return 0;
  }
  else
  {
    return (1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr -> getRightChildPtr()));
  }
}

template <class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
  if (subTreePtr != nullptr)
  {
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    delete subTreePtr; //MIGHT BE WRONG KIND OF DELETE?
  }
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
  BinaryNode<ItemType>* newTreePtr = nullptr;
  if (treePtr != nullptr)
  {
    newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
    newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
    newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
  }
  return newTreePtr;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if (treePtr != nullptr)
  {
    ItemType item = treePtr->getItem();
    visit(item);
    preorder(visit, treePtr->getLeftChildPtr());
    preorder(visit, treePtr->getRightChildPtr());
  }
}

template <class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if (treePtr != nullptr)
  {
    inorder(visit, treePtr->getLeftChildPtr());
    ItemType item = treePtr->getItem();
    visit(item);
    inorder(visit, treePtr->getRightChildPtr());
  }
}

template <class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if (treePtr != nullptr)
  {
    postorder(visit, treePtr->getLeftChildPtr());
    postorder(visit, treePtr->getRightChildPtr());
    ItemType item = treePtr->getItem();
    visit(item);
  }
}

//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
{
  rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr); //CAN probably remove nullptrs
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
                                         const BinaryNodeTree<ItemType>* leftTreePtr,
                                         const BinaryNodeTree<ItemType>* rightTreePtr)
{
  rootPtr = new BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr),
                                              copyTree(rightTreePtr->rootPtr));
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& tree)
{
  rootPtr = copyTree(tree.rootPtr);
}

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
  destroyTree(rootPtr);
}

//------------------------------------------------------------
// Public BinaryTreeInterface Methods Section.
//------------------------------------------------------------
template<class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const
{
  return (rootPtr == nullptr);
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const
{
  return getHeightHelper(rootPtr);
}

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
  return getNumberOfNodesHelper(rootPtr);
}

template<class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const throw(PrecondViolationExcep)
{
  if (!isEmpty())
  {
    return rootPtr->getItem();
  }
  else throw PrecondViolationExcep ("Tree is empty");
}

template<class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData)
{
  rootPtr->setItem(newData);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::clear()
{
  destroyTree(rootPtr);
}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------

template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
  preorder(visit, rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
  inorder(visit, rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
  postorder(visit, rootPtr);
}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
template<class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree<ItemType>& rightHandSide)
{
  this->clear();
  copyTree(rightHandSide);
  return *this;
}
