/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 4 - Exercise 2
 * Description: This program plays a "Guess a Word" game with the user.
 * Date: 02/16/18
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include <string>
using namespace std;

std::string userGuess;
std::string secretWord = "valentine";
char userChoice;
int c = 0;

int main()
{
	do
	{
		cout << "Welcome to the word guessing game.\nGuess a word: ";
		cin >> userGuess;
		while (userGuess != secretWord)
		{
			if (userGuess == secretWord)
			{
				break;
			}
			else if (userGuess.length() == secretWord.length())
			{
				c = 0;
				for (unsigned int i = 0; i < secretWord.length(); i++)
				{
					if (userGuess.at(i) == secretWord.at(i))
					{
						c = c + 1;
					}
					else
					{
						c = c;
					}
				}
				cout << "You have " << c << " letters correct.\n";
				cout << "Incorrect. Guess again: ";
				cin >> userGuess;
			}
			else
			{
				if (userGuess.length() > secretWord.length())
				{
					cout << "The word is shorter.\n";
				}
				else
				{
					cout << "The word is longer.\n";
				}
				cout << "Incorrect. Guess again: ";
				cin >> userGuess;
			}
		}
		cout << "You win!\nWould you like to play again? (y/n): ";
		cin >> userChoice;
	} while (userChoice != 'N' && userChoice != 'n');
}
