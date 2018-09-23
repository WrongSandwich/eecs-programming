/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 5 - Exercise 4
 * Description: This program has the user open a text document, then creates a normalized and reversed 
 * version of the document.
 * Date: 02/28/18
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include <fstream>
#include <string>

int arraySize, g;
double number;
double* originalArray = nullptr;
double* normalizedArray = nullptr;
double* reversedArray = nullptr;
bool isOpen = false;
std::string fileName;

int main()
{
	std::ifstream inFile;
	//Checking to see if file name is valid and opening file.
	do
	{
		std::cout << "File name: ";
		std::cin >> fileName;
		inFile.open(fileName);
		if (inFile.is_open())
		{
			isOpen = true;
		}
	} while (isOpen == false);
	//Reading and storing file values.
	inFile >> arraySize;
	originalArray = new double[arraySize];
	for(int i = 0; i < arraySize; i++)
	{
		inFile >> number;
		originalArray[i] = number;
	}
	inFile.close();
	//Determining max and min.
	double max = originalArray[0];
	double min = originalArray[0];
	for(int i = 1; i < arraySize; i++)
	{
		if (originalArray[i] > max)
		{
			max = originalArray[i];
		}
		else if (originalArray[i] < min)
		{
			min = originalArray[i];
		}
	}
	//Creating the normalized array.
	normalizedArray = new double[arraySize];
	for(int i = 0; i < arraySize; i++)
	{
		number = originalArray[i];
		number = (number - min)/(max - min);
		normalizedArray[i] = number;
	}
	//Creating the reversed array.
	reversedArray = new double[arraySize];
	int c = arraySize - 1;
	for(int i = 0; i < arraySize; i++)
	{
		number = originalArray[i];
		g = c - i;
		reversedArray[g] = number;
	}
	//Creating normalized.txt
	std::ofstream myOutFile;
	std::string fileName = "normalized.txt";
	myOutFile.open(fileName);
	myOutFile << "Original array: [";
	for (int i = 0; i < c; i++)
	{
		myOutFile << originalArray[i] << ", ";
	}
		myOutFile << originalArray[c] << "]\n";
	myOutFile << "Normalized array: [";
	for (int i = 0; i < c; i++)
	{
		myOutFile << normalizedArray[i] << ", ";
	}
		myOutFile << normalizedArray[c] << "]\n";
	myOutFile.close();
	fileName = "reversed.txt";
	myOutFile.open(fileName);
	myOutFile << "Original array: [";
	for (int i = 0; i < c; i++)
	{
		myOutFile << originalArray[i] << ", ";
	}
		myOutFile << originalArray[c] << "]\n";
	myOutFile << "Reversed array: [";
	for (int i = 0; i < c; i++)
	{
		myOutFile << reversedArray[i] << ", ";
	}
		myOutFile << reversedArray[c] << "]\n";
	myOutFile.close();
	delete[] originalArray;
	delete[] normalizedArray;
	delete[] reversedArray;
	return(0);
}
