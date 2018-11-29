/*******************************************************************************
*@author  Evan Trout
*@file    BinarySearchTree.cpp
*@date    11/27/2018
*@brief   Implementation file for the BinaryNodeTree class. Creates and maintains
*         a Binary Search Tree out of Binary Nodes. Header file created by
*         Carrano and Henry.
*******************************************************************************/

//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
// Recursively finds where the given node should be placed and
// inserts it in a leaf at that point.
BinaryNode<ItemType>* BinarySearchTree<ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr,
                                    BinaryNode<ItemType>* newNode)
{

}

// Removes the given target value from the tree while maintaining a
// binary search tree.
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,
                                  KeyType aKey,
                                  bool& success)
{

}

// Removes a given node from a tree while maintaining a
// binary search tree.
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodePtr)
{

}

// Removes the leftmost node in the left subtree of the node
// pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree.
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr,
                                         ItemType& inorderSuccessor)
{

}

// Returns a pointer to the node containing the given value,
// or nullptr if not found.
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr, KeyType aKey) const
 {

 }

template <class ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
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
int BinarySearchTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
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
void BinarySearchTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
  if (subTreePtr != nullptr)
  {
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    delete subTreePtr; //Is this the right type of delete?
  }
}

<template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr)
{
  BinaryNode<ItemType>* newTreePtr = nullptr;
  if (treePtr != nullptr)
  {
    newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr)
    newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
    newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
  }
  return newTreePtr;
}

// Recursive traversal helper methods:
template <class ItemType>
void BinarySearchTree<ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
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
void BinarySearchTree<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
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
void BinarySearchTree<ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
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
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
{

}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree)
{
  rootPtr = copyTree(tree.rootPtr);
}

template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
  destroyTree(rootPtr);
}

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
  return (rootPtr == nullptr);
}

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
  return getHeightHelper(rootPtr);
}

template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
  return getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{

}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<ItemType>::remove(const KeyType& aKey)
{

}

template<typename KeyType, typename ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const KeyType& aKey) const throw(NotFoundException)
{

}

// An entry in a BST can be set if and only if "item == aKey".
// If this is not the case, throw InvalidSetEntryRequest.
// If "aKey" does not exist in the tree, throw NotFoundException.
template<typename KeyType, typename ItemType>
void BinarySearchTree<ItemType>::setEntry(const KeyType& aKey, const ItemType& item) const
 throw(NotFoundException, InvalidSetEntryRequest)
{

}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<ItemType>::contains(const KeyType& aKey) const
{

}

template <class ItemType>
void BinarySearchTree<ItemType>::clear()
{
  destroyTree(rootPtr);
}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
  preorder(visit, rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
  inorder(visit, rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
  postorder(visit, rootPtr);
}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
template <class ItemType>
BinarySearchTree& BinarySearchTree<ItemType>::operator=(const BinarySearchTree& rightHandSide)
{

}
