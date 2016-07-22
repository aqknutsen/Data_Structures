/**
*	@file main.cpp
*	@author John Gibbons
*	Updated 2015.04.17
*	@date 2014.10.02
*/


#include <iostream>
#include <fstream>
#include <vector>
#include "StackOfAnything.h"
#include "Test.h"
#include <sstream>


//Menu for your personal use. Not required for testing.
void printMenu()
{
	std::cout 	<< "\n\nSelect an action:\n"
			<< "1) Push onto stack\n"
			<< "2) Pop until\n"
			<< "3) Print the stack\n"
			<< "4) Quit\n"
			<< "Enter choice: ";
}

int main()
{

	Test test2(std::cout); 
	test2.runTests();



	return(0);
}
