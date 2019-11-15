#ifndef BINOMIAL_NODE_H
#define BINOMIAL_NODE_H

class BinomialNode
{
private:
  int order;
  int key;
  BinomialNode* left;
  BinomialNode* sibling;
  BinomialNode* child;
public:
  BinomialNode(int newKey);
  void setKey(int newKey);
  void setOrder(int newOrder);
  void setLeft(BinomialNode* newLeft);
  void setSibling(BinomialNode* newSibling);
  void setChild(BinomialNode* newChild);
  int getKey() const;
  int getOrder() const;
  BinomialNode* getLeft() const;
  BinomialNode* getSibling() const;
  BinomialNode* getChild() const;
};

#endif
