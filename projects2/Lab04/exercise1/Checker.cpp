



Checker::Checker(std::string fileName) throw std::runtime_error
{
  std::ifstream inFile;
  inFile.open(fileName); //Open given file
  if(inFile.is_open())
  {
    inFile >> str;
    inFile.close();
  }
  else throw std::runtime_error("File could not be opened!");
}

void Checker::run()
{
  int length = str.size();
  if ((length % 2) != 0)//Checking if string is an even number
  {
    std::cout << "The sequence " << str << "is not balanced\n";
  }
  else
  {
    test();
  }
}

void Checker::test()
