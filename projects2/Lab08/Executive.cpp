#include "BinaryNodeTree.h"
#include "Executive.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "PrecondViolationExcep.h"

//CONSTRUCTOR

Executive::Executive(std::string type, std::string fileName)
{
  expLength = 0;
  pos = -1;
  expression = nullptr;
  std::string* newArray = nullptr;
  std::ifstream inFile;
  inFile.open(fileName);
  if (inFile.is_open())
  {
    int i = 1;
    newArray = new std::string[i];
    inFile >> newArray[expLength];
    expression = newArray;
    expLength++;
    i++;
    newArray = nullptr;
    while (!inFile.eof())
    {
      newArray = new std::string[i];
      for (int j = 0; j < expLength; j++)
      {
        newArray[j] = expression[j];
      }
      inFile >> newArray[expLength]; //New array is complete
      delete[] expression;
      expression = newArray;
      expLength++;
      i++;
      newArray = nullptr;
    }
  }
  inFile.close();
  if (type == "prefix")
  {
    execTreePtr = prefixTreeMaker();
  }
  else if (type == "postfix")
  {
    execTreePtr = postfixTreeMaker();
  }
  else throw std::runtime_error("Invalid expression type");
  BinaryNodeTree<std::string> execTree = *execTreePtr;
  //Printing traversal results of new tree
  std::cout << "PREORDER\n";
  printTreePreorder(execTree);
  std::cout << "INORDER\n";
  printTreeInorder(execTree);
  std::cout << "POSTORDER\n";
  printTreePostorder(execTree);
}

Executive::~Executive()
{
  delete[] expression;
}

//TREE MAKERS

BinaryNodeTree<std::string>* Executive::prefixTreeMaker()
{
  pos++;
  if (pos < expLength)
  {
    if (expression[pos] == "+" || expression[pos] == "-" || expression[pos] == "*" || expression[pos] == "/")
    {
      BinaryNodeTree<std::string>* newTree = new BinaryNodeTree<std::string>(expression[pos], prefixTreeMaker(), prefixTreeMaker());
      return newTree;
    }
    else
    {
      BinaryNodeTree<std::string>* newTree = new BinaryNodeTree<std::string>(expression[pos]);
      return newTree;
    }
  }
}

BinaryNodeTree<std::string>* Executive::postfixTreeMaker() //Supposed to be non-recursive, uses Stack ADT
{
  for (int pos = 0; pos < expLength; pos++)
  {
    if (expression[pos] == "+" || expression[pos] == "-" || expression[pos] == "*" || expression[pos] == "/")
    {
      BinaryNodeTree<std::string>* rightLeaf = treeStack.peek();
      treeStack.pop();
      BinaryNodeTree<std::string>* leftLeaf = treeStack.peek();
      treeStack.pop();
      BinaryNodeTree<std::string>* newTree = new BinaryNodeTree<std::string>(expression[pos], leftLeaf, rightLeaf);
      treeStack.push(newTree);
    }
    else
    {
      BinaryNodeTree<std::string>* newTree = new BinaryNodeTree<std::string>(expression[pos]);
      treeStack.push(newTree);
    }
  }
  BinaryNodeTree<std::string>* newTree = treeStack.peek();
  return newTree;
}

//TRAVERSALS AND DISPLAY
static void display(std::string& item)
{
  std::cout << item << '\n';
}

void Executive::printTreePreorder(BinaryNodeTree<std::string> bt)
{
  bt.preorderTraverse(display);
}

void Executive::printTreeInorder(BinaryNodeTree<std::string> bt)
{
  bt.inorderTraverse(display);
}

void Executive::printTreePostorder(BinaryNodeTree<std::string> bt)
{
  bt.postorderTraverse(display);
}
