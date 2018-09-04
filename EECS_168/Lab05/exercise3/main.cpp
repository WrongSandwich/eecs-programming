/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 5 - Exercise 3
 * Description: This program uses a text document to store integers and display them.
 * Date: 02/26/18
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include <fstream>

//The first value in the file tells you how many ints (the type must be int!) are in the file. The rest of the values are the ints you want to store. Create a program that reads in the first value, always an int, that tells you how many values are in the file. Then, create an array to store all of those values. 

int arraySize, number, userSearch;
int* array = nullptr;
char userChoice;
bool isPresent;

int main()
{
	std::ifstream inFile;
	inFile.open("input.txt");
	if(inFile.is_open())
	{
		inFile >> arraySize;
		array = new int[arraySize];
		for(int i = 0; i < arraySize; i++)
		{
			inFile >> number;
			array[i] = number;
		}
		//Displaying contents of file
		int c = arraySize - 1;
		std::cout << "Contents of input.txt:\n[";
		for(int i = 0; i < c; i++)
		{
			std::cout << array[i] << ", ";
		}
		std::cout << array[c] << "]\n\n";
		//Searching
		do
		{
			isPresent = false;
			std::cout << "Input a value to search for: ";
			std::cin >> userSearch;
			for(int i = 0; i < arraySize; i++)
			{
				number = array[i];
				if (userSearch == number)
				{
					isPresent = true;
				}
			}
			if (isPresent == true)
			{
				std::cout << userSearch << " is in the array.\n";
			}
			else
			{
				std::cout << userSearch << " is not in the array.\n";
			}
			std::cout << "Do you want to quit (y/n): ";
			std::cin >> userChoice;
		} while(userChoice != 'Y' && userChoice != 'y');
		inFile.close();
	}
	else
	{
		std::cout << "File coult not be opened!\n";
	}
	delete[] array;
	return(0);
}
