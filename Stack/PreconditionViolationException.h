/**
*	@file : PreconditionViolationException.h
*	@author : Alec Knutsen
*	@date : 2014.02.26
*	@brief: This class uses the constructor of PreconditionViolationException to pass an error message to the constructor of std::runtime_error
*/


/**
* The ifndef, define block is used to avoid redefintion and other errors that can occur
* during compilation.
* NOTE: the #endif at the end of the file.
*/


#ifndef PRECONDITIONVIOLATIONEXCEPTION_H
#define PRECONDITIONVIOLATIONEXCEPTION_H

#include <stdexcept> // We include the <stdexcept> library which std::runtime_error is a derived class of std::exception


class PreconditionViolationException: public std::runtime_error { // We make the PreconditionViolationException class inherit from std::runtime_error which inherts from std::exception


public:



    /**
     * @pre - None
     * @post - This constructor passes the message to the constructor of std::runtime_error
     * @param - const char* message - Represents the error message to be passed to the std::runtime_error
     */
    PreconditionViolationException(const char* message); // We use the constructor of PreconditionViolationException to pass an error message to the constructor of std::runtime_error

};

#endif
