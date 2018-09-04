/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 3 - Exercise 2
 * Description: This program allows the user to determine the number of sick people on any given day.
 * Date: 02/05/18
 * ------------------------------------------------------------------------------- */
#include <iostream>
using namespace std;

int main()
{
	int userInput = 0;
	int day1Count = 1;
	int day2Count = 5;
	int day3Count = 17;
	int totalSick = 0;
	int daysPassed = 4;
	cout << "OUTBREAK!\nWhat day do you want a sick count for?: ";
	cin >> userInput;
	if (userInput <= 0)
	{
		cout << "\nInvalid day\n";
	}
	else if (userInput == 1)
	{
		cout << "\nTotal people with flu: " << day1Count << "\n";
	}
	else if (userInput == 2)
	{
		cout << "\nTotal people with flu: " << day2Count << "\n";
	}
	else if (userInput == 3)
	{
		cout << "\nTotal people with flu: " << day3Count << "\n";
	}
	else
	{
		for (daysPassed = 4; daysPassed <= userInput; daysPassed = daysPassed + 1)
		{
			totalSick = day1Count + day2Count + day3Count;
			day1Count = day2Count;	
			day2Count = day3Count;		
			day3Count = totalSick;
		}
		cout << "\nTotal people with flu: " << totalSick << "\n";
	}
}
