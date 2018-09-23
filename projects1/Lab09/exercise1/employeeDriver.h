#ifndef EMPLOYEEDRIVER_H
#define EMPLOYEEDRIVER_H
#include "employee.h"

class employeeDriver
{
private:
  employee emp1;
  employee emp2;
  void obtainEmployee(employee emp);
  void printEmployeeInfo(employee emp1, employee emp2);
public:
  void run();
};

#endif
