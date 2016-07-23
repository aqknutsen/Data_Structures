/**
*	@file : main.cpp
*	@author : Alec Knutsen
*	@date : 2015.04.05
*	@brief: The main.cpp file gets commands from the command line. If we have more that five commands and a valid option (either -sort or -create) the commands are passed to the run method of SortDriver or NumberFileDriver.
*   @brief: If the commands are not valid, both the help menu of NumberFileDriver and SortDriver class are printed
*/


#include "NumberFileDriver.h" // We include NumberFileDriver so the user can create a file of numbers

#include "SortDriver.h" // We include SortDriver so the user can sort a file of numbers

#include <string> // We include the string library because we use strings

#include <iostream> // We include the iostream library to print data




/**
* @pre - We assume the run methods of the SortDriver class and NumberFileDriver class work properly.
* @pre - We assume commands from the command line are valid.
* @post - The main.cpp file gets commands from the command line. If we have more that five commands and a valid option (either -sort or -create) the commands are passed to the run method of SortDriver or NumberFileDriver. If the commands are not valid, both the help menu of NumberFileDriver and SortDriver class are printed
* @param - int argc - Number of commands from the command line, char** argc - Stores the commands from the command line
* @return - int - We return 0
*/
int main(int argc, char* argv[])
{

    NumberFileDriver test; // We create a stack allocated object of NumberFileDriver type

    SortDriver test1; // We create a stack allocated object of SortDriver type


    if (argc < 5) { // If we do not have five commands, this if statement runs. We print both help menus

        test.printHelpMenu();


        std::cout << " "<<std::endl;


        test1.printHelpMenu();

    }

    else { // If we have at least five commands we proceed

        std::string mode = argv[1]; // We store the mode (either -create or -sort)

        if (mode == "-create") {  // If the user wants to create a file, we use the run method form NumberFileDriver to do so.

            test.run(argc, argv); // If the user wants to create a file, we use the run method form NumberFileDriver to do so.


            std::cout << " "<<std::endl;

            std::cout<<"If a help menu was not printed, " << argv[4] << " numbers stored in " << argv[3] <<std::endl;

        }

        else if (mode == "-sort") { // If the user wants to sort a file, we use the run method form SortDriver to do so.


            std::cout<<"Calculating sort timing information... " <<std::endl;

            test1.run(argc, argv);

            std::cout << " "<<std::endl;

            std::cout<<"If a help menu was not printed, calculations finished, and results were stored in " << argv[4] <<std::endl;

            std::cout<<"Exiting..."<<std::endl;

        }

        else { // If the user does not enter a valid mode, we print both help menus

            test.printHelpMenu();

            test1.printHelpMenu();

        }

    }

}
