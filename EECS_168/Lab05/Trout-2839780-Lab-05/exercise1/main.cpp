/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 5 - Exercise 1
 * Description: This program creates a 5-double array, has the user input numbers, then returns data.
 * Date: 02/26/18
 * ------------------------------------------------------------------------------- */

#include <iostream>

const int size = 5;
double nums[size];
double userInput;

int main()
{
	std::cout << "Please enter 5 numbers\n";
	for(int i = 0; i < size; i++)
	{
		std::cout << "Input a number into your array: ";
		std::cin >> userInput;
		nums[i] = userInput;
	}
	std::cout << "Here are the numbers in your array:\n";
	for(int i = 0; i < size; i++)
	{
		std::cout << nums[i] << '\n';
	}
	//Sum
	double sum = 0;
	for(int i = 0; i < size; i++)
	{
		sum = sum + nums[i];
	}
	std::cout << "The sum of all the values is: " << sum << '\n';
	//Average
	double average = sum / size;
	std::cout << "The average of all the values is: " << average << '\n';
	//Max and min
	double max = nums[0];
	double min = nums[0];
	for(int i = 1; i < size; i++)
	{
		if (nums[i] > max)
		{
			max = nums[i];
		}
		else if (nums[i] < min)
		{
			min = nums[i];
		}
	}
	std::cout << "The largest value is: " << max << '\n';
	std::cout << "The smallest value is: " << min << '\n';
}
