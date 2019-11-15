#ifndef BINOMIAL_NODE_H
#define BINOMIAL_NODE_H

class BinomialNode
{
private:
  int order;
  int key;
  BinomialNode* parent;
  BinomialNode* sibling;
  BinomialNode* child;
public:
  BinomialNode(int newKey);
  void setKey(int newKey);
  void setOrder(int newOrder);
  void setParent(BinomialNode* newParent);
  void setSibling(BinomialNode* newSibling);
  void setChild(BinomialNode* newChild);
  int getKey() const;
  int getOrder() const;
  BinomialNode* getParent() const;
  BinomialNode* getSibling() const;
  BinomialNode* getChild() const;
};

#endif
