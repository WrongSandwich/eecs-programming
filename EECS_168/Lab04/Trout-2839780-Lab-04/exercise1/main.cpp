/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 4 - Exercise 1
 * Description: This program plays a "Guess a Number" game with the user.
 * Date: 02/16/18
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int userGuess, difference, previousGuess, secretNumber, guessCount;
char userChoice;

int main()
{
	cout << "Welcome to the number guessing game.\n";
	srand (time(NULL));
	do
	{
		secretNumber = rand() % 100 + 1;
		guessCount = 0;
		do
		{
			guessCount = guessCount + 1;
			cout << "Guess a number: ";
			cin >> userGuess;
			difference = secretNumber - userGuess;
			if (difference > 0)
			{
				cout << "\nSorry, your guess is too low.\n";
				previousGuess = userGuess;
			}
			else if (difference < 0)
			{
				cout << "\nSorry, your guess is too high.\n";
				previousGuess = userGuess;
			}
		} while (difference != 0);
		cout << "You win!\nYou guessed the secret number after " << guessCount << " guess(es).";
		cout << "\nYour closest guess was " << previousGuess;
		cout << "\nWould you like to play again? (y/n): ";
		cin >> userChoice;
	} while (userChoice != 'N' && userChoice != 'n');
}
