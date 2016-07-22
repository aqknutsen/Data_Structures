/**
*	@file main.cpp
*	@author John Gibbons
*	@date 2014.02.02
*/
 
#include <iostream>
#include <stdexcept>
#include <string>
#include "Queue.h"
#include "Test3.h"

//Menu for your personal use. Not required for testing.
void printMenu()
{
	std::cout 	<< "\n\nSelect an action:\n"
			<< "1) Enqueue a number\n"
			<< "2) Dequeue a number\n" 
			<< "3) Send next to back of line\n"
			<< "4) Print\n"
			<< "5) Quit\n"
			<< "Enter choice: ";
}


int main()
{
	
	//WARNING: The test class may hang or segfault if ran while methods 
	//are empty.
	Test3 t3(std::cout);
	t3.testQueue();
}
