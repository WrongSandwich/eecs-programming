

#include <string>
#include <iostream>
#include "Checker.h"

Checker::Checker(std::string givenStr)
{
    origStr = givenStr;
    str = origStr;
    strLength = str.size();
}

void Checker::run()
{
  if ((strLength % 2) != 0)//Checking if string is an even number
  {
    std::cout << "The sequence " << origStr << " is not balanced\n";
  }
  else
  {
    test();
  }
}

void Checker::test()
{
  if (strLength == 0) //base case
  {
    std::cout << "The sequence " << origStr << " is balanced\n";
  }
  else //String is not empty
  {
    if (str.substr(0,1) == "(" && str.substr((strLength - 1),1) == ")") //If first and last characters are equal
    {
      str = str.substr(1, (strLength-2));
      strLength = strLength - 2;
      test();
    }
    else if (str.substr(0,1) == ")" && str.substr((strLength - 1),1) == "(")
    {
      str = str.substr(1, (strLength-2));
      strLength = strLength - 2;
      test();
    }
    else
    {
      std::cout << "The sequence " << origStr << " is not balanced\n";
    }
  }
}
