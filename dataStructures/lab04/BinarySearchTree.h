#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryNode.h"

class BinarySearchTree {
private:
  BinaryNode<int>* rootPtr;
public:
  BinarySearchTree();
  bool isEmpty() const;
  bool isFull() const;
  bool addItem(int x);
  int delete();
  bool leaf(int x) const;
  void printLeaf() const;
  void printTreeHeight() const;
  void preorder() const;
  void postorder() const;
  void inorder() const;
  void levelorder() const;
};

#endif;
