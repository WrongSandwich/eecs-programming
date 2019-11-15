#ifndef BINOMIAL_NODE_H
#define BINOMIAL_NODE_H

class BinomialNode
{
private:
  int order;
  int key;
  BinomialNode* leftSibling;
  BinomialNode* rightSibling;
  BinomialNode* firstChild;
public:
  BinomialNode(const int& newKey);
  void setKey(const int& newKey);
  void setOrder(const int& newOrder);
  void setLeft(BinomialNode* left);
  void setRight(BinomialNode* right);
  void setFirst(BinomialNode* child);
  int getKey() const;
  int getOrder() const;
  BinomialNode* getLeft() const;
  BinomialNode* getRight() const;
  BinomialNode* getFirst() const;
};

#endif
