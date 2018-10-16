#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "Grammar.h"
#include "ProductionRule.h"


Grammar::Grammar(std::string inputFile)
{
  std::ifstream inFile;
  inFile.open(inputFile);
  if (inFile.is_open())
  {
    while (!inFile.eof())
    {
      std::string temp;
      getline(inFile, temp, '#');
      std::istringstream iss(temp);
      //Reading in the nonterminal label for the rule
      std::string word;
      iss >> word;
      //Searching to see if the rule already exists
      bool alreadyExists = false;
      int entry = 0;
      for(int i = 0; i < prodRules.size(); i++)
      {
        if (prodRules[i].getLabel() == word)
        {
          alreadyExists = true;
          entry = i;
        }
      }
      //ProductionRule for this label already exists
      if (alreadyExists == true)
      {
        std::string newRule;
        //Adding each new word to the rule string
        while (iss >> word)
        {
          newRule += word;
        }
        prodRules[entry].addRule(newRule);
      }
      else if (alreadyExists == false)
      {
        prodRules.push_back(ProductionRule(word));
        entry = (prodRules.size() - 1);
        std::string newRule;
        //Adding each new word to the rule string
        while (iss >> word)
        {
          newRule += word;
        }
        prodRules[entry].addRule(newRule);
      }
    }
  }
}

Grammar::~Grammar()
{
  prodRules.clear();
}

std::string Grammar::generate()
{
  //Set line equal to starting rule before parsing
  std::string genLine = prodRules[0].getRandRule();
  //Transferring the first rule into a vector of strings
  std::vector<std::string> genVector;
  //https://www.geeksforgeeks.org/tokenizing-a-string-cpp/
  std::stringstream check1(genLine);
  std::string intermediate;
  while (getline(check1, intermediate))
  {
    genVector.push_back(intermediate);
  }
  bool changeOccured = false;
  do //Do change loop until full loop with no changes
  {
    changeOccured = false;
    for (int i = 0; i < genVector.size(); i++)
    {
      for (int j = 0; j < prodRules.size(); j++)
      {
        if (genVector[i] == prodRules[j].getLabel())
        {
          //Replace label with relevant rule
          std::string rule = prodRules[j].getRandRule();
          //Removing relevant nonterminal from genVector
          genVector.erase(genVector.begin()+i);
          std::stringstream check2(rule);
          std::string temp;
          int z = i;
          while (getline(check2, temp))
          {
            genVector.insert(genVector.begin()+z, temp);
            z++;
          }
          changeOccured = true;
        }
      }
    }
  } while (changeOccured != false);
  std::string productLine = "";
  //Add all members of genVector to a finished product string to return
  for (int i = 0; i < genVector.size(); i++)
  {
    productLine += genVector[i];
  }
  return productLine;
}

void Grammar::print()
{
  std::cout << "START SYMBOL\n";
  prodRules[0].printRules();
  std::cout << "PRODUCTION RULES\n";
  for (int i = 1; i < prodRules.size(); i++)
  {
    prodRules[i].printRules();
  }
}
