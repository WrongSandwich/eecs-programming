/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 2 - Exercise 5
 * Description: This program makes change for the user using coins.
 * Date: 01/29/2018
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include <math.h>
using namespace std;

int inputPennies = 0;
int outputQuarters = 0;
int outputDimes = 0;
int outputNickels = 0;
int outputPennies = 0;

int main()
{
	cout << "How many pennies do you have? ";
	cin >> inputPennies;

	//Here is where I determine the number of each type of coin.
	outputQuarters = inputPennies / 25;
	inputPennies = inputPennies - outputQuarters * 25;
	outputDimes = inputPennies / 10;
	inputPennies = inputPennies - outputDimes * 10;
	outputNickels = inputPennies / 5;
	inputPennies = inputPennies - outputNickels * 5;
	outputPennies = inputPennies;

	//Now I display the results.
	cout << "\nQuarters: " << outputQuarters << "\nDimes: " << outputDimes;
	cout << "\nNickels: " << outputNickels << "\nPennies: " << outputPennies << "\n";
}
