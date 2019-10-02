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
  BinaryNode<char>* rootPtr;
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
  void destroyTree(BinaryNode<char>* subTreePtr);

  /**
  * @return boolean of whether or not tree is empty
  **/
  bool isEmpty() const;

  bool addItem(char x);

  bool recursiveAdd(BinaryNode<char>* subTreePtr, char x);

  bool remove(char x); // need to keep parent and child nodes tracked here
  // actually jk that's in a sub function

  bool recursiveDelete(BinaryNode<char>* parentPtr, BinaryNode<char>* childPtr, char x);

  char deleteMin(BinaryNode<char>* subTreePtr);

  /**
  * @param x: char being searched for and checked
  * @return true if found node is leaf, otherwise false
  **/
  bool leaf(char x) const;

  /**
  * @pre is called by another BinarySearchTree function
  * @param subTreePtr: current node
  * @param x: char being searched for
  * @return pointer to found node, otherwise nullptr
  **/
  BinaryNode<char>* findNode(BinaryNode<char>* subTreePtr, char x) const;

  /**
  * @post calls leafPrinter on rootPtr
  **/
  void printLeaf() const;

  /**
  * @pre is called by itself or printLeaf
  * @post recursively prints all leafs
  * @param treePtr: current node
  **/
  void leafPrinter(BinaryNode<char>* treePtr) const;

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
  int heightHelper(BinaryNode<char>* subTreePtr) const;

  /**
  * @pre called in a traversal
  * @post prints the value of x
  * @param x: value to be printed
  **/
  static void printNode(char& x);

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
  void preorderHelper(void visit(char&), BinaryNode<char>* treePtr) const;

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
  void postorderHelper(void visit(char&), BinaryNode<char>* treePtr) const;

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
  void inorderHelper(void visit(char&), BinaryNode<char>* treePtr) const;

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
  void printLevel(BinaryNode<char>* subTreePtr, int level) const;

  bool searchElement(char x) const;
};

#endif
