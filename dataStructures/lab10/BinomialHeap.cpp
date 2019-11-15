#include "BinomialHeap.h"
#include "BinomialNode.h"

BinomialHeap::BinomialHeap()
{
  headPtr = nullptr;
}

bool BinomialHeap::insert(int x)
{

}

void BinomialHeap::mergeTrees(BinomialNode* tree1, BinomialNode* tree2)
{
  if (tree1->getKey() > tree2->getKey())
  {
    BinomialNode* temp = tree1;
    tree1 = tree2;
    tree2 = temp;
  }
  tree1->addChild(tree2);
}

void BinomialHeap::mergeHeaps(BinomialHeap* heap1, BinomialHeap* heap2)
{
  BinomialNode* headPtr1 = heap1->getHeadPtr();
  BinomialNode* headPtr2 = heap2->getHeadPtr();
}

BinomialNode* BinomialHeap::findMin()
{
  BinomialNode* curPtr = headPtr;
  BinomialNode* minPtr = curPtr;
  int min = minPtr->getKey();
  int loop = min;
  curPtr = curPtr->getRight();
  while (curPtr->getKey() != loop)
  {
    if (curPtr->getKey() < min)
    {
      minPtr = curPtr;
      min = minPtr->getKey();
    }
    curPtr = curPtr->getRight();
  }
  return minPtr;
}

BinomialNode* BinomialHeap::getHeadPtr()
{
  return headPtr;
}
