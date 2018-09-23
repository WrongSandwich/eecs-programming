#include "Course.h"
#include <string>
#include <iostream>
//default Constructor
Course::Course()
{
  students = nullptr;
}

//Destructor
Course::~Course()
{
  delete[] students;
}

//SETTERS
void Course::setSize(int inputSize)
{
  courseSize = inputSize;
}

void Course::setNum(int inputNum)
{
  courseNum = inputNum;
}

void Course::setDept(std::string inputDept)
{
  dept = inputDept;
}

void Course::setStudents(int* inputStudents)
{
  students = inputStudents;
}

//GETTERS
int Course::getSize()
{
  return(courseSize);
}

int Course::getNum()
{
  return(courseNum);
}

std::string Course::getDept()
{
  return(dept);
}

int* Course::getStudents()
{
  return(students);
}

//Print functions
void Course::printCourse()
{
  std::cout << dept << " " << courseNum << '\n';
}

void Course::printSize()
{
  std::cout << courseSize;
}

void Course::printStudents()
{
  for(int i = 0; i < (courseSize - 1); i++)
  {
    std::cout << students[i] << ", ";
  }
  std::cout << students[courseSize - 1] << '\n';
}

//Search functions
bool Course::searchStudents(int searchID)
{
  for(int i = 0; i < courseSize; i++)
  {
    if (students[i] == searchID)
    {
      return(true);
    }
  }
  return(false);
}
