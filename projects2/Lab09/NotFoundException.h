/*******************************************************************************
*@author  Evan Trout
*@file    NotFoundException.h
*@date    12/06/18
*@brief   Header file for NotFoundException, a custom error for when
*         BinarySearchTree is unable to find a key in its tree.
*******************************************************************************/

#ifndef _NOT_FOUND_EXCEPTION
#define _NOT_FOUND_EXCEPTION

#include <stdexcept>
#include <string>

using namespace std;

class NotFoundException : public runtime_error
{
public:
   NotFoundException(const string& message = "");
}; // end NotFoundException
#endif
