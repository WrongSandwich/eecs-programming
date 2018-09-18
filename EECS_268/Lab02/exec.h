#ifndef EXEC_H
#define EXEC_H
#include <string>

class Exec
{
private:
  std::string fileName;
  std::string* commList;
public:
  Exec(std::string fileName);
  void run();
};

#endif
