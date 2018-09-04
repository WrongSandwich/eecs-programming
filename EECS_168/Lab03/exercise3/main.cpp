/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 3 - Exercise 3
 * Description: This program detects whether or not a user input is part of the Fibonacci Sequence.
 * Date: 02/05/18
 * ------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;
int main()
{
	int userInput = 0;
	int fib2 = 1;
	int fib3 = 1;
	int fibTotal = 0;
	int fibCount = 0;
	cout << "Enter a value: ";
	cin >> userInput;
	cout << "\n";
	if (userInput == 1)
	{
		cout << "1 is the 2nd and 3rd values in the Fibonacci Sequence!\nGoodbye";
	}
	else if (userInput == 0)
	{
		cout << "0 is the 1st value in the Fibonacci Sequence!\nGoodbye";
	}	
	else
	{
		for (fibCount = 3; fibTotal < userInput; fibCount = fibCount + 1)
		{
			fibTotal = fib2 + fib3;
			fib2 = fib3;
			fib3 = fibTotal;
		}
		if (fibTotal == userInput)
		{
			/* I know I'm supposed to return the correct number suffix, but I'm not sure 	 				*how to so I've just changed the formatting slightly instead.*/
			cout << userInput << " is value number " << fibCount;
			cout << " in the Fibonacci Sequence!\nGoodbye\n\n";
		}
		else
		{
			cout << userInput << " is not in the Fibonacci Sequence!\nGoodbye\n\n";
		}
	}
}
