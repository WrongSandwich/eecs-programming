/*******************************************************************************
*@author  Evan Trout
*@file    LeftistHeap.h
*@date    10/29/19
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

  /**
  * @pre called by exec after checking for valid file name
  * @param fileName: name of file to be opened containing data
  * @post opens and reads in from given file and inserts data into leftist heap
  **/  
  void buildHeap(std::string fileName);

  /**
  * @param x: element to be inserted into heap
  * @post checks to make sure element isn't duplicate then enters it
  * @return true if inserted, otherwise false
  **/
  bool insert(int x);

  /**
  * @post calls merge on the root's two subtrees and returns the roots value
  * @return minimum value being deleted
  **/
  int deleteMin();

  /**
  * @return the value stored at the root
  **/
  int findMin();

  /**
  * @param heap1/heap2: two leftist heaps being merged
  * @post merges the two heaps using recursive calls
  * @return pointer to the root node of the merged heap
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
  * @param subTreePtr: current location in heap
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
  * @post returns value of swapped, then sets it to false
  * @return the current value of swapped
  **/
  bool isSwapped();

  /**
  * @param curPtr: current location in tree
  * @param x: value being searched for
  * @post recursively traverses tree searching for a matching value
  * @return true if duplicate found, otherwise false
  **/
  bool isDuplicate(BinaryNode<int>* curPtr, int x);
  
  /**
  * @pre called by exec with valid ints
  * @param x/y/z: three values to be inserted as a subheap
  * @post creates a valid heap, then merges it with the existing heap
  * @return true if sucessful, otherwise false
  **/
  bool showMerge(int x, int y, int z);
};

#endif
