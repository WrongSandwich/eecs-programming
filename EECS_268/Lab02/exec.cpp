//Need to create a WebBrowser in this code
#include "Exec.h"
#include "LinkedList.h"
#include "WebBrowser.h"

#include <iostream>
#include <fstream>
#include <string>

Exec::Exec(std::string fileName)
{
  std::ifstream inFile;
  inFile.open(fileName);
  if(inFile.is_open())
  {
    WebBrowser wb;
    inFile.close();
  }
  else
  {
    std::cout << "ERROR: File could not be opened\n";
  }
}

void Exec::run()
{
  std::ifstream inFile;
  inFile.open(fileName);
  std::string command, address;
  do
  {
    inFile >> command;
    //NAVIGATE
    if (command == "NAVIGATE")
    {
      inFile >> address;
      wb.navigateTo(address);
    }
    //BACK
    else if (command == "BACK")
    {
      wb.back();
    }
    //FORWARD
    else if (command == "FORWARD")
    {
      wb.forward();
    }
    //HISTORY
    else if (command == "HISTORY")
    {
      wb.printHistory();
    }
  } while(!inFile.eof()); //Checks if end of file has been reached
  inFile.close()
}
