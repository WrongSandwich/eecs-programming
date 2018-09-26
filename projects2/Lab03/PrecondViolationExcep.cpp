/*******************************************************************************
*@author  Frank M. Carrano, Tim Henry
*@file    PrecondViolationExcep.cpp
*@date    2013
*@brief   Defines an exception for when a precondition is violated.
*******************************************************************************/

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Listing 7-6.
    @file PrecondViolationExcep.cpp */
#include "PrecondViolationExcep.h"

PrecondViolationExcep::PrecondViolationExcep(const string& message): logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.
