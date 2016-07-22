/**
*	@file :MazeCreationException.h
*	@author : Alec Knutsen
*	@date : 2015.04.18
*	@brief:This class uses a constructor to pass an error message to the constructor of std::runtime_error
*/




#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H


#include <stdexcept> // We include the <stdexcept> library which std::runtime_error is a derived class of std::exception


class MazeCreationException: public std::runtime_error { // We make the MazeCreationException class inherit from std::runtime_error which inherits from std::exception


public:



    /**
     * @pre - We assume a valid message is passed in
     * @post - This constructor passes the message to the constructor of std::runtime_error
     * @param - const char* message - Represents the error message to be passed to the std::runtime_error
     */
   MazeCreationException(const char* message);
};

#endif
