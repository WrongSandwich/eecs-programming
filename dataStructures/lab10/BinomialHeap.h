#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H

#include "BinomialNode.h"
#include "BinomialTree.h"

class BinomialHeap
{
private:
  BinomialTree* headPtr;
public:
  BinomialHeap();
  bool insert(int x);
  void mergeTrees(BinomialNode* tree1, BinomialNode* tree2);
  void mergeHeaps(BinomialHeap* heap1, BinomialHeap* heap2);
  void deleteMin();
  void levelorder();
  BinomialNode* findMin();
  BinomialTree* getHeadPtr();
};

#endif
