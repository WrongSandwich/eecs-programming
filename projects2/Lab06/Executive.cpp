#include <iostream>
#include <string>


Executive::Executive(std::string inputFile1, std::string inputFile2)
{
  //Constructing grammars using inputfile
  Grammar questionGrammar(std::string inputFile1);
  Grammar answerGrammar(std::string inputFile2);
  //Get set of nonterminals, termainals, and start symbol from questionGrammar and print
  //Get set of nonterminals, terminals, and start symbol from answerGrammar and print
  run();
}


void Executive::run()
{
  char userInput = '';
  do {
    std::cout << "Enter command: ";
    std::cin >> userInput;
    if (userInput == 'A')
    {
      std::string question, answer;
      question = questionGrammar.generate();
      std::cout << question << '\n';
      answer = answerGrammar.generate();
      std::cout << answer << '\n';
    }
    else if (userInput == 'Q')
    {
      std::cout << "Exiting...\n";
    }
    else
    {
      std::cout << "Error: Please enter a valid menu choice\n";
    }
  } while (userInput != 'Q');
}
