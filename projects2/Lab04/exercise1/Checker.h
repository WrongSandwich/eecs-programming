#ifndef CHECKER_H
#define CHECKER_H

#include <string>

class Checker
{
private:
  std::string fileName;
  std::string origStr;
  std::string str;
  int strLength;

public:
  Checker(std::string fileName);
  void run();
  void test();
};

#endif
