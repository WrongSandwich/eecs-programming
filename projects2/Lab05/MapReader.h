/*******************************************************************************
*@author  Evan Trout
*@file    MapReader.h
*@date    10/04/2018
*@brief   Header file for the MapReader class. Reads input from input file and
*         creates a 2D char array and associated integers. Also contains getters
*         for all private members.
*******************************************************************************/

#ifndef MAP_READER_H
#define MAP_READER_H

class MapReader
{
private:
  char** map;
  int numRows;
  int numCols;
  int startRow;
  int startCol;
  int waterAmnt;
public:
  /**
  * @param fileName: a fileName with data and a map to be used
  * @post Reads data into private members and creates a 2D char map
  * @return the constructed MapReader
  */
  MapReader(std::string fileName);

  /**
  * @return char** map
  */
  char** getMap();

  /**
  * @return int numRows
  */
  int getRows();

  /**
  * @return int numCols
  */
  int getCols();

  /**
  * @return int startRow
  */
  int getStartRow();

  /**
  * @return int startCol
  */
  int getStartCol();

  /**
  * @return int waterAmnt
  */
  int getWater();
};

#endif
