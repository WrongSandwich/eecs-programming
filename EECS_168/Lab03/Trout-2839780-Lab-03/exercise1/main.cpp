/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 3 - Exercise 1
 * Description: This program allows the user to see the ASCII representation of a specific number.
 * Date: 02/05/18
 * ------------------------------------------------------------------------------- */
#include <iostream>
using namespace std;
int main()
{
	int menuInput = 0;
	int userInt = 0;
	while (menuInput != 3)
	{
		cout << "1) Select a specific ASCII character provided an int\n";
		cout << "2) Display visible ASCII values (33 to 126)\n";
		cout << "3) Exit\nChoice: ";
		cin >> menuInput;
		cout << "\n";

		if (menuInput == 1)
		{
			cout << "Enter value: ";
			cin >> userInt;
			cout << "\n";
			cout << userInt << " = " << static_cast<char>(userInt) << "\n\n";
		}
		else if (menuInput == 2)
		{
			userInt = 33;
			while (userInt <= 126)
			{
				cout << userInt << " = " << static_cast<char>(userInt) << "\n";
				userInt = userInt + 1;
			}
			cout << "\n";
		}
		else if (menuInput == 3)
		{
			cout << "Goodbye...\n\n";
		}
		else
		{
			cout << "ERROR: Invalid menu selection\n\n";
		}
	}
}
