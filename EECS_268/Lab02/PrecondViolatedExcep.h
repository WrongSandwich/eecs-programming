#include <stdexcept>
#include <string>
class PrecondViolatedExcep: public std::exception
{
public:
  PrecondViolatedExcep(const std::string& message = "")
  {}
};
