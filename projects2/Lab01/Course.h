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
  /* @pre None
  * @post Creates an uninitialized Course (default constructor)
  */
  Course();

  /* @pre None
  * @post The students array is deleted
  */
  ~Course();

  /* @pre inputSize is valid
  * @post sets courseSize of course to given value
  */
  void setSize(int inputSize);
  /* @pre inputNum is valid
  * @post sets courseNum of course to given value
  */
  void setNum(int inputNum);

  /* @pre inputDept is valid
  * @post sets dept of course to given value
  */
  void setDept(std::string inputDept);

  /* @pre inputStudents is valid
  * @post students points to the same heap array as inputStudents
  */
  void setStudents(int* inputStudents);

  /* @pre None
  * @post None
  * @return Returns size of course (number of students)
  */
  int getSize();

  /* @pre None
  * @post None
  * @return Returns 3-digit course number
  */
  int getNum();

  /* @pre None
  * @post None
  * @return Returns department code of course
  */
  std::string getDept();

  /* @pre None
  * @post None
  * @return Returns pointer to the array of students in this courseNum
  */
  int* getStudents();

  /* @pre None
  * @post Prints the department code and course number with formatting
  */
  void printCourse();

  /* @pre None
  * @post Prints the size of the course with formatting
  */
  void printSize();

  /* @pre None
  * @post Prints all the student IDs for the course with formatting
  */
  void printStudents();

  /* @pre Valid search ID
  * @return Returns true if searchID is found in course, false if not
  */
  bool searchStudents(int searchID);
};

#endif
