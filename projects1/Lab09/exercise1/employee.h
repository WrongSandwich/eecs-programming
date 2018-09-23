#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class employee
{
private:
  int phoneNumber; //must be 7 digits
  std::string name; //cannot be empty string
  std::string department; //must be a valid department code
  //Valid department codes are "MARKETING", "R&D", "GLOBAL"
  double salary; //cannot be negative
public:
  bool setPhoneNumber(int num);
  bool setName(std::string name_);
  bool setDepartment(std::string dept);
  bool setSalary(double salary_);
  bool isSameDept(const employee& otherEmployee);
  int getPhoneNumber();
  std::string getName();
  std::string getDepartment();
  double getSalary();
};
#endif
