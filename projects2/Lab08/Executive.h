#ifndef EXECUTIVE
#define EXECUTIVE

#include <string>

class Executive
{
private:
  std::string* expression;
  int expLength;
public:
  Executive(std::string type, std::string fileName);
  void printTreePreorder(BinaryNodeTree<std::string> bt);
  void printTreeInorder(BinaryNodeTree<std::string> bt);
  void printTreePostorder(BinaryNodeTree<std::string> bt);
};
#endif
