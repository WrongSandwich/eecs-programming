#include "InvalidSetEntryRequest.h"

InvalidSetEntryRequest::InvalidSetEntryRequest(const string& message): runtime_error("Invalid Set Entry Request: " + message)
{
}
