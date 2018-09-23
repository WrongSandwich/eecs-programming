/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 2 - Exercise 3
 * Description: This program converts a Fahrenheit temperature input to Celsius or vice versa.
 * Date: 01/29/2018
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include <math.h>

double inputTemp = 0.0;
char inputUnit = 'A';
double outputTemp = 0.0;

int main()
{
	std::cout << "What is the unit of the temperature?: ";
	std::cin >> inputUnit;
	std::cout << "\nEnter the temperature: ";
	std::cin >> inputTemp;

	// Code for determining output temperature.

	if (inputUnit == 'F')
	{
		outputTemp = (inputTemp - 32.0) * (5.0/9.0);
		std::cout << "\n" << inputTemp << " degrees Fahrenheit = ";
		std::cout << outputTemp << " degrees Celsius.\n";
	}
	else
	{
		outputTemp = inputTemp * (9.0/5.0) + 32.0;
		std::cout << "\n" << inputTemp << " degrees Celsius = ";
		std::cout << outputTemp << " degrees Fahrenheit.\n";
	}
}
