#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "ProductionRule.h"
#include <string>
#include <vector>

class Grammar
{
private:
  std::vector<ProductionRule> prodRules;
public:
  Grammar(std::string inputFile);
  ~Grammar();
  std::string generate();
  void print();
};

#endif
