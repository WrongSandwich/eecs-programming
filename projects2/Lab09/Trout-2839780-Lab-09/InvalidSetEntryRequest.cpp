/*******************************************************************************
*@author  Evan Trout
*@file    InvalidSetEntryRequest.cpp
*@date    12/06/18
*@brief   Implementation file for InvalidSetEntryRequest, a custom error for
*         when aKey and item do not match for the setEntry function in the
*         BinarySearchTree class.
*******************************************************************************/

#include "InvalidSetEntryRequest.h"

InvalidSetEntryRequest::InvalidSetEntryRequest(const string& message): runtime_error("Invalid Set Entry Request: " + message)
{
}
