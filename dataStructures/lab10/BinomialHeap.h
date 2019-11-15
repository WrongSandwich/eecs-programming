#ifndef BINOMIAL_HEAP_H
#define BINOMIAL_HEAP_H

#include "BinomialNode.h"

class BinomialHeap
{
private:
  BinomialNode* headPtr;
public:
  BinomialHeap();
  void link(BinomialNode* tree1, BinomialNode* tree2);
  BinomialNode* findMin();
  void insert(int x);
  void merge(BinomialHeap H);
  void extractMin();
  void printLevelOrder();
  void printTree(BinomialNode* curPtr);
  bool printAtDepth(BinomialNode* curPtr, int depth);
  void setHead(BinomialNode* newHead);
  BinomialNode* getHead();
};

#endif
