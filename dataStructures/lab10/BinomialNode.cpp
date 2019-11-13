#include "BinomialNode.h"

BinomialNode::BinomialNode(const int& newKey)
{
  leftSibling = nullptr;
  rightSibling = nullptr;
  firstChild = nullptr;
  key = newKey;
  order = 0;
}

void BinomialNode::setKey(const int& newKey)
{
  key = newKey;
}

void BinomialNode::setOrder(const int& newOrder)
{
  order = newOrder;
}

void BinomialNode::setLeft(BinomialNode* left)
{
  leftSibling = left;
}

void BinomialNode::setRight(BinomialNode* right)
{
  rightSibling = right;
}

void BinomialNode::setFirst(BinomialNode* child)
{
  firstChild = child;
}

int BinomialNode::getKey() const
{
  return key;
}

int BinomialNode::getOrder() const
{
  return order;
}

BinomialNode* BinomialNode::getRight() const
{
  return rightSibling;
}

BinomialNode* BinomialNode::getFirst() const
{
  return firstChild;
}