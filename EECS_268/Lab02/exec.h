#ifndef EXEC_H
#define EXEC_H
#include <string>
#include "WebBrowser.h"

class Exec
{
private:
  std::string fileName;
  WebBrowser wb;
public:
  Exec(std::string fileName);
  void run();
};

#endif
