#ifndef EXECUTIVE
#define EXECUTIVE

#include <string>
#include "BinaryNodeTree.h"

class Executive
{
private:
  std::string* expression;
  int expLength;
  BinaryNodeTree<std::string> execTree;
  Stack<BinaryNodeTree> treeStack;
public:
  Executive(std::string type, std::string fileName);
  void printTreePreorder(BinaryNodeTree<std::string> bt);
  void printTreeInorder(BinaryNodeTree<std::string> bt);
  void printTreePostorder(BinaryNodeTree<std::string> bt);
};
#endif
