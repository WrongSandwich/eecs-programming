#include "DriversLicenseRecord.h"
#include "DMV.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <limits>

void DMV::userMenu()
{
  int userChoice;
  do
  {
    //Showing menu and getting user's choice
    std::cout << "Select an option:\n1) Print all drivers' info\n";
    std::cout << "2) Print all voters\n3) Print drivers by last initial\n";
    std::cout << "4) Print drivers in age range\n5) Quit\nEnter your choice: ";
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
    //Print all drivers' info
    if (userChoice == 1)
    {
      for (int i = 0; i < size; i++)
      {
        std::cout << records[i].getLastName() << ", ";
        std::cout << records[i].getFirstName() << " (";
        std::cout << records[i].getAge() << "): ";
        std::cout << records[i].getLicenseNumber() << '\n';
      }
    }
    //Print all voters
    else if (userChoice == 2)
    {
      for (int i = 0; i < size; i++)
      {
        if (records[i].getVoterStatus() == 'Y')
        {
          std::cout << records[i].getLastName() << ", ";
          std::cout << records[i].getFirstName() << " (";
          std::cout << records[i].getAge() << "): ";
          std::cout << records[i].getLicenseNumber() << '\n';
        }
      }
    }
    //Print by last initial
    else if (userChoice == 3)
    {
      char charSearch;
      int count = 0;
      std::cout << "Enter last initial search: ";
      std::cin >> charSearch;
      if (islower(charSearch))
      {
        charSearch = toupper(charSearch);
      }
      std::string nameSearch;
      for(int i = 0; i < size; i++)
      {
        nameSearch = records[i].getLastName();
        if (charSearch == nameSearch.at(0))
        {
          std::cout << records[i].getLastName() << ", ";
          std::cout << records[i].getFirstName() << " (";
          std::cout << records[i].getAge() << "): ";
          std::cout << records[i].getLicenseNumber() << '\n';
          count++;
        }
      }
      if (count == 0)
      {
        std::cout << "No record found.\n";
      }
    }
    //Print in age range
    else if (userChoice == 4)
    {
      int num1, num2;
      int count = 0;
      std::cout << "Please enter an age range to search:\nFirst age: ";
      std::cin >> num1;
      //Validation of user input.
      while (std::cin.fail())
      {
          std::cin.clear(); // unset failbit

          // skip bad input up to the next newline
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          std::cout << "Sorry, your input did not seem to be an int. Try again: ";
          std::cin >> num1;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Second age: ";
      std::cin >> num2;
      //Validation of user input.
      while (std::cin.fail())
      {
          std::cin.clear(); // unset failbit

          // skip bad input up to the next newline
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          std::cout << "Sorry, your input did not seem to be an int. Try again: ";
          std::cin >> num2;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if(num2 < num1)
      {
        int num3 = num2;
        num2 = num1;
        num1 = num3;
      }
      for(int i = 0; i < size; i++)
      {
        if(records[i].getAge() >= num1 && records[i].getAge() <= num2)
        {
          std::cout << records[i].getLastName() << ", ";
          std::cout << records[i].getFirstName() << " (";
          std::cout << records[i].getAge() << "): ";
          std::cout << records[i].getLicenseNumber() << '\n';
          count++;
        }
      }
      if (count == 0)
      {
        std::cout << "No record found.\n";
      }
    }
    //Quit
    else if (userChoice == 5)
    {
      std::cout << "Exiting\n";
    }
    //Incorrect menu choice
    else
    {
        std::cout << "ERROR: Please enter a valid menu choice\n";
    }
  } while(userChoice != 5);
}

void DMV::setSize(int arrSize)
{
  if (arrSize > 0)
  {
    size = arrSize;
  }
}

DMV::DMV(std::string fileName)
{
  std::ifstream inFile;
  inFile.open(fileName);
  if (inFile.is_open())
  {
    int arrSize, years, number;
    std::string f_Name, l_Name;
    char status;
    inFile >> arrSize;
    setSize(arrSize);
    records = new DriversLicenseRecord[size];
    for(int i = 0; i < size; i++)
    {
      inFile >> f_Name;
      records[i].setFirstName(f_Name);
      inFile >> l_Name;
      records[i].setLastName(l_Name);
      inFile >> years;
      records[i].setAge(years);
      inFile >> status;
      records[i].setVoterStatus(status);
      inFile >> number;
      records[i].setLicenseNumber(number);
    }
    inFile.close();
  }
}

void DMV::run()
{
  userMenu();
}

DMV::~DMV()
{
  delete[] records;
}
