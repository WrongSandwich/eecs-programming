#ifndef EXEC_H
#define EXEC_H
#include <string>
#include "WebBrowser.h"

class Exec
{
private:
  std::string fileName;
  WebBrowser wb;
  std::string* commArray;
  int size;
public:
  Exec(std::string fileName);
  void run();
};

#endif
