#include <iostream>
#include "BinaryNode.h"
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
  rootPtr = nullptr;
}

// TODO: Create a destructor

bool BinarySearchTree::isEmpty() const
{
  return (rootPtr == nullptr);
}

bool BinarySearchTree::isFull() const
{
  if (isEmpty())
  {
    return true;
  }
  else
  {
    return fullHelper(rootPtr);
  }
}

bool BinarySearchTree::fullHelper(BinaryNode<int>* subTreePtr) const
{
  if ((subTreePtr->getLeftChildPtr() == nullptr) && (subTreePtr->getRightChildPtr() == nullptr))
  {
    return true;
  }
  else if ((subTreePtr->getLeftChildPtr() != nullptr) && (subTreePtr->getRightChildPtr() != nullptr))
  {
    bool leftFull = fullHelper(subTreePtr->getLeftChildPtr());
    bool rightFull = fullHelper(subTreePtr->getRightChildPtr());
    return (leftFull && rightFull);
  }
  else
  {
    return false;
  }
}

bool BinarySearchTree::addItem(int x)
{
  if (rootPtr == nullptr)
  {
    rootPtr = new BinaryNode<int>(x);
    std::cout << x << " added as root\n";
    return true;
  }
  else
  {
    int height = heightHelper(rootPtr);
    std::cout << "height is " << height << '\n';
    bool success = addLevelOrder(rootPtr, x, height);
    if (success)
    {
      return true;
    }
    else
    {
      addFarLeft(rootPtr, x);
      return true;
    }
  }
}

bool BinarySearchTree::addLevelOrder(BinaryNode<int>* subTreePtr, int x, int level)
{
  if (level == 1)
  {
    if (subTreePtr->getLeftChildPtr() == nullptr)
    {
      BinaryNode<int>* tempPtr = new BinaryNode<int>(x);
      subTreePtr->setLeftChildPtr(tempPtr);
      tempPtr = nullptr;
      return true;
    }
    else if (subTreePtr->getRightChildPtr() == nullptr)
    {
      BinaryNode<int>* tempPtr = new BinaryNode<int>(x);
      subTreePtr->setRightChildPtr(tempPtr);
      tempPtr = nullptr;
      return true;
    }
    else
    {
      return false;
    }
  }
  if (level > 1)
  {
    if (addLevelOrder(subTreePtr->getLeftChildPtr(), x, level-1))
    {
      return true;
    }
    else if (addLevelOrder(subTreePtr->getRightChildPtr(), x, level-1))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}

void BinarySearchTree::addFarLeft(BinaryNode<int>* treePtr, int x)
{
  if (treePtr->getLeftChildPtr() == nullptr)
  {
    BinaryNode<int>* tempPtr = new BinaryNode<int>(x);
    treePtr->setLeftChildPtr(tempPtr);
    tempPtr = nullptr;
    return;
  }
  else
  {
    addFarLeft(treePtr->getLeftChildPtr(), x);
  }
}

int BinarySearchTree::remove()
{
  return 0;
}

bool BinarySearchTree::leaf(int x) const
{
  BinaryNode<int>* target = findNode(rootPtr, x);
  return ((target->getLeftChildPtr() == nullptr) && (target->getRightChildPtr() == nullptr));
}

BinaryNode<int>* BinarySearchTree::findNode(BinaryNode<int>* subTreePtr, int x) const
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
    BinaryNode<int>* temp = findNode(subTreePtr->getLeftChildPtr(), x);
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

void BinarySearchTree::leafPrinter(BinaryNode<int>* treePtr) const
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
  int height = heightHelper(rootPtr);
  std::cout << height;
}

int BinarySearchTree::heightHelper(BinaryNode<int>* subTreePtr) const
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

void BinarySearchTree::printNode(int& x)
{
  std::cout << x << ' ';
}

void BinarySearchTree::preorder() const
{
  preorderHelper(printNode, rootPtr);
}

void BinarySearchTree::preorderHelper(void visit(int&), BinaryNode<int>* treePtr) const
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

void BinarySearchTree::postorderHelper(void visit(int&), BinaryNode<int>* treePtr) const
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

void BinarySearchTree::inorderHelper(void visit(int&), BinaryNode<int>* treePtr) const
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

void BinarySearchTree::printLevel(BinaryNode<int>* subTreePtr, int level) const
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
    printLevel(subTreePtr->getLeftChildPtr(), level-1);
    printLevel(subTreePtr->getRightChildPtr(), level-1);
  }
}
