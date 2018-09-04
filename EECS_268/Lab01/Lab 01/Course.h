#ifndef COURSE_H
#define COURSE_H
#include <string>

class Course
{
private:
  std::string dept;
  int courseNum;
  int courseSize;
  int* students;
public:
  Course();
  ~Course();
  void setSize(int inputSize);
  void setNum(int inputNum);
  void setDept(std::string inputDept);
  void setStudents(int* inputStudents);
  int getSize();
  int getNum();
  std::string getDept();
  int* getStudents();
  void printCourse();
  void printSize();
  void printStudents();
  bool searchStudents(int searchID);
};

#endif
