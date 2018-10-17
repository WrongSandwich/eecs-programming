#include <iostream>
#include <string>
#include "Grammar.h"
#include "Executive.h"


Executive::Executive(std::string inputFile1, std::string inputFile2)
{
  //Constructing grammars using inputfile
  Grammar questionGrammar(inputFile1);
  Grammar answerGrammar(inputFile2);
  questionGrammar.print();
  answerGrammar.print();
  run(questionGrammar, answerGrammar);
}


void Executive::run(Grammar questionGrammar, Grammar answerGrammar)
{
  char userInput;
  do {
    std::cout << "Enter command: ";
    std::cin >> userInput;
    if (userInput == 'A')
    {
      std::string question, answer;
      question = questionGrammar.generate();
      std::cout << "Question: " << question << '\n';
      answer = answerGrammar.generate();
      std::cout << "Answer: " << answer << '\n';
    }
    else if (userInput == 'Q')
    {
      std::cout << "Exiting...\n";
    }
    else
    {
      std::cout << "Error: Please enter a valid menu choice(A or Q)\n";
    }
  } while (userInput != 'Q');
}
