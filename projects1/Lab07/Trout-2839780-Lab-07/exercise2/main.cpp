/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 7 - Exercise 2
 * Description: Takes a single int at the command-line and displays whether or not that integer is a palindrome.
 * Date: 03/12/18
 * ------------------------------------------------------------------------------- */
#include <iostream>
#include <string>
//Returns the last digit of a given integer.
int lastDigit(int n)
{
  while(n > 9)
  {
    n = n % 10;
  }
  return(n);
}
//Returns the input value, but with the last digit removed.
int removeLast(int n)
{
  if(n < 10)
  {
    return(0);
  }
  else
  {
    n = n / 10;
    return(n);
  }
}
//Returns the reverse of an integer.
int reverse(int n)
{
  int x = 0;
  while(n!=0)
  {
    x = x * 10;
    x = x + lastDigit(n);
    n = removeLast(n);
  }
  return(x);
}
//Returns true if n is a palindrome, false otherwise.
bool isPalindrome(int n)
{
  if(n == reverse(n))
  {
    return(true);
  }
  else
  {
    return(false);
  }
}
//Takes a single int at command-line and displays if it is a palindrome.
int main(int argc, char* argv[])
{
  std::string myStr;
  int x = 0;
  if(argc == 2)
  {
    myStr = argv[1];
    x = std::stoi(myStr);
    if (isPalindrome(x) == true)
    {
      std::cout << x << " is a palindrome!\n";
    }
    else
    {
      std::cout << x << " is not a palindrome!\n";
    }
  }
  else
  {
    std::cout << "ERROR: Please include 1 integer as an argument.\n";
  }
}
