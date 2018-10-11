#ifndef GRAMMAR_H
#define GRAMMAR_H

class Grammar
{
private:
  std::vector<ProductionRule> prodRules;
public:
  Grammar(std::string inputFile);
};

#endif
