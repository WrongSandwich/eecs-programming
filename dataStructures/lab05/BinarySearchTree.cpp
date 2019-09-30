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
}

bool BinarySearchTree::remove(char x)
{
}

bool BinarySearchTree::removeMin()
{
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
  if (subTreePtr->getItem() == x)
  {
    return subTreePtr;
  }
  else if (subTreePtr->getRightChildPtr() == nullptr && subTreePtr->getLeftChildPtr() == nullptr)
  {
    return nullptr;
  }
  else
  {
    BinaryNode<char> *temp = findNode(subTreePtr->getLeftChildPtr(), x);
    if (temp != nullptr)
    {
      return temp;
    }
    else if (subTreePtr->getRightChildPtr() != nullptr)
    {
      return findNode(subTreePtr->getRightChildPtr(), x);
    }
    else
    {
      return nullptr;
    }
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
    int item = treePtr->getItem();
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
    int item = treePtr->getItem();
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
    int item = treePtr->getItem();
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

bool searchElement(char x) const
{
  
}
