/*******************************************************************************
*@author  Frank M. Carrano, Tim Henry
*@file    PrecondViolationExcep.h
*@date    2013
*@brief   Defines an exception for when a precondition is violated.
*******************************************************************************/

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Listing 7-5.
    @file PrecondViolationExcep.h */

#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolationExcep : public logic_error
{
public:
   PrecondViolationExcep(const string& message = "");
}; // end PrecondViolationExcep
#endif
