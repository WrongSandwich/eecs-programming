/*******************************************************************************
*@author  Evan Trout
*@file    SkewHeap.cpp
*@date    11/08/19
*@brief   Implementation file for SkewHeap class, which controls a tree of linked
*         BinaryNodes and allows for various operations on them.
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "BinaryNode.h"
#include "SkewHeap.h"

SkewHeap::SkewHeap()
{
  rootPtr = nullptr;
  swapped = false;
}

SkewHeap::~SkewHeap()
{
  destroyTree(rootPtr);
}

void SkewHeap::buildHeap(std::string fileName)
{
  std::ifstream inFile;
  inFile.open(fileName);
  if (inFile.is_open())
  {
    int temp;
    bool success = true;
    while (inFile >> temp)
    {
      success = insert(temp);
      if (!success)
      {
        throw std::runtime_error("Heap building failed -> please remove duplicate/invalid elements from input file");
      }
    }
    inFile.close();
  }
}

bool SkewHeap::insert(int x)
{
  if (isPresent(x))
  {
    return false;
  }
  BinaryNode<int>* newNode = new BinaryNode<int>(x);
  rootPtr = merge(rootPtr, newNode);
  return true;
}

bool SkewHeap::remove(int x)
{
  BinaryNode<int>* targetParent = findElement(rootPtr, x);
  if (targetParent == nullptr)
  {
    return false;
  }
  if (targetParent == rootPtr && targetParent->getItem() == x)
  {
    rootPtr = merge(rootPtr->getLeftChildPtr(), rootPtr->getRightChildPtr());
    delete [] targetParent;
  }
  else if (targetParent->getLeftChildPtr()->getItem() == x)
  {
    BinaryNode<int>* target = targetParent->getLeftChildPtr();
    targetParent->setLeftChildPtr(merge(target->getLeftChildPtr(), target->getRightChildPtr()));
    delete [] target;
  }
  else
  {
    BinaryNode<int>* target = targetParent->getRightChildPtr();
    targetParent->setRightChildPtr(merge(target->getLeftChildPtr(), target->getRightChildPtr()));
    delete [] target;
  }
  return true;
}

BinaryNode<int>* SkewHeap::merge(BinaryNode<int> *heap1, BinaryNode<int> *heap2)
{
  if (heap1 == nullptr)
  {
    return heap2;
  }
  if (heap2 == nullptr)
  {
    return heap1;
  }
  if (heap1->getItem() > heap2->getItem())
  {
    BinaryNode<int>* tempNode = heap1;
    heap1 = heap2;
    heap2 = tempNode;
    tempNode = nullptr;
    swapped = true;
  }
  
  BinaryNode<int>* tempNode = heap1->getLeftChildPtr();
  heap1->setLeftChildPtr(heap1->getRightChildPtr());
  heap1->setRightChildPtr(tempNode);
  tempNode = nullptr;

  heap1->setLeftChildPtr(merge(heap2, heap1->getLeftChildPtr()));

  return heap1;
}

void SkewHeap::destroyTree(BinaryNode<int> *subTreePtr)
{
  if (subTreePtr != nullptr)
  {
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    delete subTreePtr;
  }
}

bool SkewHeap::isEmpty() const
{
  return (rootPtr == nullptr);
}

int SkewHeap::heightHelper(BinaryNode<int> *subTreePtr) const
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

void SkewHeap::printNode(int &x)
{
  std::cout << x << ' ';
}

void SkewHeap::preorder() const
{
  preorderHelper(printNode, rootPtr);
}

void SkewHeap::preorderHelper(void visit(int &), BinaryNode<int> *treePtr) const
{
  if (treePtr != nullptr)
  {
    int item = treePtr->getItem();
    visit(item);
    preorderHelper(visit, treePtr->getLeftChildPtr());
    preorderHelper(visit, treePtr->getRightChildPtr());
  }
}

void SkewHeap::postorder() const
{
  postorderHelper(printNode, rootPtr);
}

void SkewHeap::postorderHelper(void visit(int &), BinaryNode<int> *treePtr) const
{
  if (treePtr != nullptr)
  {
    postorderHelper(visit, treePtr->getLeftChildPtr());
    postorderHelper(visit, treePtr->getRightChildPtr());
    int item = treePtr->getItem();
    visit(item);
  }
}

void SkewHeap::inorder() const
{
  inorderHelper(printNode, rootPtr);
}

void SkewHeap::inorderHelper(void visit(int &), BinaryNode<int> *treePtr) const
{
  if (treePtr != nullptr)
  {
    inorderHelper(visit, treePtr->getLeftChildPtr());
    int item = treePtr->getItem();
    visit(item);
    inorderHelper(visit, treePtr->getRightChildPtr());
  }
}

void SkewHeap::levelorder() const
{
  int height = heightHelper(rootPtr);
  for (int i = 1; i <= height; i++)
  {
    printLevel(rootPtr, i);
  }
}

void SkewHeap::printLevel(BinaryNode<int> *subTreePtr, int level) const
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

bool SkewHeap::isSwapped()
{
  bool temp = swapped;
  swapped = false;
  return temp;
}

BinaryNode<int>* SkewHeap::findElement(BinaryNode<int>* curPtr, int x)
{
  if (curPtr == nullptr || curPtr->getItem() > x)
  {
    return nullptr;
  }
  else if (curPtr == rootPtr && curPtr->getItem() == x)
  {
    return curPtr;
  }
  bool leftSide = false;
  bool rightSide = false;
  if (curPtr->getLeftChildPtr() != nullptr && curPtr->getLeftChildPtr()->getItem() == x)
  {
    return curPtr;
  }
  if (curPtr->getRightChildPtr() != nullptr && curPtr->getRightChildPtr()->getItem() == x)
  {
    return curPtr;
  }
  if (findElement(curPtr->getLeftChildPtr(), x) != nullptr)
  {
    return findElement(curPtr->getLeftChildPtr(), x);
  }
  else
  {
    return findElement(curPtr->getRightChildPtr(), x);
  }
}

bool SkewHeap::isPresent(int x)
{
  if(findElement(rootPtr, x) == nullptr)
  {
    return false;
  }
  else 
  {
    return true;
  }
}

void SkewHeap::mergeToRoot(BinaryNode<int>* newHeap)
{
  rootPtr = merge(rootPtr, newHeap);
}