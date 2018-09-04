/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-168 Lab 8
 * Description: Create a program that reads a chess board and determines possible attacks.
 * Date: 04/02/18
 * ------------------------------------------------------------------------------- */
#include <iostream>
#include <fstream>
#include <string>

char** textToArray(std::string fileName, int& rows, int& cols)
{
  std::ifstream inFile;
  inFile.open(fileName);
  if(inFile.is_open())
  {
    //Read the grid size
    inFile >> rows;
    inFile >> cols;
    //Create and fill the array from the text document
    char** grid = nullptr;
    grid = new char*[rows];
    for(int i = 0; i < rows; i++)
    {
      grid[i] = new char[cols];
      for(int j = 0; j < cols; j++)
      {
        inFile >> grid[i][j];
      }
    }
    inFile.close();
    return(grid);
  }
  else
  {
    std::cout << "ERROR: File could not be opened\n";
    return(0);
  }
}

void pawnTest(char** board, int rows, int cols)
{
  bool isAttacked = false;
  int i = 0;
  int j = 0;
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      //If a pawn is found at this location
      if(board[i][j] == 'P')
      {
        isAttacked = false;
        //Checking for attack in this column from the top
        for(int it = i - 1; it > -1; it--)
        {
          if(board[it][j] == 'R')
          {
            isAttacked = true;
          }
          else if(board[it][j] == 'P')
          {
            break;
          }
        }
        //Checking for attack in this column from the bottom
        for(int it = i + 1; it < rows; it++)
        {
          if(board[it][j] == 'R')
          {
            isAttacked = true;
          }
          else if(board[it][j] == 'P')
          {
            break;
          }
        }
        //Checking for attack in this row from the left
        for(int jt = j - 1; jt > -1; jt--)
        {
          if(board[i][jt] == 'R')
          {
            isAttacked = true;
          }
          else if(board[i][jt] == 'P')
          {
            break;
          }
        }
        for(int jt = j + 1; jt < cols; jt++)
        //Checking for attack in this row from the right
        {
          if(board[i][jt] == 'R')
          {
            isAttacked = true;
          }
          else if(board[i][jt] == 'P')
          {
            break;
          }
        }
        if(isAttacked == true)
        {
          std::cout << "! ";
        }
        else
        {
          std::cout << "P ";
        }
      }
      //If not a pawn, normal contents of point are printed
      else
      {
        std::cout << board[i][j] << " ";
      }
    }
    std::cout << '\n';
  }
}

int main(int argc, char* argv[])
{
  if (argc > 1)
  {
    std::string fileName = argv[1];
    char** board = nullptr;
    int rows = 0;
    int cols = 0;
    board = textToArray(fileName, rows, cols);
    //Printing array to show original board.
    std::cout << "=================================\nCURRENT BOARD LAYOUT\n";
    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < cols; j++)
      {
        std::cout << board[i][j] << " ";
      }
      std::cout << '\n';
    }
    std::cout << "=================================\nPOSSIBLE TARGET PAWNS\n";
    //Checking to see what pawns can be attacked.
    pawnTest(board, rows, cols);
    for(int i = 0; i < rows; i++)
    {
      delete[] board[i];
    }
    delete[] board;
  }
  else
  {
    std::cout << "ERROR: Please enter a valid file name\n";
  }
  return(0);
}
