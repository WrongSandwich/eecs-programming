/*******************************************************************************
*@author  Evan Trout
*@file    Executive.h
*@date    10/17/2018
*@brief   Header file for the Executive class. Constructor creates 2 instances
          of Grammar class, then calls run to handle interaction with user.
*******************************************************************************/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include "Grammar.h"

class Executive
{
public:
  /**
  * @pre: includes two valid input file names
  * @param inputFile1: the filename to be used to create questionGrammar
  * @param inputFile2: the filename to be used to create answerGrammar
  * @post creates two Grammars, prints their contents, then calls run()
  */
  Executive(std::string inputFile1, std::string inputFile2);

  /**
  * @pre Executive constructor has run successfully and generated two Grammars
  * @param questionGrammar: Grammar that contains rules for generating a question
  * @param answerGrammar: Grammar that contains rules for generating an answer
  * @post Runs an interface with the user and uses the generate() Grammar function
  *       to provide the user with generated questions and answers
  */
  void run(Grammar questionGrammar, Grammar answerGrammar);
};

#endif
