/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 3 - Exercise 4
 * Description: This program returns the largest prime number less than or equal to a user int.
 * Date: 02/05/18
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include <math.h>
using namespace std;

char userInput = 'a';
int x = 0;
int y, userNumber;
// Using the internet has told me that this way easier when using a bool.
bool isPrime = true;

int main()
{
    while (userInput != 'Y' && userInput != 'y')
    {
        cout << "Input an integer: ";
        cin >> userNumber;
        x = userNumber + 1;
        cout << "\n";
        do
        {
		x = x - 1;
		isPrime = true;
        	for (y = 2;y <= x / 2; ++y)
        	{
                	if (x % y == 0)
                	{
                    		isPrime = false;
                    		break;
                	}
        	}
        } while (isPrime == false);
        cout << x << " is the largest prime <= " << userNumber << "\n";
        cout << "Do you want to quit? (y/n): ";
        cin >> userInput;
        cout << "\n";
    }
    cout << "Goodbye.\n";
}

