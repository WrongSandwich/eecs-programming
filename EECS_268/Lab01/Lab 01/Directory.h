#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <string>
#include "Course.h"

class Directory
{
private:
  std::string fileName;
  Course* catalog;
public:
  Directory(std::string fileName);
  void run();
};

#endif
