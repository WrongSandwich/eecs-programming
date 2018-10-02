#include <string>
#include <iostream>
#include <cstring>
#include "Permuter.h"

//Kept shrinking length by 1, loop over characters in string
//For ith time through this loop do iterations with ith character in this loop
//Pass through a prefix with the set characters

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
