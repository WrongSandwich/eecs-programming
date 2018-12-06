/*******************************************************************************
*@author  Evan Trout
*@file    NotFoundException.cpp
*@date    12/06/18
*@brief   Implementation file for NotFoundException, a custom error for when
*         BinarySearchTree is unable to find a key in its tree.
*******************************************************************************/

#include "NotFoundException.h"

NotFoundException::NotFoundException(const string& message): runtime_error("Not Found Exception: " + message)
{
}
