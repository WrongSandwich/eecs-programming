#ifndef PRODUCTION_RULE_H
#define PRODUCTION_RULE_H

#include <string>
#include <vector>

class ProductionRule
{
private:
  std::string label;
  std::vector<std::string> rules;
public:
  ProductionRule(std::string newLabel);
  ~ProductionRule();
  std::string getLabel();
  std::string getRandRule();
  void addRule(std::string newRule);
  void printRules();
};

#endif
