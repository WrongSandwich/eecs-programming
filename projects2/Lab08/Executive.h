#ifndef EXECUTIVE
#define EXECUTIVE

#include <string>
#include "BinaryNodeTree.h"
#include "Stack.h"
#include "PrecondViolationExcep.h"

class Executive
{
private:
  std::string* expression;
  int expLength;
  int pos;
  BinaryNodeTree<std::string>* execTreePtr;
  Stack<BinaryNodeTree<std::string>*> treeStack;
public:
  Executive(std::string type, std::string fileName);
  ~Executive();
  BinaryNodeTree<std::string>* prefixTreeMaker();
  BinaryNodeTree<std::string>* postfixTreeMaker();
  void printTreePreorder(BinaryNodeTree<std::string> bt);
  void printTreeInorder(BinaryNodeTree<std::string> bt);
  void printTreePostorder(BinaryNodeTree<std::string> bt);
};
#endif
