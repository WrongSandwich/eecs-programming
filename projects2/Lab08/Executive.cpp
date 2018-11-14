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
    prefixTreeMaker(0);
  }
  else if (type == "postfix")
  {
    postfixTreeMaker();
  }
  else throw std::runtime_error("Invalid expression type");
}

BinaryNodeTree* Executive::prefixTreeMaker(int pos) //Supposed to be recurisve
{
  if (expression[pos] == '+' || expression[pos] == '-' || expression[pos] == '*' || expression[pos] == '/')
  {
    BinaryNodeTree* newTree = BinaryNodeTree(expression[pos], prefixTreeMaker(pos+1), prefixTreeMaker(pos+2));
  }
  else
  {
    BinaryNodeTree* newTree = BinaryNodeTree(expression[pos]);
  }
  return newTree;
}

void Executive::postfixTreeMaker() //Supposed to be non-recursive, uses Stack ADT
{

}
