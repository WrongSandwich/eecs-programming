#include "BinomialHeap.h"
#include "BinomialNode.h"

BinomialHeap::BinomialHeap()
{
  headPtr = nullptr;
}

bool BinomialHeap::insert(int x)
{

}

void BinomialHeap::merge(BinomialNode* heap1, BinomialNode* heap2)
{

}

BinomialNode* BinomialHeap::findMin()
{
  BinomialNode* curPtr = headPtr;
  int minPtr = curPtr;
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
  }
  return minPtr;
}
