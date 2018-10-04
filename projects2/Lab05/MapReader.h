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
  MapReader(std::string fileName);
  char** getMap();
  int getRows();
  int getCols();
  int getStartRow();
  int getStartCol();
  int getWater();
};

#endif
