/*******************************************************************************
*@author  Evan Trout
*@file    LeftistHeap.cpp
*@date    09/25/19
*@brief   Implementation file for LeftistHeap class, which controls a tree of linked
*         BinaryNodes and allows for various operations on them.
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "BinaryNode.h"
#include "LeftistHeap.h"

LeftistHeap::LeftistHeap()
{
  rootPtr = nullptr;
}

LeftistHeap::~LeftistHeap()
{
  destroyTree(rootPtr);
}

void LeftistHeap::buildHeap(std::string fileName)
{
  std::ifstream inFile;
  inFile.open(fileName);
  if (inFile.is_open())
  {
    int temp;
    while (inFile >> temp)
    {
      insert(temp);
    }
    inFile.close();
  }
}

void LeftistHeap::insert(int x)
{
  BinaryNode<int>* newNode = new BinaryNode<int>(x);
  rootPtr = merge(rootPtr, newNode);
}

int LeftistHeap::deleteMin()
{
  int x = rootPtr->getItem();
  rootPtr = merge(rootPtr->getLeftChildPtr(), rootPtr->getRightChildPtr());
  return x;
}

BinaryNode<int>* LeftistHeap::merge(BinaryNode<int> *heap1, BinaryNode<int> *heap2)
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
  }
  heap1->setRightChildPtr(merge(heap1->getRightChildPtr(), heap2));

  if (heap1->getLeftChildPtr() == nullptr)
  {
    heap1->setLeftChildPtr(heap1->getRightChildPtr());
    heap1->setRightChildPtr(nullptr);
  }
  else 
  {
    if (heap1->getLeftChildPtr()->getRank() < heap1->getRightChildPtr()->getRank())
    {
      BinaryNode<int>* tempNode = heap1->getLeftChildPtr();
      heap1->setLeftChildPtr(heap1->getRightChildPtr());
      heap1->setRightChildPtr(tempNode);
      tempNode = nullptr;
    }
    heap1->setRank(heap1->getRightChildPtr()->getRank() + 1);
  }
  return heap1;
}

void LeftistHeap::destroyTree(BinaryNode<int> *subTreePtr)
{
  if (subTreePtr != nullptr)
  {
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    delete subTreePtr;
  }
}

bool LeftistHeap::isEmpty() const
{
  return (rootPtr == nullptr);
}

int LeftistHeap::heightHelper(BinaryNode<int> *subTreePtr) const
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

void LeftistHeap::printNode(char &x)
{
  std::cout << x << ' ';
}

void LeftistHeap::preorder() const
{
  preorderHelper(printNode, rootPtr);
}

void LeftistHeap::preorderHelper(void visit(char &), BinaryNode<int> *treePtr) const
{
  if (treePtr != nullptr)
  {
    char item = treePtr->getItem();
    visit(item);
    preorderHelper(visit, treePtr->getLeftChildPtr());
    preorderHelper(visit, treePtr->getRightChildPtr());
  }
}

void LeftistHeap::postorder() const
{
  postorderHelper(printNode, rootPtr);
}

void LeftistHeap::postorderHelper(void visit(char &), BinaryNode<int> *treePtr) const
{
  if (treePtr != nullptr)
  {
    postorderHelper(visit, treePtr->getLeftChildPtr());
    postorderHelper(visit, treePtr->getRightChildPtr());
    char item = treePtr->getItem();
    visit(item);
  }
}

void LeftistHeap::inorder() const
{
  inorderHelper(printNode, rootPtr);
}

void LeftistHeap::inorderHelper(void visit(char &), BinaryNode<int> *treePtr) const
{
  if (treePtr != nullptr)
  {
    inorderHelper(visit, treePtr->getLeftChildPtr());
    char item = treePtr->getItem();
    visit(item);
    inorderHelper(visit, treePtr->getRightChildPtr());
  }
}

void LeftistHeap::levelorder() const
{
  int height = heightHelper(rootPtr);
  for (int i = 1; i <= height; i++)
  {
    printLevel(rootPtr, i);
  }
}

void LeftistHeap::printLevel(BinaryNode<int> *subTreePtr, int level) const
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