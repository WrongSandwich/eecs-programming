#include "Directory.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <limits>

int arrSize = 1;

Directory::Directory(std::string fileName)
{
  std::ifstream inFile;
  inFile.open(fileName);
  if(inFile.is_open())
  {
    inFile >> arrSize;
    catalog = new Course[arrSize];
    std::string s;
    int x, classSize;
    int* tempStudents = nullptr;
    for (int i = 0; i < arrSize; i++)
    {
      inFile >> s;
      catalog[i].setDept(s);
      inFile >> x;
      catalog[i].setNum(x);
      inFile >> classSize;
      catalog[i].setSize(classSize);
      //Resetting the pointer each time for a new class's roster
      tempStudents = nullptr;
      //Creating a heap pointer for an array for a course's students
      tempStudents = new int[classSize];
      for (int j = 0; j < classSize; j++)
      {
        inFile >> tempStudents[j];
      }
      catalog[i].setStudents(tempStudents);
      delete[] tempStudents;
    }
    inFile.close();
  }
}

//Running the user interface
void Directory::run()
{
  int userChoice = 0;
  do
  {
    std::cout << "==========\nMENU\n==========\n";
    std::cout << "1. Print all courses\n2. Print all courses for";
    std::cout << " a department\n3. Print roster for a course\n4. Print largest class";
    std::cout << "\n5. Swap two classes\n6. Print schedule for student\n7. Exit\n";
    std::cout << "SELECT AN OPTION: ";
    std::cin >> userChoice;
    //Validation of user input.
    while (std::cin.fail())
    {
        std::cin.clear(); // unset failbit

        // skip bad input up to the next newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Sorry, your input did not seem to be an int. Try again: ";
        std::cin >> userChoice;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //Printing all course department and numbers
    if (userChoice == 1)
    {
      std::cout << "==========\nCATALOG\n==========\n";
      for (int i = 0; i < arrSize; i++)
      {
        catalog[i].printCourse();
      }
    }
    //Obtaining a department code from the user, then printing all courses within it
    else if (userChoice == 2)
    {
      std::string userDept;
      std::cout << "Enter a department code: ";
      std::cin >> userDept;
      std::cout << "==========\nCOURSES IN " << userDept << " DEPARTMENT\n";
      std::cout << "==========\n";
      //Creating a bool to check if any courses exist with the user code
      bool courseExists = false;
      for (int i = 0; i < arrSize; i++)
      {
        if (userDept == catalog[i].getDept())
        {
          courseExists = true;
          catalog[i].printCourse();
        }
      }
      //Telling the user if no such classes exist.
      if (courseExists == false)
      {
        std::cout << "No courses listed in that department.\n";
        std::cout << "Note: Make sure you use all caps.\n";
      }
    }
    //Obtaining a specific course from the user, then printing all student IDs
    else if (userChoice == 3)
    {
      std::string userDept;
      int userNum;
      bool courseExists = false;
      //Getting the user's search items
      std::cout << "Enter a department: ";
      std::cin >> userDept;
      std::cout << "Enter a course number: ";
      std::cin >> userNum;
      while (std::cin.fail())
      {
          std::cin.clear(); // unset failbit

          // skip bad input up to the next newline
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          std::cout << "Sorry, your input did not seem to be an int. Try again: ";
          std::cin >> userNum;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      //Searching the catalog for the correct course
      for (int i = 0; i < arrSize; i++)
      {
        if (userDept == catalog[i].getDept())
        {
          if (userNum == catalog[i].getNum())
          {
            courseExists = true;
            std::cout << "==========\nROSTER FOR " << userDept << " ";
            std::cout << userNum << "\n==========\n";
            catalog[i].printStudents();
          }
        }
      }
      //Telling user if course could not be found
      if (courseExists == false)
      {
        std::cout << "The course could not be found.\n";
      }
    }
    //Printing the name and size of the largest class in the catalog
    else if (userChoice == 4)
    {
      //Initializing variables with the first entry in the catalog
      int iMax = 0;
      int sizeMax = catalog[iMax].getSize();
      //Comparing current max with each catalog entry
      for (int i = 1; i < arrSize; i++)
      {
        if (catalog[i].getSize() > sizeMax)
        {
          iMax = i;
          sizeMax = catalog[iMax].getSize();
        }
      }
      //Printing the results
      std::cout << "The largest course is: ";
      catalog[iMax].printCourse();
      std::cout << "It has ";
      catalog[iMax].printSize();
      std::cout << " students\n";
    }
    //Obtaining two class names from the user and swapping their catalog positions
    else if (userChoice == 5)
    {
      std::string userDept1, userDept2;
      int userNum1, userNum2, i1, i2;
      bool course1Exists = false;
      bool course2Exists = false;
      //Getting the user's search items
      std::cout << "Enter the first department: ";
      std::cin >> userDept1;
      std::cout << "Enter the first course number: ";
      std::cin >> userNum1;
      while (std::cin.fail())
      {
          std::cin.clear(); // unset failbit

          // skip bad input up to the next newline
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          std::cout << "Sorry, your input did not seem to be an int. Try again: ";
          std::cin >> userNum1;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Enter the second department: ";
      std::cin >> userDept2;
      std::cout << "Enter the second course number: ";
      std::cin >> userNum2;
      while (std::cin.fail())
      {
          std::cin.clear(); // unset failbit

          // skip bad input up to the next newline
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          std::cout << "Sorry, your input did not seem to be an int. Try again: ";
          std::cin >> userNum2;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (userDept1 == userDept2 && userNum1 == userNum2)
      {
        std::cout << "ERROR: Please enter two unique courses\n";
      }
      else
      {
        //Finding the two search queries
        for (int i = 0; i < arrSize; i++)
        {
          if(catalog[i].getDept() == userDept1)
          {
            if(catalog[i].getNum() == userNum1)
            {
              i1 = i;
              course1Exists = true;
            }
          }
          if(catalog[i].getDept() == userDept2)
          {
            if(catalog[i].getNum() == userNum2)
            {
              i2 = i;
              course2Exists = true;
            }
          }
        }
        //Making sure both courses exist
        if (course1Exists == false)
        {
          std::cout << "ERROR: " << userDept1 << " " << userNum1;
          std::cout << " could not be found\n";
        }
        else if (course2Exists == false)
        {
          std::cout << "ERROR: " << userDept2 << " " << userNum2;
          std::cout << " could not be found\n";
        }
        else
        {
          //Switching the two courses
          int tempNum, tempSize;
          std::string tempDept;
          int* tempStudents = nullptr;
          //Saving data from course 1
          tempNum = catalog[i1].getNum();
          tempSize = catalog[i1].getSize();
          tempDept = catalog[i1].getDept();
          tempStudents = catalog[i1].getStudents();
          //Changing course 1 data to course 2
          catalog[i1].setNum(catalog[i2].getNum());
          catalog[i1].setSize(catalog[i2].getSize());
          catalog[i1].setDept(catalog[i2].getDept());
          catalog[i1].setStudents(catalog[i2].getStudents());
          //Putting stored data into course 2
          catalog[i2].setNum(tempNum);
          catalog[i2].setSize(tempSize);
          catalog[i2].setDept(tempDept);
          catalog[i2].setStudents(tempStudents);
          //Informing the user of success
          std::cout << "Courses successfully swapped\n";
        }
      }
    }
    //Obtaining a student ID from the user and printing all enrolled courses
    else if (userChoice == 6)
    {
      int searchID = 0;
      bool isEnrolled = false;
      bool courseExists = false;
      std::cout << "Enter a 5-digit student ID: ";
      std::cin >> searchID;
      while (std::cin.fail() || searchID < 10000 || searchID > 99999)
      {
          std::cin.clear(); // unset failbit

          // skip bad input up to the next newline
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          std::cout << "Sorry, your input did not seem to be a 5-digit int. Try again: ";
          std::cin >> searchID;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "==========\nCOURSE SCHEDULE FOR " << searchID << "\n==========\n";
      for (int i = 0; i < arrSize; i++)
      {
        isEnrolled = false;
        isEnrolled = catalog[i].searchStudents(searchID);
        if (isEnrolled == true)
        {
          catalog[i].printCourse();
          courseExists = true;
        }
      }
      //Telling user if no courses could be found
      if (courseExists = false)
      {
        std::cout << "No enrolled courses were found\n";
      }
    }
    //Exiting the program
    else if (userChoice == 7)
    {
      delete[] catalog;
      std::cout << "Exiting...\n";
    }
    //The user is an idiot and can't use a simple menu
    else
    {
        std::cout << "ERROR: Please input a valid menu option.\n";
    }
  } while (userChoice != 7);
}
