#include "BinomialTree.h"
#include "BinomialNode.h"
#include <stdexcept>

BinomialTree::BinomialTree(BinomialNode* newHead)
{
    headPtr = newHead;
    order = 0;
}

void BinomialTree::mergeTree(BinomialTree* target)
{
    if (target->getOrder() != order || target->getHeadPtr()->getKey() > headPtr->getKey())
    {
        throw std::runtime_error("Tried to merge trees incorrectly");
    }

    BinomialNode* targetHead = target->getHeadPtr();
    BinomialNode* tail = headPtr->getLeft();
    tail->setRight(targetHead);
    headPtr->setLeft(targetHead);
    order++;
}

BinomialNode* BinomialTree::getFirstChild()
{
    return headPtr->getFirst();   
}

void BinomialTree::setHeadPtr(BinomialNode* newHead)
{
    headPtr = newHead;
}

void BinomialTree::setOrder(int newOrder)
{
    order = newOrder;
}

BinomialNode* BinomialTree::getHeadPtr()
{
    return headPtr;
}

int BinomialTree::getOrder()
{
    return order;
}