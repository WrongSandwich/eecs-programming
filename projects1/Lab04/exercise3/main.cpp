/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 4 - Exercise 3
 * Description: This program creates a triangle of asterisks based on user input.
 * Date: 02/17/18
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include <string>

using namespace std;

int n;

int main()
{
	cout << "Enter the number of asterisks for the base of the trinagle: ";
	cin >> n;
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c <= r; c++)
		{
			cout << "*";
		}
		cout << "\n";
	}
}

