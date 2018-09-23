#include "employee.h"
#include "employeeDriver.h"
#include <string>
#include <iostream>

void employeeDriver::obtainEmployee(employee emp)
{
  bool advance = false; //bool used to control advancement
  //Getting a valid name
  std::cout << "Input Employee Information:\n";
  std::string name;
  do
  {
    std::cout << "Name: ";
    std::getline(std::cin, name);
    advance = emp.setName(name);
    if (advance == false)
    {
      std::cout << "Invalid\n";
    }
  } while(advance == false);
  advance = false; //Resetting advancement control
  //Getting a valid phone number
  int number = 0;
  do
  {
    std::cout << "Phone: ";
    std::cin >> number;
    advance = emp.setPhoneNumber(number);
    if (advance == false)
    {
      std::cout << "Invalid\n";
    }
  } while(advance == false);
  advance = false; //Resetting advancement control
  //Getting a valid salary
  double salary = 0;
  do
  {
    std::cout << "Salary: ";
    std::cin >> salary;
    advance = emp.setSalary(salary);
    if (advance == false)
    {
      std::cout << "Invalid\n";
    }
  } while(advance == false);
  advance = false; //Resetting advancement control
  //Getting a valid department
  std::string dept;
  do
  {
    std::cout << "Department: ";
    std::cin >> dept;
    advance = emp.setDepartment(dept);
    if (advance == false)
    {
      std::cout << "Invalid\n";
    }
  } while(advance == false);
}

void employeeDriver::printEmployeeInfo(employee emp1, employee emp2)
{
  //Printing emp1's info.
  std::cout << "Employee 1:\nName: " << emp1.getName() << '\n';
  std::cout << "Phone: " << emp1.getPhoneNumber() << '\n';
  std::cout << "Salary: " << emp1.getSalary() << '\n';
  std::cout << "Department: " << emp1.getDepartment() << '\n\n';
  //Printing emp2's info.
  std::cout << "Employee 2:\nName: " << emp2.getName() << '\n';
  std::cout << "Phone: " << emp2.getPhoneNumber() << '\n';
  std::cout << "Salary: " << emp2.getSalary() << '\n';
  std::cout << "Department: " << emp2.getDepartment() << '\n\n';
  //Printing whether or not the two employees work in same dept.
  if (emp1.isSameDept(emp2) == true)
  {
    std::cout << "The employees work in the same department.\n";
  }
  else
  {
    std::cout << "The employees do not work in the same department.\n";
  }
}

void employeeDriver::run()
{
  obtainEmployee(emp1);
  obtainEmployee(emp2);
  printEmployeeInfo(emp1, emp2);
}
