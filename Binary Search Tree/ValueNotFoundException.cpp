/**
*	@file :ValueNotFoundException.cpp
*	@author : Alec Knutsen
*	@date : 2015.04.13
*	@brief: Implementation of the ValueNotFoundException.h file (see header file for constructor description)
*/



#include "ValueNotFoundException.h" // We include our "ValueNotFoundException.h" file

ValueNotFoundException::ValueNotFoundException(const char* message) :  std::runtime_error(message) { // We use the message passed in as a parameter to the constructor and an initalization list to pass message to the constructor of std::runtime_error
}
