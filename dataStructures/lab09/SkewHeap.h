/*******************************************************************************
*@author  Evan Trout
*@file    SkewHeap.h
*@date    11/08/19
*@brief   Header file for SkewHeap class, which controls a tree of linked
*         BinaryNodes and allows for various operations on them.
*******************************************************************************/

#ifndef SKEW_HEAP
#define SKEW_HEAP

#include "BinaryNode.h"
#include <string>

class SkewHeap {
private:
  BinaryNode<int>* rootPtr;
  bool swapped;
public:
  /**
  * @pre constructor is called
  * @return initalized SkewHeap
  **/
  SkewHeap();

  /**
  * @pre Destructor is called
  * @post Calls destroyTree on rootPtr
  **/
  ~SkewHeap();

  /**
  * @pre called with a valid, tested file name
  * @post builds the heap from the file of data using insert calls
  * @param fileName: name of file containing data
  **/
  void buildHeap(std::string fileName);

  /**
  * @post creates a new node with the given element and calls merge
  * @param x: element to be inserted
  * @return true if successful, otherwise false
  **/
  bool insert(int x);

  /**
  * @post finds and removes the given element from the heap
  * @param x: element to be removed
  * @return true if successful, otherwise false
  **/
  bool remove(int x);

  /**
  * @post merges the two given heaps recursively
  * @param heap1/heap2: two heaps to be merged
  * @return root of newly merged heap
  **/
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

  /**
  * @post recursively determines the height of the current subtree
  * @param subTreePtr: current location in tree
  * @return height of subtree
  **/
  int heightHelper(BinaryNode<int> *subTreePtr) const;

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

  /**
  * @post returns the current state of swapped and then sets it back to false
  * @return the current state of swapped
  **/
  bool isSwapped();

  /**
  * @post calls itself recursively to find the parent of the given element
  * @param curPtr: current location in tree
  * @param x: element being searched for
  * @return pointer of x's parent, otherwise nullptr
  **/
  BinaryNode<int>* findElement(BinaryNode<int>* curPtr, int x);

  /**
  * @post calls findElement on rootPtr and then returns a bool of if the element was found
  * @param x: element being searched for
  * @return true if x was found, otherwise false
  **/
  bool isPresent(int x);
  
  /**
  * @post merges the newHeap into rootPtr
  * @param newHeap: heap to be merged into rootPtr
  **/
  void mergeToRoot(BinaryNode<int>* newHeap);
};

#endif
