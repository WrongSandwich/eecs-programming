#include "BinomialNode.h"

BinomialNode::BinomialNode()
{
  leftSibling = nullptr;
  rightSibling = nullptr;
  firstChild = nullptr;
  key = 0;
  order = 0;
}

BinomialNode::BinomialNode(const int& key)
{
  leftSibling = nullptr;
  rightSibling = nullptr;
  firstChild = nullptr;
  key = key;
  order = 0;
}

BinomialNode::BinomialNode(const int& key, const int& order, BinomialNode* leftSibling, BinomialNode* rightSibling)
{
  key = key;
  order = order;
  leftSibling = leftSibling;
  rightSibling = rightSibling;
  firstChild = nullptr;
}

void BinomialNode::setKey(const int& key)
{
  key = key;
}

void BinomialNode::setOrder(const int& order)
{
  order = order;
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
