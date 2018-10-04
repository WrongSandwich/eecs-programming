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
  Flood(char** theMap, int rows, int cols, int waterAmnt);
  ~Flood();
  void floodBase(int startRow, int startCol);
  void recurseFlood(int row, int col);
};

#endif
