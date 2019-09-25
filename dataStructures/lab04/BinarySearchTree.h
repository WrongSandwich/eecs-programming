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
  bool fullHelper(BinaryNode<int>* subTreePtr);
  bool addItem(int x);
  bool addLevelOrder(BinaryNode<int>* subTreePtr, int x, int level);
  int remove();
  bool leaf(int x) const;
  void printLeaf() const;
  void leafPrinter(BinaryNode<int>* treePtr) const;
  void printTreeHeight() const;
  int heightHelper(BinaryNode<int>* subTreePtr) const;
  static void printNode(int x);
  void preorder() const;
  void preorderHelper(void visit(int&), BinaryNode<int>* treePtr) const;
  void postorder() const;
  void postorderHelper(void visit(int&), BinaryNode<int>* treePtr) const;
  void inorder() const;
  void inorderHelper(void visit(int&), BinaryNode<int>* treePtr) const;
  void levelorder() const;
  void printLevel(BinaryNode<int>* subTreePtr, int level) const;
};

#endif;
