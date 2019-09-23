#include <iostream>
#include "BinaryNode.h"
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
  rootPtr = nullptr;
}

// TODO: Create a constructor

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

bool BinarySearchTree::fullHelper(BinaryNode<int>* subTreePtr)
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

}

int BinarySearchTree::delete()
{

}

bool BinarySearchTree::leaf(int x) const
{
  BinaryNode<int>* target = findNode(x);
  return ((target->getLeftChildPtr() == nullptr) && (target->getRightChildPtr() == nullptr));
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

int BinarySearchTree::heightHelper(BinaryNode<int>* subTreePtr)
{
  if (subTreePtr == nullptr)
  {
    return 0;
  }
  else
  {
    return (1 + max(heightHelper(subTreePtr->getLeftChildPtr()), heightHelper(subTreePtr->getRightChildPtr())));
  }
}

static void BinarySearchTree::printNode(int x)
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

}
