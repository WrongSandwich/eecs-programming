/*******************************************************************************
*@author  Evan Trout
*@file    Executive.h
*@date    11/14/18
*@brief   Header file for the Executive class. Takes user input passed
*         by main and reads a given file to create a binary tree of information,
*         then traverses the tree in multiple ways and prints the results.
*******************************************************************************/

#ifndef EXECUTIVE
#define EXECUTIVE

#include <string>
#include "BinaryNodeTree.h"
#include "Stack.h"
#include "PrecondViolationExcep.h"

class Executive
{
private:
  std::string* expression;
  int expLength;
  int pos;
  BinaryNodeTree<std::string>* execTreePtr;
  Stack<BinaryNodeTree<std::string>*> treeStack;
public:
  /**
  * @pre Executive constructor is called with two strings as arguments
  * @post Creates an Executive object by opening the given fileName, generating
  *       a string array with its contents, calling the appropriate treeMaker
  *       function, and calling all three printOrder functions
  * @param type: type of expression, either prefix or postfix
  * @throw runtime_error if invalid expression type is given
  **/
  Executive(std::string type, std::string fileName);

  /**
  * @pre An Executive object is deallocated
  * @post Deletes expression array and deallocates memory
  **/
  ~Executive();

  /**
  * @pre Function is called by the Executive constructor
  * @post Recursively generates a binary tree for the prefix expression
  * @return newTree: pointer to the newly generated tree
  **/
  BinaryNodeTree<std::string>* prefixTreeMaker();

  /**
  * @pre Function is called by the Executive constructor
  * @post Uses a stack to generate a binary tree for the postfix expression
  * @return newTree: pointer to the newly generated tree
  **/
  BinaryNodeTree<std::string>* postfixTreeMaker();

  /**
  * @pre Function is called by the Executive constructor after a tree is generated
  * @post bt is preorder traversed and its contents printed
  * @param bt: the BinaryNodeTree being traversed
  **/
  void printTreePreorder(BinaryNodeTree<std::string> bt);

  /**
  * @pre Function is called by the Executive constructor after a tree is generated
  * @post bt is inorder traversed and its contents printed
  * @param bt: the BinaryNodeTree being traversed
  **/
  void printTreeInorder(BinaryNodeTree<std::string> bt);

  /**
  * @pre Function is called by the Executive constructor after a tree is generated
  * @post bt is postorder traversed and its contents printed 
  * @param bt: the BinaryNodeTree being traversed
  **/
  void printTreePostorder(BinaryNodeTree<std::string> bt);
};
#endif
