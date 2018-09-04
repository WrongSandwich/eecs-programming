/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 5 - Exercise 2
 * Description: This program creates an array of strings, has the user fill it, then shows them data.
 * Date: 02/26/18
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include <string>

std::string* strings = nullptr;
int userSize;
std::string userString;

int main()
{
	do
	{
		std::cout << "Input an array size for your words array: ";
		std::cin >> userSize;
	} while(userSize < 1);
	strings = new std::string[userSize];
	std::cout << "Now please enter " << userSize << " words\n";
	for(int i = 0; i < userSize; i++)
	{
		std::cout << "Input a word: ";
		std::cin >> userString;
		strings[i] = userString;
	}
	//Max and min word lengths
	std::string max = strings[0];
	std::string min = strings[0];
	int length, maxLength, minLength;
	maxLength = strings[0].length();
	minLength = strings[0].length();
	for(int i = 1; i < userSize; i++)
	{
		length = strings[i].length();
		if (length > maxLength)
		{
			max = strings[i];
		}
		else if (length < minLength)
		{
			min = strings[i];
		}
	}
	std::cout << "The longest word is: " << max << '\n';
	std::cout << "The shortest word is: " << min << '\n';
	delete[] strings;
}
