/*******************************************************************************
*@author  Evan Trout
*@file    Flood.h
*@date    10/04/2018
*@brief   Header file for the Flood class. Takes in a 2D char map array created
*         by MapReader, then recursively plays out a flood.
*******************************************************************************/


#ifndef FLOOD_H
#define FLOOD_H

class Flood
{
private:
  char** map;
  int numRows;
  int numCols;
  int water;
public:
  /**
  * @param theMap: 2D char map constructed by MapReader
  * @param rows: number of rows in the map
  * @param cols: number of columns in the map
  * @param waterAmnt: the amount of water in the flood
  * @return the constructed Flood object
  */
  Flood(char** theMap, int rows, int cols, int waterAmnt);

  /**
  * @post deletes the map and deallocates all used memory
  */
  ~Flood();

  /**
  * @param startRow, startCol: initial coordinates for flood
  * @post calls recurseFlood, and when flooding is done prints results
  */
  void floodBase(int startRow, int startCol);

  /**
  * @param row, col: the current coordinates of the flood
  * @post if water != 0, floods the current location and checks adjacent tiles
  *       for possible flooding; calls recurseFlood on floodable tiles
  */
  void recurseFlood(int row, int col);
};

#endif
