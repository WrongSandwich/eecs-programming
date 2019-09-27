#ifndef _BINARY_TREE
#define _BINARY_TREE

#include "BinaryNode.h"

class BinaryTree {
private:
  BinaryNode<int>* rootPtr;
public:
  BinaryTree();
  ~BinaryTree();
  void destroyTree(BinaryNode<int>* subTreePtr);
  bool isEmpty() const;
  bool isFull() const;
  bool fullHelper(BinaryNode<int>* subTreePtr) const;
  bool addItem(int x);
  bool addLevelOrder(BinaryNode<int>* subTreePtr, int x, int level);
  int remove();
  int removeHelper(BinaryNode<int>* subTreePtr, int level);
  bool leaf(int x) const;
  BinaryNode<int>* findNode(BinaryNode<int>* subTreePtr, int x) const;
  void printLeaf() const;
  void leafPrinter(BinaryNode<int>* treePtr) const;
  void printTreeHeight() const;
  int heightHelper(BinaryNode<int>* subTreePtr) const;
  static void printNode(int& x);
  void preorder() const;
  void preorderHelper(void visit(int&), BinaryNode<int>* treePtr) const;
  void postorder() const;
  void postorderHelper(void visit(int&), BinaryNode<int>* treePtr) const;
  void inorder() const;
  void inorderHelper(void visit(int&), BinaryNode<int>* treePtr) const;
  void levelorder() const;
  void printLevel(BinaryNode<int>* subTreePtr, int level) const;
};

#endif