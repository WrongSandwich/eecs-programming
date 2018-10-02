/*******************************************************************************
*@author  Evan Trout
*@file    Permuter.cpp
*@date    10/02/2018
*@brief   Implementation file for the executive class Permuter. Constructor
*         takes the given string and stores it and its size, then calls run(),
*         which in turn calls the iterative permuter.
*******************************************************************************/

#include <string>
#include <iostream>
#include <cstring>
#include "Permuter.h"


Permuter::Permuter(std::string origStr)
{
  strLength = origStr.size();
  str = origStr;
  run(strLength);
}

void Permuter::run(int length)
{
  prefix = "";
  int spot = 0;
  permute(length, spot);
}

void Permuter::permute(int length, int spot)
{
  for (int cur = 0; cur < length; cur++)
  {
    std::string temp;
    temp += str.at(cur);
    prefix.insert(spot, temp);
    str.erase(cur,1);
    length--;
    std::cout << prefix << '\n';
    if (length != 0)
    {
      permute(length, spot+1);
    }
    str.insert(cur, temp);
    prefix.erase(spot, 1);
    length++;
  }
}
