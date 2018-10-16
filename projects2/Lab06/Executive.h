#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include "Grammar.h"

class Executive
{
private:
  Grammar questionGrammar
  Grammar answerGrammar
public:
  Executive(std::string inputFile1, std::string inputFile2);
  void run();
};

#endif
