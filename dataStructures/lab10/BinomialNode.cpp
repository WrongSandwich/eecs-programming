#include "BinomialNode.h"

BinomialNode::BinomialNode(int newKey)
{
  key = newKey;
  order = 0;
  parent = nullptr;
  sibling = nullptr;
  child = nullptr;
}

void BinomialNode::setKey(int newKey)
{
  key = newKey;
}

void BinomialNode::setOrder(int newOrder)
{
  order = newOrder;
}

void BinomialNode::setParent(BinomialNode* newParent)
{
  parent = newParent;
}

void BinomialNode::setSibling(BinomialNode* newSibling)
{
  sibling = newSibling;
}

void BinomialNode::setChild(BinomialNode* newChild)
{
  child = newChild;
}

int BinomialNode::getKey() const 
{
  return key;
}

int BinomialNode::getOrder() const 
{
  return order;
}

BinomialNode* BinomialNode::getParent() const
{
  return parent;
}

BinomialNode* BinomialNode::getSibling() const
{
  return sibling;
}

BinomialNode* BinomialNode::getChild() const
{
  return child;
}