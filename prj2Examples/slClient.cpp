#include <iostream>
#include <string>
#include "SLNode.h"

//Missing cpp for SLnode, I guess it was in an earlier class?

SLNode<std::string>* add1(SLNode<std::string>* head, std::string str)
{
  if (head == nullptr)
    head = new SLNode<std::string>(str);
  else
    //This constructor sets current name as new head of chain, points to previous head
    head = new SLNode<std::string>(str, head);
  return head;
}

SLNode<std::string>* add2(SLNode<std::string>* head, std::string str)
{
  if (head == nullptr)
    head = new SLNode<std::string>(str);
  else
  {
    //Always adds a new node to the end of the list
    SLNode<std::string>* cur = head;
    SLNode<std::string>* prev = nullptr;
    while (cur != nullptr)
    {
      prev = cur;
      cur = cur->getNext();
    }
    prev->setNext(new SLNode<std::string>(str));
  }
  return head;
}

void print(SLNode<std::string>* h)
{
  while (h != nullptr)
  {
    std::cout << h->getItem() << '';
    h = h->getNext();
  }
  std::cout << '\n';
}

int main(int argc, char* argv[])
{
  std::string names[] = {
    "chris", "book", "garage", "airplane", "bad", "good"
  };
  SLNode<std::string>* head = nullptr;
  for (int i = 0; i < 6; i+=2)
  {
    head = add1(head, names[i]);
    head = add2(head, names[i+1]);
  }
  print (head);
  return 0;
}
