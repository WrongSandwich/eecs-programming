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
    inFile >> numCols;
    inFile >> startRow;
    inFile >> startCol;
    inFile >> waterAmnt;
    map = new char*[numRows];
    for (int i = 0; i < numRows; i++)
    {
      map[i] = new char[numCols];
      for (int j = 0; j < numCols; j++)
      {
        inFile >> map[i][j];
      }
    }
  }
  inFile.close();
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
