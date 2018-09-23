/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 4 - Exercise 4 "Checker"
 * Description: This program creates a checkerboard based on user inputs.
 * Date: 02/17/18
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include <string>

int n = 0;
int cCheck, rCheck;
char a, b, userChoice;

int main()
{
	do
	{
		do
		{
			std::cout << "Enter a size: ";
			std::cin >> n;
		} while (n <= 0);
		std::cout << "Enter symbol 1: ";
		std::cin >> a;
		std::cout << "Enter symbol 2: ";
		std::cin >> b;
		for (int r = 0; r < n; r++)
		{
			rCheck = r % 2;
			if (rCheck == 0)
			{
				for (int c = 0; c < n; c++)
				{
					cCheck = c % 2;
					if (cCheck == 0)
					{
						std::cout << a;
					}
					else
					{
						std::cout << b;
					}
				}
			}
			else
			{
				for (int c = 0; c < n; c++)
				{
					cCheck = c % 2;
					if (cCheck == 0)
					{
						std::cout << b;
					}
					else
					{
						std::cout << a;
					}
				}
			}
			std::cout << "\n";
		}
		std::cout << "Do you wish to quit (y/n): ";
		std::cin >> userChoice;
	} while (userChoice != 'y' && userChoice != 'Y');
}
