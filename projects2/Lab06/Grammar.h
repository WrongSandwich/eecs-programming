/*******************************************************************************
*@author  Evan Trout
*@file    Grammar.h
*@date    10/17/2018
*@brief   Header file for the Grammar class. Reads and stores production rules
*         from an input file, and recursively carries out said rules to generate
          an output string.
*******************************************************************************/

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
  /**
  * @pre: is called by Executive with a valid file name
  * @param inputFile: fileName to be opened and read from
  * @post: populates a vector of production rules from the inputFile and
  *        initializes recursionDepth to 0
  */
  Grammar(std::string inputFile);

  /**
  * @pre instance of Grammar class is deleted
  * @post clears prodRules array
  */
  ~Grammar();

  /**
  * @param labelIndex: index of prodRules vector where relevant nonterminal is
  *                    being used
  * @post Recursively generates a string using the Grammar rules
  * @return productLine: string generated using the Grammar rules
  */
  std::string generate(int labelIndex);

  /**
  * @post Uses ProductionRule functions to print formatted rules
  */
  void print();
};

#endif
