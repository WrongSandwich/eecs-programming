/*******************************************************************************
*@author  Evan Trout
*@file    InvalidSetEntryRequest.h
*@date    12/06/18
*@brief   Header file for InvalidSetEntryRequest, a custom error for
*         when aKey and item do not match for the setEntry function in the
*         BinarySearchTree class.
*******************************************************************************/

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
