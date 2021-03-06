/**
*	@file : PreconditionViolationException.cpp
*	@author :  Alec Knutsen
*	@date : 2014.02.26
*	@brief: Implentation of the PreconditionViolationException class
*/

#include "PreconditionViolationException.h" // We include our "PreconditionViolationException.h" file

PreconditionViolationException::PreconditionViolationException(const char* message) :    std::runtime_error(message) { // We use the message passed in as a parameter to the constructor and an initalization list to pass message to the constructor of std::runtime_error
}
