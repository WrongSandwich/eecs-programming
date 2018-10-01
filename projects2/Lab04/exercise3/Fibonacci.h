#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <string>

class Fibonacci
{
public:
  Fibonacci(std::string flag, std::string targetStr);
  void ith(int target);
  void verify(int target);
  int fib(int i);
};

#endif
