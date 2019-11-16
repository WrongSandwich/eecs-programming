#include "BinomialHeap.h"
#include "BinomialNode.h"
#include <iostream>

BinomialHeap::BinomialHeap()
{
  headPtr = nullptr;
}

void BinomialHeap::link(BinomialNode* tree1, BinomialNode* tree2)
{
  tree2->setSibling(tree1->getChild());
  tree1->setChild(tree2);
  int temp = tree1->getOrder();
  tree1->setOrder(temp + 1);
}

void BinomialHeap::insert(int x)
{
  BinomialHeap tempHeap;
  BinomialNode* tempNode = new BinomialNode(x);
  tempHeap.setHead(tempNode);
  merge(tempHeap);
}

void BinomialHeap::merge(BinomialHeap H)
{
  BinomialNode* x = getHead();
  BinomialNode* y = H.getHead();
  BinomialNode* z = nullptr;
  BinomialNode* temp = nullptr;

  if (x == nullptr)
  {
    headPtr = y;
    return;
  }

  if (x->getOrder() <= y->getOrder())
  {
    z = x;
    x = x->getSibling();
  }
  else
  {
    z = y;
    y = y->getSibling();
  }

  temp = z;

  //load the new heap in order of degree
  while (x != nullptr && y != nullptr)
  {
    if (x->getOrder() <= y->getOrder())
    {
      z->setSibling(x);
      x = x->getSibling();
    }
    else 
    {
      z->setSibling(y);
      y = y->getSibling();
    }
    z = z->getSibling();
  }

  //clean up any left over trees
  while (x != nullptr)
  {
    z->setSibling(x);
    x = x->getSibling();
    z = z->getSibling();
  }

  while (y != nullptr)
  {
    z->setSibling(y);
    y = y->getSibling();
    z = z->getSibling();
  }

  //merge trees with same degree
  z = temp;
  BinomialNode* prev = nullptr;
  BinomialNode* next = z->getSibling();

  while (next != nullptr)
  {
    if ((z->getOrder() != next->getOrder()) || (next->getSibling() != nullptr && z->getOrder() == next->getSibling()->getOrder()))
    {
      prev = z;
      z = next;
    }
    else
    {
      if (z->getKey() <= next->getKey())
      {
        z->setSibling(next->getSibling());
        link(z, next);
      }
      else 
      {
        if (prev == nullptr)
        {
          temp = next;
        }
        else 
        {
          prev->setSibling(next);
        }
        link(next, z);
        z = next;
      }
    }
    next = z->getSibling();
  }
  setHead(temp);
}

void BinomialHeap::extractMin() {
  BinomialNode* cur = headPtr;
  BinomialNode* prevMin = nullptr;
  BinomialNode* minPtr = nullptr;
  BinomialNode* prevPtr = nullptr;
  if (cur == nullptr)
  {
    return;
  }
  int min = cur->getKey();
  while (cur != nullptr)
  {
    if (cur->getKey() <= min)
    {
      min = cur->getKey();
      prevMin = prevPtr;
      minPtr = cur;
    }
    prevPtr = cur;
    cur = cur->getSibling();
  }

  if (prevMin != nullptr && minPtr->getSibling() != nullptr)
  {
    prevMin->setSibling(minPtr->getSibling());
  }
  else if (prevMin != nullptr && minPtr->getSibling() == nullptr)
  {
    prevMin->setSibling(nullptr);
  }

  BinomialNode* child = minPtr->getChild();
  BinomialNode* temp = child;
  // while (child != nullptr)
  // {
  //   child->setParent(nullptr);
  //   child = child->getSibling();
  // }

  BinomialHeap tempHeap;
  tempHeap.setHead(temp);
  merge(tempHeap);
}

void BinomialHeap::printLevelOrder()
{
  BinomialNode* cur = headPtr;
  while (cur != nullptr)
  {
    printTree(cur);
    std::cout << "---\n";
    cur = cur->getSibling();
  }
}

void BinomialHeap::printTree(BinomialNode* curPtr)
{
  std::cout << curPtr->getKey() << "\n";
  bool success = true;
  int depth = 0;
  while (success)
  {
    success = printAtDepth(curPtr->getChild(), depth);
    std::cout << "\n";
    depth++;
  }
}

bool BinomialHeap::printAtDepth(BinomialNode* curPtr, int depth)
{
  if (curPtr == nullptr)
  {
    return false;
  }
  if (depth == 0)
  {
    // std::cout << curPtr->getKey() << " ";
    // printAtDepth(curPtr->getSibling(), depth);
    printSiblings(curPtr);
    return true;
  }
  else
  {
    bool a, b;
    a = printAtDepth(curPtr->getChild(), depth - 1);
    b = printAtDepth(curPtr->getSibling(), depth);
    return (a || b);
  }
}

void BinomialHeap::printSiblings(BinomialNode* curPtr)
{
  if (curPtr)
  {
    printSiblings(curPtr->getSibling());
    std::cout << curPtr->getKey() << " ";
  }
}

void BinomialHeap::setHead(BinomialNode* newHead)
{
  headPtr = newHead;
}

BinomialNode* BinomialHeap::getHead()
{
  return headPtr;
}