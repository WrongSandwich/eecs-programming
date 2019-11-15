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
  BinomialTree* headPtr1 = heap1->getHeadPtr();
  BinomialTree* headPtr2 = heap2->getHeadPtr();
  if (headPtr1 == nullptr)
  {
    headPtr = headPtr2;
  }
  else if (headPtr2 == nullptr)
  {
    headPtr = headPtr1;
  }
  else 
  {
    BinomialTree* cur1 = headPtr1;
    BinomialTree* cur2 = headPtr2;
    do 
    {
      
    } while (cur1 != headPtr1 && cur2 != headPtr2);
  }
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

BinomialTree* BinomialHeap::getHeadPtr()
{
  return headPtr;
}
