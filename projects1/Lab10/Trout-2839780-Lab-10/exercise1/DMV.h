#ifndef DMV_H
#define DMV_H
#include <string>
#include "DriversLicenseRecord.h"

class DMV
{
  int size;
  DriversLicenseRecord* records;
  void userMenu();
public:
  DMV(std::string fileName);
  void run();
  void setSize(int arrSize);
  ~DMV();
};
#endif
