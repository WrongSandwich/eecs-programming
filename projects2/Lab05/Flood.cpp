#include <iostream>
#include "Flood.h"

Flood::Flood(char** theMap, int rows, int cols) : map(theMap), numRows(rows), numCols(cols), water(waterAmnt)
{}

Flood::~Flood()
{
  for (int i = 0; i < rows; i++)
  {
    delete[] map[i];
  }
  delete[] map;
}

void Flood::floodBase(int startRow, int startCol)
{
  recurseFlood(startRow, startCol);
  //Print data and board
  std::cout << "Size: " << numRows << "," << numCols << '\n';
  std::cout << "Starting position: " << startRow << ',' << startCol << '\n';
  for (int i = 0; i < numRows; i++)
  {
    for (int j = 0; j < numCols; j++)
    {
      std::cout << map[i][j];
    }
    std::cout << '\n';
  }
  if (water == 0)
  {
    std::cout << "Flood ran out of water.\n";
  }
  else
  {
    std::cout << "Flood complete.\n";
  }
}

void Flood::recurseFlood(int row, int col)
{
  if (water > 0)
  {
    //In order, checking up, right, down, left
    map[row][col] = '~';
    water--;
    //Need a way to determine what to do if out of water before the above statement
    //Flooding upwards
    if ((row-1) >= 0)
    {
      if (map[row-1][col] == '')
      {
        recurseFlood((row-1), col);
      }
    }
    //Flooding to the right
    if ((col+1) < numCols)
    {
      if (map[row][col+1] == '')
      {
        recurseFlood(row, (col+1));
      }
    }
    //Flooding downwards
    if ((row+1) < numRows)
    {
      if (map[row+1][col] == '')
      {
        recurseFlood((row+1), col);
      }
    }
    //Flooding to the left
    if ((col-1) >= 0)
    {
      if (map[row][col-1] == '')
      {
        recurseFlood(col, (row-1));
      }
    }
  }
}
