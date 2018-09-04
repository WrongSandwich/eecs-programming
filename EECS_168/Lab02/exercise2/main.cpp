/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 2 - Exercise 2
 * Description: This program solves the quadratic equation.
 * Date: 01/29/2018
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include <math.h>

double a = 0.0;
double b = 0.0;
double c = 0.0;
double root1 = 0.0;
double root2 = 0.0;
double discriminant = 0.0;

int main()
{
	std::cout << "This program solves the quadratic equation.\nInput a:";
	std::cin >> a;
	std::cout << "\nInput b:";
	std::cin >> b;
	std::cout << "\nInput c:";
	std::cin >> c;

	// Code to determine the discriminant
	discriminant = (b * b) - (4 * a * c);
	if (discriminant > 0)
	{
		root1 = 1/(2*a)*(-b + sqrt(discriminant));
		root2 = 1/(2*a)*(-b - sqrt(discriminant));
		std::cout << "\nRoot 1:" << root1;
		std::cout << "\nRoot 2:" << root2;
		std::cout << "\n";
	}
	else
	{
		std::cout << "\nERROR: Discriminant is less than zero.\n";
	}
}
