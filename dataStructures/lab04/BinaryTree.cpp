#include <iostream>
#include "BinaryNode.h"
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
  rootPtr = nullptr;
}

// TODO: Create a destructor

bool BinaryTree::isEmpty() const
{
  return (rootPtr == nullptr);
}

bool BinaryTree::isFull() const
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

bool BinaryTree::fullHelper(BinaryNode<int> *subTreePtr) const
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

bool BinaryTree::addItem(int x)
{
  if (rootPtr == nullptr)
  {
    rootPtr = new BinaryNode<int>(x);
    std::cout << x << " added as root\n";
    return true;
  }
  else if (findNode(rootPtr, x) != nullptr)
  {
    return false;
  }
  else
  {
    bool success = false;
    int level = 0;
    while (!success)
    {
      level++;
      success = addLevelOrder(rootPtr, x, level);
    }
  }
}

bool BinaryTree::addLevelOrder(BinaryNode<int> *subTreePtr, int x, int level)
{
  if (level == 1)
  {
    if (subTreePtr->getLeftChildPtr() == nullptr)
    {
      BinaryNode<int> *tempPtr = new BinaryNode<int>(x);
      subTreePtr->setLeftChildPtr(tempPtr);
      tempPtr = nullptr;
      return true;
    }
    else if (subTreePtr->getRightChildPtr() == nullptr)
    {
      BinaryNode<int> *tempPtr = new BinaryNode<int>(x);
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
    if (addLevelOrder(subTreePtr->getLeftChildPtr(), x, level - 1))
    {
      return true;
    }
    else if (addLevelOrder(subTreePtr->getRightChildPtr(), x, level - 1))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}

int BinaryTree::remove()
{
  int level = heightHelper(rootPtr) - 1;
  if (level == 0)
  {
    return -1;
  }
  return removeHelper(rootPtr, level);
}

int BinaryTree::removeHelper(BinaryNode<int>* subTreePtr, int level)
{
  if (level == 1)
  {
    if (subTreePtr->getRightChildPtr() != nullptr)
    {
      BinaryNode<int>* tempPtr = subTreePtr->getRightChildPtr();
      int target = tempPtr->getItem();
      delete [] tempPtr;
      subTreePtr->setRightChildPtr(nullptr);
      tempPtr = nullptr;
      return target;
    }
    else if (subTreePtr->getLeftChildPtr() != nullptr)
    {
      BinaryNode<int>* tempPtr = subTreePtr->getLeftChildPtr();
      int target = tempPtr->getItem();
      delete [] tempPtr;
      subTreePtr->setLeftChildPtr(nullptr);
      tempPtr = nullptr;
      return target;
    }
    else
    {
      return -1;
    }
  }
  if (level > 1)
  {
    int result = removeHelper(subTreePtr->getRightChildPtr(), level - 1);
    if (result != -1)
    {
      return result;
    }
    result = removeHelper(subTreePtr->getLeftChildPtr(), level - 1);
    if (result != -1)
    {
      return result;
    }
    return -1;
  }
}

bool BinaryTree::leaf(int x) const
{
  BinaryNode<int> *target = findNode(rootPtr, x);
  return ((target->getLeftChildPtr() == nullptr) && (target->getRightChildPtr() == nullptr));
}

BinaryNode<int> *BinaryTree::findNode(BinaryNode<int> *subTreePtr, int x) const
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
    BinaryNode<int> *temp = findNode(subTreePtr->getLeftChildPtr(), x);
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

void BinaryTree::printLeaf() const
{
  leafPrinter(rootPtr);
}

void BinaryTree::leafPrinter(BinaryNode<int> *treePtr) const
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

void BinaryTree::printTreeHeight() const
{
  int height = heightHelper(rootPtr) - 1;
  std::cout << height;
}

int BinaryTree::heightHelper(BinaryNode<int> *subTreePtr) const
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

void BinaryTree::printNode(int &x)
{
  std::cout << x << ' ';
}

void BinaryTree::preorder() const
{
  preorderHelper(printNode, rootPtr);
}

void BinaryTree::preorderHelper(void visit(int &), BinaryNode<int> *treePtr) const
{
  if (treePtr != nullptr)
  {
    int item = treePtr->getItem();
    visit(item);
    preorderHelper(visit, treePtr->getLeftChildPtr());
    preorderHelper(visit, treePtr->getRightChildPtr());
  }
}

void BinaryTree::postorder() const
{
  postorderHelper(printNode, rootPtr);
}

void BinaryTree::postorderHelper(void visit(int &), BinaryNode<int> *treePtr) const
{
  if (treePtr != nullptr)
  {
    postorderHelper(visit, treePtr->getLeftChildPtr());
    postorderHelper(visit, treePtr->getRightChildPtr());
    int item = treePtr->getItem();
    visit(item);
  }
}

void BinaryTree::inorder() const
{
  inorderHelper(printNode, rootPtr);
}

void BinaryTree::inorderHelper(void visit(int &), BinaryNode<int> *treePtr) const
{
  if (treePtr != nullptr)
  {
    inorderHelper(visit, treePtr->getLeftChildPtr());
    int item = treePtr->getItem();
    visit(item);
    inorderHelper(visit, treePtr->getRightChildPtr());
  }
}

void BinaryTree::levelorder() const
{
  int height = heightHelper(rootPtr);
  for (int i = 1; i <= height; i++)
  {
    printLevel(rootPtr, i);
  }
}

void BinaryTree::printLevel(BinaryNode<int> *subTreePtr, int level) const
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
