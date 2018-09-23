#ifndef DRIVERSLICENSERECORD_H
#define DRIVERSLICENSERECORD_H
#include <string>

class DriversLicenseRecord
{
  std::string firstName;
  std::string lastName;
  int age;
  char voterStatus;
  int licenseNumber;
public:
  void setFirstName(std::string f_Name);
  void setLastName(std::string l_Name);
  void setAge(int years);
  void setVoterStatus(char status);
  void setLicenseNumber(int number);
  std::string getFirstName();
  std::string getLastName();
  int getAge();
  char getVoterStatus();
  int getLicenseNumber();
};
#endif
