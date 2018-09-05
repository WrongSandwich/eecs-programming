#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <string>
#include "Course.h"

class Directory
{
private:
  std::string fileName;
  Course* catalog;
public:
  /* @pre fileName is valid
  * @post Reads given file to an array of Courses, then closes the file and starts run()
  */
  Directory(std::string fileName);

  /* @pre None
  * @post Runs the user menu and handles interactions with user and courseSize
  */
  void run();
};

#endif
