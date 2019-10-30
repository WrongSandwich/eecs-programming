/*******************************************************************************
*@author  Evan Trout
*@file    LeftistHeap.h
*@date    09/25/19
*@brief   Header file for LeftistHeap class, which controls a tree of linked
*         BinaryNodes and allows for various operations on them.
*******************************************************************************/

#ifndef LEFTIST_HEAP
#define LEFTIST_HEAP

#include "BinaryNode.h"
#include <string>

class LeftistHeap {
private:
  BinaryNode<int>* rootPtr;
  bool swapped;
public:
  /**
  * @pre constructor is called
  * @return initalized LeftistHeap
  **/
  LeftistHeap();

  /**
  * @pre Destructor is called
  * @post Calls destroyTree on rootPtr
  **/
  ~LeftistHeap();

  void buildHeap(std::string fileName);

  bool insert(int x);

  int deleteMin();

  int findMin();

  BinaryNode<int>* merge(BinaryNode<int>* heap1, BinaryNode<int>* heap2);

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

  int heightHelper(BinaryNode<int> *subTreePtr) const;

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
  void preorderHelper(void visit(char&), BinaryNode<int>* treePtr) const;

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
  void postorderHelper(void visit(char&), BinaryNode<int>* treePtr) const;

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
  void inorderHelper(void visit(char&), BinaryNode<int>* treePtr) const;

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

  bool isSwapped();

  bool isDuplicate(BinaryNode<int>* curPtr, int x);
};

#endif
