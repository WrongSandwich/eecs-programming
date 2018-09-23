/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 7 - Exercise 1
 * Description: Receives two numbers from the user, then using functions returns a summation.
 * Date: 03/12/18
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include <string>
//Returns the smaller integer
int smaller(int n1, int n2)
{
  if (n1 > n2)
  {
    return(n2);
  }
  else
  {
    return(n1);
  }
}
//Returns the larger integer
int larger(int n1, int n2)
{
  if (n1 > n2)
  {
    return(n1);
  }
  else
  {
    return(n2);
  }
}
//Determines the sum of the values from the smaller to the larger value.
int sum(int n1, int n2)
{
  int x = 0;
  for(int i = smaller(n1,n2); i <= larger(n1,n2); i++)
  {
    x = x + i;
  }
  return(x);
}

int main(int argc, char* argv[])
{
  int n1 = 0;
  int n2 = 0;
  std::string str1;
  std::string str2;
  if(argc == 3)
  {
    str1 = argv[1];
    str2 = argv[2];
    n1 = std::stoi(str1);
    n2 = std::stoi(str2);
    std::cout << "Summation from " << smaller(n1,n2) << " to " << larger(n1,n2);
    std::cout << " : " << sum(n1,n2) << '\n';
  }
  else
  {
    std::cout << "ERROR: Please include two numbers as command line arguments.\n";
  }
  return(0);
}
