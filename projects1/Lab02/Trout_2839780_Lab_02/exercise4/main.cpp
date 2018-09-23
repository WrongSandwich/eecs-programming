/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 2 - Exercise 4
 * Description: This program returns the ASCII value for a character.
 * Date: 01/29/2018
 * ------------------------------------------------------------------------------- */

#include <iostream>

char input;
int output = 0;

int main()
{
	std::cout << "Input a character: ";
	std::cin >> input;
	std::cout << "\nASCII value of " << input << " is " << int(input) << "\n";
}

