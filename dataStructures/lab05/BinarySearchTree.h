/*******************************************************************************
*@author  Evan Trout
*@file    BinarySearchTree.h
*@date    09/25/19
*@brief   Header file for BinarySearchTree class, which controls a tree of linked
*         BinaryNodes and allows for various operations on them.
*******************************************************************************/

#ifndef _BINARY_TREE
#define _BINARY_TREE

#include "BinaryNode.h"

class BinarySearchTree {
private:
  BinaryNode<int>* rootPtr;
public:
  /**
  * @pre constructor is called
  * @return initalized BinarySearchTree
  **/
  BinarySearchTree();

  /**
  * @pre Destructor is called
  * @post Calls destroyTree on rootPtr
  **/
  ~BinarySearchTree();

  /**
  * @pre called by destructor
  * @post Recursively deletes all nodes
  * @param subTreePtr: node to delete
  **/
  void destroyTree(BinaryNode<int>* subTreePtr);

  /**
  * @return boolean of whether or not tree is empty
  **/
  bool isEmpty() const;

  /**
  * @post uses fullHelper to determine whether or not tree is ful
  * @return boolean of whether or not tree is full
  **/
  bool isFull() const;

  /**
  * @pre is called by isFull function or by itself
  * @post recursively determines if tree is full
  * @param subTreePtr: node that function is currently checking
  * @return boolean of whether or not tree is full
  **/
  bool fullHelper(BinaryNode<int>* subTreePtr) const;

  /**
  * @post adds item to tree, sometimes by calling addLevelOrder
  * @param x: integer being added to tree
  * @return boolean of whether or not item was added
  **/
  bool addItem(int x);

  /**
  * @pre is called by itself or by addItem with appropriate params
  * @post recursively finds next level-order location and adds node
  * @param subTreePtr: current node
  * @param x: new integer to be added to tree
  * @param level: level tracker to ensure node is added to bottom level
  * @return true if successful, false if not
  **/
  bool addLevelOrder(BinaryNode<int>* subTreePtr, int x, int level);

  /**
  * @post checks if a node can be removed, if it can then calls removeHelper
  * @return -1 if no remove, otherwise int value of removed node
  **/
  int remove();

  /**
  * @pre is called by remove
  * @post recursively finds the last levelorder node and removes it
  * @param subTreePtr: current node
  * @param level: current level, needed to ensure remove takes place on last level
  * @return int value of removed node
  **/
  int removeHelper(BinaryNode<int>* subTreePtr, int level);

  /**
  * @param x: int being searched for and checked
  * @return true if found node is leaf, otherwise false
  **/
  bool leaf(int x) const;

  /**
  * @pre is called by another BinarySearchTree function
  * @param subTreePtr: current node
  * @param x: integer being searched for
  * @return pointer to found node, otherwise nullptr
  **/
  BinaryNode<int>* findNode(BinaryNode<int>* subTreePtr, int x) const;

  /**
  * @post calls leafPrinter on rootPtr
  **/
  void printLeaf() const;

  /**
  * @pre is called by itself or printLeaf
  * @post recursively prints all leafs
  * @param treePtr: current node
  **/
  void leafPrinter(BinaryNode<int>* treePtr) const;

  /**
  * @post gets height from heightHelper and prints it
  **/
  void printTreeHeight() const;

  /**
  * @pre called by another member function or itself
  * @post recursively determines height of the tree
  * @param subTreePtr: current node
  * @return the height of the tree
  **/
  int heightHelper(BinaryNode<int>* subTreePtr) const;

  /**
  * @pre called in a traversal
  * @post prints the value of x
  * @param x: value to be printed
  **/
  static void printNode(int& x);

  /**
  * @post calls preorderHelper and passes printNode function and rootPtr
  **/
  void preorder() const;

  /**
  * @pre called by itself or preorder
  * @post recursively prints values in preorder
  * @param visit: function that will be run on the node
  * @param treePtr: current node
  **/
  void preorderHelper(void visit(int&), BinaryNode<int>* treePtr) const;

  /**
  * @post calls postorderHelper and passes printNode function and rootPtr
  **/
  void postorder() const;

  /**
  * @pre called by itself or postorder
  * @post recursively prints values in postorder
  * @param visit: function that will be run on the node
  * @param treePtr: current node
  **/
  void postorderHelper(void visit(int&), BinaryNode<int>* treePtr) const;

  /**
  * @post calls inorderHelper and passes printNode function and rootPtr
  **/
  void inorder() const;

  /**
  * @pre called by itself or inorder
  * @post recursively prints values in inorder
  * @param visit: function that will be run on the node
  * @param treePtr: current node
  **/
  void inorderHelper(void visit(int&), BinaryNode<int>* treePtr) const;

  /**
  * @post calls levelorderHelper and passes printNode function and rootPtr
  **/
  void levelorder() const;

  /**
  * @pre called by levelorder or by itself
  * @post recursively prints the nodes in levelorder
  * @param subTreePtr: current node
  * @param level: current level
  **/
  void printLevel(BinaryNode<int>* subTreePtr, int level) const;
};

#endif
