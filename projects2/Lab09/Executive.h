#ifndef EXECUTIVE
#define EXECUTIVE

#include "Task.h"
#include "BinarySearchTree.h"
#include <stdexcept>
#include "NotFoundException.h"
#include "InvalidSetEntryRequest.h"
#include <string>

class Executive
{
private:
  std::string* inputData;
  int dataLength;
  int pos;
  int execTime;
  BinarySearchTree<int, Task> taskTree;
public:
  Executive(std::string fileName);
  ~Executive();
  void treeMaker();
  //static void flush(Task& target);
};
#endif
