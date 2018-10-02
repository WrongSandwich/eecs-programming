#ifndef PERMUTER_H
#define PERMUTER_H

#include <string>

class Permuter
{
private:
  std::string origStr;
  std::string str;
  std::string prefix;
  int strLength;
public:
  Permuter(std::string origStr);
  void run(int length);
  void permute(int length, int spot);
};

#endif
