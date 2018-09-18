//Need to create a WebBrowser in this code


Exec::Exec(std::string fileName)
{
  std::ifstream inFile;
  inFile.open(fileName);
  if(inFile.is_open())
  {
    WebBrowser();
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

    }
    //BACK
    else if (command == "BACK")
    {

    }
    //FORWARD
    else if (command == "FORWARD")
    {

    }
    //HISTORY
    else if (command == "HISTORY")
    {

    }
    else
    {
      
    }
  } while(!inFile.eof()); //Checks if end of file has been reached
}
