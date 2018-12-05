#ifndef _INVALID_SET_ENTRY_REQUEST
#define _INVALID_SET_ENTRY_REQUEST

#include <stdexcept>
#include <string>

using namespace std;

class InvalidSetEntryRequest : public runtime_error
{
public:
   InvalidSetEntryRequest(const string& message = "");
}; // end InvalidSetEntryRequest
#endif
