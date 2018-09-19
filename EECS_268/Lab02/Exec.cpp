//Need to create a WebBrowser in this code
#include "Exec.h"
#include "WebBrowser.h"

#include <iostream>
#include <fstream>
#include <string>

Exec::Exec(std::string file)
{
  wb = new WebBrowser;
  std::ifstream inFile;
  inFile.open(file);
  if(inFile.is_open())
  {
    std::cout << "WHAT THE FUCK";
    inFile.close();
  }
  fileName = file;
}

void Exec::run()
{
  std::cout << fileName;
  std::ifstream inFile;
  std::cout << "Reached run()\n";
  inFile.open(fileName);
  if(inFile.is_open())
  {
    std::cout <<"ARGH";
  }
  std::cout << "File opened";
  std::string command;
  std::string address;
  do
  {
    inFile >> command;
    std::cout << command;
    //NAVIGATE
    if (command == "NAVIGATE")
    {
      inFile >> address;
      wb->navigateTo(address);
    }
    //BACK
    else if (command == "BACK")
    {
      wb->back();
    }
    //FORWARD
    else if (command == "FORWARD")
    {
      wb->forward();
    }
    //HISTORY
    else if (command == "HISTORY")
    {
      wb->printHistory();
    }
  } while(!inFile.eof()); //Checks if end of file has been reached
  inFile.close();
  delete[] wb;
}
