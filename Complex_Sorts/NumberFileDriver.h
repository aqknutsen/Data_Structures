/**
*	@file : NumberFileDriver.h
*	@author : Alec Knutsen
*	@date : 2015.04.05
*	@brief: This class contains the run methods which will create a file of ascending, descending, random, or the same number of numbers. If commands are invalid, the helpMenu will be printed
*/


#include <string> // We include the <string> library since we use strings

#include <iostream> // We include the <iostream> library to print data


#include <cstdlib> // The <cstdlib> allows us to convert values from argv into ints. We use this so we can get the number of numbers from the command line and convert it to an int.

#include "NumberFileGenerator.h" // We include the NumberFileGenerator.h file so we can use its methods

#ifndef NUMBERFILEDRIVER_H
#define NUMBERFILEDRIVER_H


class NumberFileDriver {

public:



    /**
    * @pre - We assume the ascending, descending, random, and singleValue methods from NumberFileGenerator work properly.
    * @pre - We assume the isValidOption and printHelpMenu methods work properly
    * @pre - We assume argc, and argv are passed from main and contain valid commands specified by the help menu. We assume the <cstdlib> works properly
    * @post - If all methods are valid this method will create a file with numbers in ascending, descending order, random numbers, or an amount of the same number. If the commands are invalid, the helpMenu is printed.
    * @param - int argc - Number of commands from the command line, char** argc - Stores the commands from the command line
    * @return -  None
    */
    static void run(int argc, char** argv);


    /**
    * @pre - None
    * @post - Prints a help menu for creating a file of numbers
    * @param - None
    * @return - None
    */
    static void printHelpMenu();

private:


    /**
    * @pre - We assume option is a valid string
    * @post - This method returns true if option is -a, -d, -r, -s. Otherwise, it returns false
    * @param - std::string option - Represents the option for entering numbers in a file
    * @return - bool - This method returns true if option is -a, -d, -r, -s. Otherwise, it returns false
    */
    static bool isValidOption(std::string option);




};

#endif // NUMBERFILEDRIVER_H
