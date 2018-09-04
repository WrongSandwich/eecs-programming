/* -------------------------------------------------------------------------------
 * File Name: main.cpp
 * Author: Evan Trout
 * Assignment: EECS-268 Lab 01
 * Description: Create an interactive course directory.
 * Date: 08/30/18
 * ------------------------------------------------------------------------------- */

#include <iostream>
#include "Directory.h"
#include <string>

 int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     Directory exec(argv[1]); //sample creation of executive object
     exec.run(); //presumably handles the calling of all other member methods
  }

  return(0);
}
