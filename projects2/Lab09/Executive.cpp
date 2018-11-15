#include "Executive.h"
#include "BinarySearchTree.h"
#include <string>
#include <fstream>
#include <iostream>

Executive::Executive(std::string fileName)
{
  dataLength = 0;
  pos = -1;
  inputData = nullptr;
  std::string* newArray = nullptr;
  std::ifstream inFile;
  inFile.open(fileName);
  if (inFile.is_open())
  {
    int i = 1;
    newArray = new std::string[i];
    inFile >> newArray[expLength];
    expression = newArray;
    i++;
    newArray = nullptr;
    while (!inFile.eof())
    {
      expLength++;
      newArray = new std::string[i];
      for (int j = 0; j < expLength; j++)
      {
        newArray[j] = expression[j];
      }
      inFile >> newArray[expLength]; //New array is complete
      delete[] expression;
      expression = newArray;
      i++;
      newArray = nullptr;
    }
  }
  inFile.close();
}
