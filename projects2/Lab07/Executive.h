#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>

class Executive
{
private:
  double* array;
  int data_size;
  std::string algorithm_name;
  std::string data_order;
public:
  Executive(std::string data_size, std::string array_order, std::string algName);
  ~Executive();
  double* randomArray();
  double* ascendingArray();
  double* descendingArray();
  void run();
  double searchTimer();
};

#endif
