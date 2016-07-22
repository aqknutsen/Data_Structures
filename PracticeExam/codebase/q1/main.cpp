/**
*	@file main.cpp
*	@date 2014.02.23
*	Updated 2015.04.17
*	@author John Gibbons
*/

#include <iostream>
#include "DoubleLinkedList.h"
#include "Test.h"


//Menu for your personal use. Not required for testing.
void printMenu()
{
	std::cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) insert ahead of a value\n"
		<<	"3) Print \n"
		<<	"4) print Reverse\n"
		<<	"5) Quit\n"
		<< 	"Your choice: ";
}

int main()
{

	Test t(std::cout);
	t.runTests();
}
