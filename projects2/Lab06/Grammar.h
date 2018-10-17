#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "ProductionRule.h"
#include <string>
#include <vector>

class Grammar
{
private:
  std::vector<ProductionRule> prodRules;
  std::string fileName;
  int recursionDepth;
public:
  Grammar(std::string inputFile);
  ~Grammar();
  std::string generate(int labelIndex);
  void print();
};

#endif
