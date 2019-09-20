#ifndef REVIEW_H
#define REVIEW_H

#include <string>

struct Review
{
  std::string name;
  int rating;
  std::string price;
  bool deleted;

  // std::string toString() {
  //   return ("name = " + name + ", rating = " + std::to_string(rating) + ", price = " + price + '\n');
  // }
};

#endif
