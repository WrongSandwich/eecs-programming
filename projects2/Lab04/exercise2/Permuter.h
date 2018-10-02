#ifndef PERMUTER_H
#define PERMUTER_H

#include <string>

class Permuter
{
private:
  std::string origStr;
  int strLength;
public:
  Permuter(std::string origStr);
  void run(std::string str, int length);
  void permute(std::string str, std::string prefix, int length, int spot);
};

#endif
