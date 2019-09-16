#ifndef REVIEW_H
#define REVIEW_H

#include <string>

struct Review
{
  std::string name;
  int rating;
  std::string price;
  bool deleted;
};

#endif
