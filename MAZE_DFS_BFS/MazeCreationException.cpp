/**
*	@file :MazeCreationException.cpp
*	@author : Alec Knutsen
*	@date : 2015.04.18
*	@brief: Implementation of the azeCreationException.h file (see header file for constructor description)
*/



#include "MazeCreationException.h" // We include our corresponding "MazeCreationException.h" file

MazeCreationException::MazeCreationException(const char* message) :  std::runtime_error(message) { // We use the message passed in as a parameter to the constructor and an initalization list to pass message to the constructor of std::runtime_error
}

