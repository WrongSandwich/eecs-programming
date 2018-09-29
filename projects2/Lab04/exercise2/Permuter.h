#ifndef PERMUTER_H
#define PERMUTER_H

#include <string>

class Permuter
{
private:
  std::string str;
  int strLength;
public:
  Permuter(std::string str);
  void permute(char pArray[], int cur, int end);
};

#endif
