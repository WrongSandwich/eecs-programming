#ifndef CHECKER_H
#define CHECKER_H

class Checker
{
private:
  std::string fileName;
  std::string str;
public:
  Checker(std::string fileName);
  void run();
}
