#ifndef BINOMIAL_TREE_H
#define BINOMIAL_TREE_H

#include "BinomialNode.h"

class BinomialTree
{
private:
    BinomialNode* headPtr;
    int order;
public:
    BinomialTree(BinomialNode* newHead);
    void mergeTree(BinomialTree* target);
    BinomialNode* getFirstChild();
    void setHeadPtr(BinomialNode* newHead);
    void setOrder(int newOrder);
    BinomialNode* getHeadPtr();
    int getOrder();
};

#endif