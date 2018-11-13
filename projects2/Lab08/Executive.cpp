#include "BinaryNodeTree.h"
#include "Executive.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>



Executive::Executive(std::string type, std::string fileName)
{
  expLength = 0;
  std::ifstream inFile;
  inFile.open(fileName);
  if (inFile.is_open())
  {
    while (!inFile.eof())
    {
      std::string temp;
      inFile >> temp;
      expression += temp;
      expLength++;
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

void Executive::prefixTreeMaker(int pos) //Supposed to be recurisve
{
  if (expre)
}

void Executive::postfixTreeMaker() //Supposed to be non-recursive, uses Stack ADT
{

}
