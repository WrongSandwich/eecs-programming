#include "employee.h"
#include <string>

bool employee::setPhoneNumber(int num)
{
  if(num >= 1000000 && num < 10000000)
  {
    phoneNumber = num;
    return(true);
  }
  else
  {
    return(false);
  }
}

bool employee::setName(std::string name_)
{
  if (name_.length()>0)
  {
    name = name_;
    return(true);
  }
  else
  {
    return(false);
  }
}

bool employee::setDepartment(std::string dept)
{
  if (dept == "MARKETING" || dept == "R&D" || dept == "GLOBAL")
  {
    department = dept;
    return(true);
  }
  else
  {
    return(false);
  }
}

bool employee::setSalary(double salary_)
{
  if (salary_ >= 0)
  {
    salary = salary_;
    return(true);
  }
  else
  {
    return(false);
  }
}

bool employee::isSameDept(const employee& otherEmployee)
{
  if(department == otherEmployee.department)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

int employee::getPhoneNumber()
{
  return(phoneNumber);
}

std::string employee::getName()
{
  return(name);
}

std::string employee::getDepartment()
{
  return(department);
}

double employee::getSalary()
{
  return(salary);
}
