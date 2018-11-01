#ifndef EXECUTIVE
#define EXECUTIVE

#include <string>

class Executive
{
private:
public:
  void printTreePreorder(BinaryNodeTree<std::string> bt);
  void printTreeInorder(BinaryNodeTree<std::string> bt);
  void printTreePostorder(BinaryNodeTree<std::string> bt);
};
#endif
