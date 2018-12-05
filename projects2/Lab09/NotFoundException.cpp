#include "NotFoundException.h"

NotFoundException::NotFoundException(const string& message): runtime_error("Not Found Exception: " + message)
{
}
