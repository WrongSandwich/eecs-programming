/*******************************************************************************
*@author  Evan Trout
*@file    ProductionRule.h
*@date    10/17/2018
*@brief   Header file for the ProductionRule class. Stores a nonterminal label
*         and a number of rules for a Grammar rule, and has the ability to return
*         a random stored rule.
*******************************************************************************/


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
  /**
  * @param newLabel: nonterminal symbol to be used as string label
  * @post Creates a new ProductionRule and sets label to newLabel
  */
  ProductionRule(std::string newLabel);

  /**
  * @post clears the rules vector
  */
  ~ProductionRule();

  /**
  * @return: std::string label
  */
  std::string getLabel();

  /**
  * @post chooses a random index for the rules vector and returns the rule
  * @return string of the rule at the randomly chosen location
  */
  std::string getRandRule();

  /**
  * @param newRule: string of a rule to be added to the rules vector
  * @post adds newRule to rules
  */
  void addRule(std::string newRule);

  /**
  * @post prints all the contents of the rules vector with some formatting
  */
  void printRules();
};

#endif
