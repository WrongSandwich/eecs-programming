/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 6 - Exercise 1
 * Description: This program obtains a 2D array from the user, then creates various text documents.
 * Date: 03/05/18
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include <fstream>
#include <string>

int rows, columns, g, h;
double number;
double rowSum;
double average;
double** grid = nullptr;
double** reversedGrid = nullptr;
double** flippedGrid = nullptr;
double** diagonalGrid = nullptr;
double* rowAverageArray = nullptr;
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
  //Reading and storing array dimensions.
  inFile >> rows;
  inFile >> columns;
  //Creating the 2D array
  grid = new double*[rows];
  for(int i = 0; i < rows; i++)
  {
    grid[i] = new double[columns];
  }
  //Transferring file data into array.
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      inFile >> number;
      grid[i][j] = number;
    }
  }
  //AVERAGES.TXT
  //Determining the averages of each row.
  rowAverageArray = new double[rows];
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      number = grid[i][j];
      rowSum = rowSum + number;
    }
    rowSum = rowSum / columns;
    rowAverageArray[i] = rowSum;
    rowSum = 0;
  }
  //Determining total average.
  for(int i = 0; i < rows; i++)
  {
    number = rowAverageArray[i];
    rowSum = rowSum + number;
  }
  average = rowSum / rows;
  //Creating averages.txt.
  std::ofstream myOutFile;
  std::string fileName = "averages.txt";
  myOutFile.open(fileName);
  myOutFile << "Total average: " << average << '\n';
  for (int i = 0; i < rows; i++)
  {
    myOutFile << "Row " << (i + 1) << " average: " << rowAverageArray[i] << '\n';
  }
  myOutFile.close();
  //REVERSE.TXT
  //Creating the reversed array.
  reversedGrid = new double*[rows];
  for(int i = 0; i < rows; i++)
  {
    reversedGrid[i] = new double[columns];
  }
  int c = columns - 1;
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      number = grid[i][j];
      g = c - j;
      reversedGrid[i][g] = number;
    }
  }
  //Creating reversed.txt.
  fileName = "reversed.txt";
  myOutFile.open(fileName);
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      myOutFile << reversedGrid[i][j] << " ";
    }
    myOutFile << '\n';
  }
  myOutFile.close();
  //FLIPPED.TXT
  //Creating the flipped array.
  flippedGrid = new double*[rows];
  for(int i = 0; i < rows; i++)
  {
    flippedGrid[i] = new double[columns];
  }
  c = rows - 1;
  for(int j = 0; j < columns; j++)
  {
    for(int i = 0; i < rows; i++)
    {
      number = grid[i][j];
      g = c - i;
      flippedGrid[g][j] = number;
    }
  }
  //Creating flipped.txt.
  fileName = "flipped.txt";
  myOutFile.open(fileName);
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < columns; j++)
    {
      myOutFile << flippedGrid[i][j] << " ";
    }
    myOutFile << '\n';
  }
  myOutFile.close();
  //DIAGONAL.TXT (Only occurs if diagonal)
  //Checking for symmetric dimensions.
  if (rows == columns)
  {
    //Creating diagonal array.
    diagonalGrid = new double*[rows];
    for(int i = 0; i < rows; i++)
    {
      diagonalGrid[i] = new double[columns];
    }
    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < columns; j++)
      {
        number = grid[i][j];
        diagonalGrid[j][i] = number;
      }
    }
    //Creating diagonal.txt.
    fileName = "diagonal.txt";
    myOutFile.open(fileName);
    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < columns; j++)
      {
        myOutFile << diagonalGrid[i][j] << " ";
      }
      myOutFile << '\n';
    }
    myOutFile.close();
    for(int i = 0; i < rows; i++)
    {
      delete[] diagonalGrid[i];
    }
    delete[] diagonalGrid;
  }
  for(int i = 0; i < rows; i++)
  {
    delete[] grid[i];
    delete[] reversedGrid[i];
    delete[] flippedGrid[i];
  }
  delete[] grid;
  delete[] rowAverageArray;
  delete[] reversedGrid;
  delete[] flippedGrid;
  return(0);
}
