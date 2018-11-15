#ifndef EXECUTIVE
#define EXECUTIVE

#include "Task.h"
#include "BinarySearchTree.h"
#include <string>

class Executive
{
private:
  std::string* inputData;
  int dataLength;
  int pos;
  int time;
  BinarySearchTree<taskID, Task>* taskTree;
public:
  Executive(std::string fileName);
};
#endif
