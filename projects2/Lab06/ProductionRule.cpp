#include <string>
#include <random>
#include <vector>
#include <iostream>
#include "ProductionRule.h"

ProductionRule::ProductionRule(std::string newLabel) : label(newLabel)
{
}

ProductionRule::~ProductionRule()
{
  rules.clear();
}

std::string ProductionRule::getLabel()
{
  return label;
}

std::string ProductionRule::getRandRule()
{
  int max = (rules.size() - 1);
  //See https://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, max);
  int loc = dis(gen);
  //Returning the rules entry with the random index generated
  return rules[loc];
}

void ProductionRule::addRule(std::string newRule)
{
  rules.push_back(newRule);
}

void ProductionRule::printRules()
{
  for (int i = 0; i < rules.size(); i++)
  {
    std::cout << label << " " << rules[i] << '\n';
  }
}
