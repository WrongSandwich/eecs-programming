/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 2 - Exercise 1
 * Description: This program solves for the hypotenuse of a right triangle.
 * Date: 01/29/2018
 * ------------------------------------------------------------------------------- */

#include <math.h>
#include <iostream>

double inputA = 0.0;
double inputB = 0.0;
double outputC = 0.0;

int main()
{
	std::cout << "Will use the formula a^2 + b^2 = c^2 to solve for the hypotenuse of a triangle.\n Input a value for a:";
	std::cin >> inputA;
	std::cout << "\n Input a value for b:";
	std::cin >> inputB;
	outputC = sqrt(inputA * inputA + inputB * inputB);
	std::cout << "\n The hypotenuse is :" << outputC;
	std::cout << "\n";
}
