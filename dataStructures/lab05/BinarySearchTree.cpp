/*******************************************************************************
*@author  Evan Trout
*@file    BinarySearchTree.cpp
*@date    09/25/19
*@brief   Implementation file for BinarySearchTree class, which controls a tree of linked
*         BinaryNodes and allows for various operations on them.
*******************************************************************************/

#include <iostream>
#include "BinaryNode.h"
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
  rootPtr = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
  destroyTree(rootPtr);
}

void BinarySearchTree::destroyTree(BinaryNode<char>* subTreePtr)
{
  if (subTreePtr != nullptr)
  {
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    delete subTreePtr;
  }
}

bool BinarySearchTree::isEmpty() const
{
  return (rootPtr == nullptr);
}

bool BinarySearchTree::addItem(char x)
{
  if (isEmpty())
  {
    rootPtr = new BinaryNode<char>(x);
    return true;
  }
  else
  {
    return recursiveAdd(rootPtr, x);
  }
}

bool BinarySearchTree::recursiveAdd(BinaryNode<char>* subTreePtr, char x)
{
  int target = int(x);
  if (target < subTreePtr->getKey())
  {
    if (subTreePtr->getLeftChildPtr() == nullptr)
    {
      BinaryNode<char>* tempPtr = new BinaryNode<char>(x);
      subTreePtr->setLeftChildPtr(tempPtr);
      tempPtr = nullptr;
      return true;
    }
    else
    {
      return recursiveAdd(subTreePtr->getLeftChildPtr(), x);
    }
  }
  else if (target >= subTreePtr->getKey())
  {
    if (subTreePtr->getRightChildPtr() == nullptr)
    {
      BinaryNode<char>* tempPtr = new BinaryNode<char>(x);
      subTreePtr->setRightChildPtr(tempPtr);
      tempPtr = nullptr;
      return true;
    }
    else
    {
      return recursiveAdd(subTreePtr->getRightChildPtr(), x);
    }
  }
  else
  {
    return false; // could throw error instead?
  }
}

bool BinarySearchTree::remove(char x)
{
  if (isEmpty())
  {
    return false;
  }
  else
  {
    if (searchElement(x) == false)
    {
      return false; //Could not find target
    }
    else if (rootPtr->getItem() == x)
    {
      //special case where rootPtr is target
      char newItem = deleteMin(rootPtr, rootPtr->getRightChildPtr());
      rootPtr->setItem(newItem);
      return true;
    }
    // target has no children
    else
    {
      if (int(x) >= rootPtr->getKey())
      {
        return recursiveDelete(rootPtr, rootPtr->getRightChildPtr(), x);
      }
      else
      {
        return recursiveDelete(rootPtr, rootPtr->getLeftChildPtr(), x);
      }
    }
  }
}

bool BinarySearchTree::recursiveDelete(BinaryNode<char>* parentPtr, BinaryNode<char>* childPtr, char x)
{
  if (childPtr == nullptr)
  {
    return false;
  }
  else if (childPtr->getItem() == x) // item has been found
  {
    // First check if there's another instance lower in the tree
    if (recursiveDelete(childPtr, childPtr->getRightChildPtr(), x))
    {
      return true;
    }
    else // only instance, delete this node
    {
      // track which child the childptr is
      bool left = false;
      if (childPtr == parentPtr->getLeftChildPtr())
      {
        left = true;
      }
      if (childPtr->getLeftChildPtr() == nullptr && childPtr->getRightChildPtr() == nullptr) // no children
      {
        delete childPtr;
        childPtr = nullptr;
        left ? (parentPtr->setLeftChildPtr(nullptr)) : (parentPtr->setRightChildPtr(nullptr));
        return true;
      }
      else if (childPtr->getLeftChildPtr() != nullptr && childPtr->getRightChildPtr() == nullptr) // left child
      {
        BinaryNode<char>* tempPtr = childPtr->getLeftChildPtr();
        delete childPtr;
        childPtr = nullptr;
        left ? (parentPtr->setLeftChildPtr(tempPtr)) : (parentPtr->setRightChildPtr(tempPtr));
        return true;
      }
      else if (childPtr->getLeftChildPtr() == nullptr && childPtr->getRightChildPtr() != nullptr) // right child
      {
        BinaryNode<char>* tempPtr = childPtr->getRightChildPtr();
        delete childPtr;
        childPtr = nullptr;
        left ? (parentPtr->setLeftChildPtr(tempPtr)) : (parentPtr->setRightChildPtr(tempPtr));
        return true;
      }
      else if (childPtr->getLeftChildPtr() != nullptr && childPtr->getRightChildPtr() != nullptr) // two children
      {
        char newItem = deleteMin(childPtr, childPtr->getRightChildPtr());
        childPtr->setItem(newItem);
        return true;
      }
    }
  }
  else
  {
    parentPtr = childPtr;
    if (int(x) >= parentPtr->getKey())
    {
      childPtr = parentPtr->getRightChildPtr();
    }
    else
    {
      childPtr = parentPtr->getLeftChildPtr();
    }
    return recursiveDelete(parentPtr, childPtr, x);
  }
}

char BinarySearchTree::deleteMin(BinaryNode<char>* currentParent, BinaryNode<char>* currentChild)
{
  bool left = false;
  while (currentChild->getLeftChildPtr() != nullptr)
  {
    left = true;
    currentParent = currentChild;
    currentChild = currentChild->getLeftChildPtr();
  }
  char targetItem = currentChild->getItem();
  if (currentChild->getRightChildPtr() == nullptr)
  {
    delete currentChild;
    currentChild = nullptr;
    left ? currentParent->setLeftChildPtr(nullptr) : currentParent->setRightChildPtr(nullptr);
  }
  else
  {
    left ? currentParent->setLeftChildPtr(currentChild->getRightChildPtr()) : currentParent->setRightChildPtr(currentChild->getRightChildPtr());
    delete currentChild;
    currentChild = nullptr;
  }
  return targetItem;
}

bool BinarySearchTree::leaf(char x) const
{
  if (rootPtr == nullptr)
  {
    return false;
  }
  BinaryNode<char> *target = findNode(rootPtr, x);
  return ((target->getLeftChildPtr() == nullptr) && (target->getRightChildPtr() == nullptr));
}

BinaryNode<char> *BinarySearchTree::findNode(BinaryNode<char> *subTreePtr, char x) const
{
  if (subTreePtr == nullptr)
  {
    return nullptr;
  }
  else if (subTreePtr->getItem() == x) // item was found
  {
    // Confirm that this is the lowest instance of this item
    if (subTreePtr->getRightChildPtr() != nullptr)
    {
      BinaryNode<char>* doubleCheck = nullptr;
      doubleCheck = findNode(subTreePtr->getRightChildPtr(), x);
      if (doubleCheck != nullptr)
      {
        return doubleCheck;
      }
      else
      {
        return subTreePtr;
      }
    }
    else
    {
      return subTreePtr;
    }
  }
  else if (subTreePtr->getRightChildPtr() == nullptr && subTreePtr->getLeftChildPtr() == nullptr) // item not found and no children
  {
    return nullptr;
  }
  else if ((int)x >= subTreePtr->getKey())
  {
    return findNode(subTreePtr->getRightChildPtr(), x);
  }
  else
  {
    return findNode(subTreePtr->getLeftChildPtr(), x);
  }
}

void BinarySearchTree::printLeaf() const
{
  leafPrinter(rootPtr);
}

void BinarySearchTree::leafPrinter(BinaryNode<char> *treePtr) const
{
  if (treePtr != nullptr)
  {
    if ((treePtr->getLeftChildPtr() == nullptr) && (treePtr->getRightChildPtr() == nullptr))
    {
      // found a leaf
      std::cout << treePtr->getItem() << ' ';
    }
    else
    {
      leafPrinter(treePtr->getLeftChildPtr());
      leafPrinter(treePtr->getRightChildPtr());
    }
  }
}

void BinarySearchTree::printTreeHeight() const
{
  int height = heightHelper(rootPtr) - 1;
  std::cout << height;
}

int BinarySearchTree::heightHelper(BinaryNode<char> *subTreePtr) const
{
  if (subTreePtr == nullptr)
  {
    return 0;
  }
  else
  {
    return (1 + std::max(heightHelper(subTreePtr->getLeftChildPtr()), heightHelper(subTreePtr->getRightChildPtr())));
  }
}

void BinarySearchTree::printNode(char &x)
{
  std::cout << x << ' ';
}

void BinarySearchTree::preorder() const
{
  preorderHelper(printNode, rootPtr);
}

void BinarySearchTree::preorderHelper(void visit(char &), BinaryNode<char> *treePtr) const
{
  if (treePtr != nullptr)
  {
    char item = treePtr->getItem();
    visit(item);
    preorderHelper(visit, treePtr->getLeftChildPtr());
    preorderHelper(visit, treePtr->getRightChildPtr());
  }
}

void BinarySearchTree::postorder() const
{
  postorderHelper(printNode, rootPtr);
}

void BinarySearchTree::postorderHelper(void visit(char &), BinaryNode<char> *treePtr) const
{
  if (treePtr != nullptr)
  {
    postorderHelper(visit, treePtr->getLeftChildPtr());
    postorderHelper(visit, treePtr->getRightChildPtr());
    char item = treePtr->getItem();
    visit(item);
  }
}

void BinarySearchTree::inorder() const
{
  inorderHelper(printNode, rootPtr);
}

void BinarySearchTree::inorderHelper(void visit(char &), BinaryNode<char> *treePtr) const
{
  if (treePtr != nullptr)
  {
    inorderHelper(visit, treePtr->getLeftChildPtr());
    char item = treePtr->getItem();
    visit(item);
    inorderHelper(visit, treePtr->getRightChildPtr());
  }
}

void BinarySearchTree::levelorder() const
{
  int height = heightHelper(rootPtr);
  for (int i = 1; i <= height; i++)
  {
    printLevel(rootPtr, i);
  }
}

void BinarySearchTree::printLevel(BinaryNode<char> *subTreePtr, int level) const
{
  if (subTreePtr == nullptr)
  {
    return;
  }
  if (level == 1)
  {
    std::cout << subTreePtr->getItem() << ' ';
  }
  else if (level > 1)
  {
    printLevel(subTreePtr->getLeftChildPtr(), level - 1);
    printLevel(subTreePtr->getRightChildPtr(), level - 1);
  }
}

bool BinarySearchTree::searchElement(char x) const
{
  BinaryNode<char>* target = findNode(rootPtr, x);
  if (target == nullptr)
  {
    return false;
  }
  else
  {
    return true;
  }
}
