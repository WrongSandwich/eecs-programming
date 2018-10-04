#include <iostream>
#include <string>
#include <fstream>
#include "MapReader.h"

MapReader::MapReader(std::string fileName)
{
  map = nullptr;
  std::ifstream inFile;
  inFile.open(fileName);
  if (inFile.is_open())
  {
    inFile >> numRows;
    if (numRows < 1)
    {
      throw std::range_error("numRows cannot be less than 1");
    }
    inFile >> numCols;
    if (numCols < 1)
    {
      throw std::range_error("numCols cannot be less than 1");
    }
    inFile >> startRow;
    if (startRow < 0 || startRow >= numRows)
    {
      throw std::range_error("Invalid start position");
    }
    inFile >> startCol;
    if (startCol < 0 || startCol >= numCols)
    {
      throw std::range_error("Invalid start position");
    }
    inFile >> waterAmnt;
    inFile.ignore();
    map = new char*[numRows];
    for (int i = 0; i < numRows; i++)
    {
      std::string temp;
      map[i] = new char[numCols];
      getline(inFile, temp);
      for (int j = 0; j < numCols; j++)
      {
        map[i][j] = temp[j];
      }
    }
    if (map[startRow][startCol] == 'H')
    {
      throw std::range_error("Invalid start position");
    }
    //Printing array for testing purposes
    std::cout << "TEST ARRAY\n";
    for (int i = 0; i < numRows; i++)
    {
      for (int j = 0; j < numCols; j++)
      {
        std::cout << map[i][j];
      }
      std::cout << '\n';
    }
    inFile.close();
  }
  else throw std::runtime_error("File does not exist!");
}

char** MapReader::getMap()
{
  return map;
}

int MapReader::getRows()
{
  return numRows;
}

int MapReader::getCols()
{
  return numCols;
}

int MapReader::getStartRow()
{
  return startRow;
}

int MapReader::getStartCol()
{
  return startCol;
}

int MapReader::getWater()
{
  return waterAmnt;
}
