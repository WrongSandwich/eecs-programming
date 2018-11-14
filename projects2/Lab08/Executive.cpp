#include "BinaryNodeTree.h"
#include "Executive.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>



Executive::Executive(std::string type, std::string fileName)
{
  expLength = 0;
  expression = nullptr;
  int* newArray = nullptr;
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
      newArray = new std::string[i]
      for (int j = 0; j < expLength; j++);
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
    execTree = prefixTreeMaker(0);
  }
  else if (type == "postfix")
  {
    postfixTreeMaker();
  }
  else throw std::runtime_error("Invalid expression type");
}

BinaryNodeTree Executive::prefixTreeMaker(int pos) //Need to work in length of array
{
  if (expression[pos] == '+' || expression[pos] == '-' || expression[pos] == '*' || expression[pos] == '/')
  {
    BinaryNodeTree<std::string> newTree = BinaryNodeTree<std::string>(expression[pos], prefixTreeMaker(pos+1), prefixTreeMaker(pos+2));
  }
  else
  {
    BinaryNodeTree<std::string> newTree = BinaryNodeTree<std::string>(expression[pos]);
  }
  return newTree;
}

void Executive::postfixTreeMaker() //Supposed to be non-recursive, uses Stack ADT
{
  for (int pos = 0; i < expLength; pos++)
  {
    if (expression[pos] == '+' || expression[pos] == '-' || expression[pos] == '*' || expression[pos] == '/')
    {
      BinaryNodeTree<std::string> newTree = BinaryNodeTree<std::string>(expression[pos]);
      BinaryNodeTree<std::string> rightLeaf = BinaryNodeTree<std::string>(treeStack.peek());
      treeStack.pop();
      BinaryNodeTree<std::string> leftLeaf = BinaryNodeTree<std::string>(treeStack.peek());
      treeStack.pop();
    }
    else
    {
      BinaryNodeTree<std::string> newTree = BinaryNodeTree<std::string>(expression[pos]);
      treeStack.push(newTree);
    }
  }
}
