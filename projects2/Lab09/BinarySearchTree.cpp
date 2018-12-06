/*******************************************************************************
*@author  Evan Trout
*@file    BinarySearchTree.cpp
*@date    11/27/2018
*@brief   Implementation file for the BinaryNodeTree class. Creates and maintains
*         a Binary Search Tree out of Binary Nodes. Header file created by
*         Carrano and Henry.
*******************************************************************************/

#include <stdexcept>
#include <iostream>
#include "BinaryNode.h"
#include "InvalidSetEntryRequest.h"
#include "NotFoundException.h"
#include "Executive.h"

//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
// Recursively finds where the given node should be placed and
// inserts it in a leaf at that point.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr,
                                    BinaryNode<ItemType>* newNode)
{
  if (subTreePtr == nullptr)
  {
    rootPtr = newNode;
    return rootPtr;
  }
  else if (newNode->getItem() < subTreePtr->getItem().getID())
  {
    if (subTreePtr->getLeftChildPtr() == nullptr)
    {
      subTreePtr->setLeftChildPtr(newNode);
      return subTreePtr->getLeftChildPtr();
    }
    else
    {
      insertInorder(subTreePtr->getLeftChildPtr(), newNode);
    }
  }
  else if (newNode->getItem() > subTreePtr->getItem().getID())
  {
    if (subTreePtr->getRightChildPtr() == nullptr)
    {
      subTreePtr->setRightChildPtr(newNode);
      return subTreePtr->getRightChildPtr();
    }
    else
    {
      insertInorder(subTreePtr->getRightChildPtr(), newNode);
    }
  }
  else
  {
    return nullptr;
  }
}

// Removes the given target value from the tree while maintaining a
// binary search tree.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,
                                  KeyType aKey,
                                  bool& success)
{
  if (subTreePtr == nullptr)
  {
    success = false;
  }
  else if (subTreePtr->getItem() == aKey)
  {
    subTreePtr = removeNode(subTreePtr);
    success = true;
  }
  else if (subTreePtr->getItem() < aKey)
  {
    BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr->getLeftChildPtr(), aKey, success);
    subTreePtr->setLeftChildPtr(tempPtr);
  }
  else
  {
    BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr->getRightChildPtr(), aKey, success);
    subTreePtr->setRightChildPtr(tempPtr);
  }
  return subTreePtr;
}

// Removes a given node from a tree while maintaining a
// binary search tree.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeNode(BinaryNode<ItemType>* nodePtr)
{
  if (nodePtr->isLeaf()) //nodePtr is a leaf and has no children; can just be deleted
  {
    delete nodePtr;
    nodePtr = nullptr;
    return nodePtr;
  }
  else if (nodePtr->getLeftChildPtr() == nullptr) //Only left child
  {
    BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightChildPtr();
    delete nodePtr;
    nodePtr = nullptr;
    return nodeToConnectPtr;
  }
  else if (nodePtr->getRightChildPtr() == nullptr) //Only right child
  {
    BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftChildPtr();
    delete nodePtr;
    nodePtr = nullptr;
    return nodeToConnectPtr;
  }
  else //Node has two children
  {
    ItemType newNodeValue;
    BinaryNode<ItemType>* tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
    nodePtr->setRightChildPtr(tempPtr);
    nodePtr->setItem(newNodeValue);
    return nodePtr;
  }
}

// Removes the leftmost node in the left subtree of the node
// pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr,
                                         ItemType& inorderSuccessor)
{
  if (subTreePtr->getLeftChildPtr() == nullptr)
  {
    inorderSuccessor = subTreePtr->getItem();
    return removeNode(subTreePtr);
  }
  else
  {
    BinaryNode<ItemType>* tempPtr = removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor);
    subTreePtr->setLeftChildPtr(tempPtr);
    return subTreePtr;
  }
}

// Returns a pointer to the node containing the given value,
// or nullptr if not found.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::findNode(BinaryNode<ItemType>* treePtr, KeyType aKey) const
{
  if (treePtr == nullptr)
  {
    return nullptr;
  }
  else if (treePtr->getItem() == aKey)
  {
    return treePtr;
  }
  else if (treePtr->getItem() < aKey)
  {
    return (findNode(treePtr->getRightChildPtr(), aKey));
  }
  else
  {
    return (findNode(treePtr->getLeftChildPtr(), aKey));
  }
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
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

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
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

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
  if (subTreePtr != nullptr)
  {
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    delete subTreePtr;
  }
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::copyTree(const BinaryNode<ItemType>* treePtr)
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

// Recursive traversal helper methods:
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if (treePtr != nullptr)
  {
    ItemType item = treePtr->getItem();
    visit(item);
    preorder(visit, treePtr->getLeftChildPtr());
    preorder(visit, treePtr->getRightChildPtr());
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if (treePtr != nullptr)
  {
    inorder(visit, treePtr->getLeftChildPtr());
    ItemType item = treePtr->getItem();
    visit(item);
    inorder(visit, treePtr->getRightChildPtr());
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
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
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(const ItemType& rootItem)
{
  rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(const BinarySearchTree<KeyType, ItemType>& tree)
{
  rootPtr = copyTree(tree.rootPtr);
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
  destroyTree(rootPtr);
}

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty() const
{
  return (rootPtr == nullptr);
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getHeight() const
{
  return getHeightHelper(rootPtr);
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getNumberOfNodes() const
{
  return getNumberOfNodesHelper(rootPtr);
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::add(const ItemType& newEntry)
{
  BinaryNode<ItemType>* newTreePtr = new BinaryNode<ItemType>(newEntry);
  BinaryNode<ItemType>* inorderPtr = nullptr;
  inorderPtr = insertInorder(rootPtr, newTreePtr);
  if (inorderPtr == nullptr)
  {
    return false;
  }
  else return true;
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(const KeyType& aKey)
{
  bool removeSuccess = 0;
  rootPtr = removeValue(rootPtr, aKey, removeSuccess);
  return removeSuccess;
}

template<typename KeyType, typename ItemType>
ItemType BinarySearchTree<KeyType, ItemType>::getEntry(const KeyType& aKey) const throw(NotFoundException)
{
  BinaryNode<ItemType>* searchNode = findNode(rootPtr, aKey);
  if (searchNode != nullptr)
  {
    return (searchNode->getItem());
  }
  else throw NotFoundException("getEntry could not find a matching task.");
}

// An entry in a BST can be set if and only if "item == aKey".
// If this is not the case, throw InvalidSetEntryRequest.
// If "aKey" does not exist in the tree, throw NotFoundException.
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::setEntry(const KeyType& aKey, const ItemType& item) const
 throw(NotFoundException, InvalidSetEntryRequest)
{
  if (item.getID() == aKey)
  {
    BinaryNode<ItemType>* searchNode = findNode(rootPtr, aKey);
    if (searchNode != nullptr)
    {
      searchNode->setItem(item);
    }
    else throw NotFoundException("setEntry could not find a matching task.");
  }
  else throw InvalidSetEntryRequest("setEntry called with non-matching item and key");
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::contains(const KeyType& aKey) const
{
  BinaryNode<ItemType>* searchNode = findNode(rootPtr, aKey);
  if (searchNode == nullptr)
  {
    return false;
  }
  else return true;
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clear()
{
  destroyTree(rootPtr);
}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::preorderTraverse(void visit(ItemType&)) const
{
  preorder(visit, rootPtr);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorderTraverse(void visit(ItemType&)) const
{
  inorder(visit, rootPtr);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::postorderTraverse(void visit(ItemType&)) const
{
  postorder(visit, rootPtr);
}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
                                    operator=(const BinarySearchTree<KeyType, ItemType>& rightHandSide)
{
  if (!isEmpty())
  {
    clear();
  }
  this = copyTree(&rightHandSide);
  return *this;
}
