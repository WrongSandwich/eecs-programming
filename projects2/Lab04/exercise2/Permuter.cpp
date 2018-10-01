#include <string>
#include <iostream>
#include <cstring>
#include "Permuter.h"

//Kept shrinking length by 1, loop over characters in cstring
//For ith time through this loop do iterations with ith character in this loop
//Pass through a prefix with the set characters

Permuter::Permuter(std::string str)
{
  strLength = str.size(); //Copying string into char array
  char pArray[strLength + 1];
  strcpy(pArray, str.c_str());
  permute(pArray, 0, strLength-1);
}

void Permuter::permute(char pArray[], int cur, int end)
{
   int i;
   if (cur == end)
     std::cout << pArray << '\n';
   else
   {
       for (i = cur; i <= end; i++)
       {
          //Swapping cur and i
          char temp = pArray[cur];
          pArray[cur] = pArray[i];
          pArray[i] = temp;
          std::cout << pArray[i] << '\n';
          std::cout << pArray[i];
          permute(pArray, cur+1, end);
          //Swapping back
          temp = pArray[cur];
          pArray[cur] = pArray[i];
          pArray[i] = temp;
       }
   }
}
