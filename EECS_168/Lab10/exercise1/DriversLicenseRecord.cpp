#include "DriversLicenseRecord.h"
#include <string>

void DriversLicenseRecord::setFirstName(std::string f_Name)
{
  if (f_Name.length()>0)
  {
    firstName = f_Name;
  }
}

void DriversLicenseRecord::setLastName(std::string l_Name)
{
  if (l_Name.length()>0)
  {
    lastName = l_Name;
  }
}

void DriversLicenseRecord::setAge(int years)
{
  if (years >= 16 && years < 150)
  {
    age = years;
  }
}

void DriversLicenseRecord::setVoterStatus(char status)
{
  if (status == 'Y' || status == 'N')
  {
    voterStatus = status;
  }
}

void DriversLicenseRecord::setLicenseNumber(int number)
{
  if (number >= 100000 && number < 1000000)
  {
    licenseNumber = number;
  }
}

std::string DriversLicenseRecord::getFirstName()
{
  return(firstName);
}

std::string DriversLicenseRecord::getLastName()
{
  return(lastName);
}

int DriversLicenseRecord::getAge()
{
  return(age);
}

char DriversLicenseRecord::getVoterStatus()
{
  return(voterStatus);
}

int DriversLicenseRecord::getLicenseNumber()
{
  return(licenseNumber);
}
