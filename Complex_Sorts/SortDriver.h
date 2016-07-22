/**
*	@file : SortDriver.h
*	@author : Alec Knutsen
*	@date : 2015.04.05
*	@brief: This class contains methods that will very commands. If commands are valid, it will do a sort on an inputFile and store the timing of the sort in an Outpufile.
*/



#include "Sorts.h" // We include Sorts to use sorting methods and timing methods




#include <iostream> // We include the iostream library to print data.

#include <iomanip> // We include the iomanip library to format our timing data

#include <string> // We include the string library to use strings


#include <fstream> // We use the fstream library for file data





#ifndef SORTDRIVER_H
#define SORTDRIVER_H




class SortDriver {


public:

    /**
    * @pre - We assume argv contains valid commands (first is executable name, second is sort, third is type of sort, and fourth is the input file.
    * @pre - We assume the areParametersValid method,isSortedValid, getFileCount, createArray, and copyArray methods work properly
    * @pre - We assume all sorting methods work properly from Sorts.h and sortTimer from Sorts.h works properly. Finally, we assume the <iomanip> library sets the precision of numbers properly.
    * @pre - We assume arc and argv are passed directly from main.
    * @pre - This method verifies that all commands are valid. If the commands are not valid, the helpMenu is printed. If the commands are valid, we do the appropriate sort, time the information, and put it in an output file
    * @param - int argc - Number of commands from the command line, char** argc - Stores the commands from the command line
    * @return -  None
    */
    static void run(int argc, char** argv);


    /**
    * @pre - None
    * @post - Prints a help menu for valid sorting commands
    * @param - None
    * @return - None
    */
    static void printHelpMenu();


private:


    /**
    * @pre - We assume std::string fileName is a valid string. We also assume fileName was created by NumberFileGenerator. We assume the good method of the <fstream> library works
    * @post - This method returns true if the file is found, otherwise it returns false
    * @param - std::string fileName - File to be read in
    * @return - bool - This method returns true if the file is found, otherwise it returns false
    */
    static bool isFileAcessible(std::string fileName);


    /**
    * @pre - We assume sortParameter is a valid string
    * @post - Returns true if sortParameter is -sort. Otherwise, returns false
    * @param - std::string sortParameter - Option selected by the user
    * @return - bool - Returns true if sortParameter is -sort. Otherwise, returns false
    */
    static bool isSortedValid(std::string sortParameter);



    /**
    * @pre - We assume sortName and inputFileName are valid strings. We assume the isFileAccessible methods works properly.
    * @post - This method returns true if an accessible file is found, and a valid sort option is chosen (bubble,insertion,merge, quick, quick with median, and selection). Otherwise, it returns false
    * @param - std::string sortName - Represents the type of sort to attempt, std::string inputFileName - Represents the file to be sorted
    * @return - bool - Returns true if sortName and inputFileName are valid. Otherwise, it returns false.
    */
    static bool areParametersValid(std::string sortName, std::string inputFileName);



    /**
    * @pre - We assume inputFile is a valid file created by Number File Generator.
    * @post - This file returns an integer representing the amount of numbers in the file.
    * @param - std::ifstream& inputFile - Input file to be read in
    * @return - int - Representing the number of integers in the file
    */
    static int getFileCount(std::ifstream& inputFile);



    /**
    * @pre - We assume the inputFile was created by Number File Generator. We assume size is valid integer
    * @post - The values from inputFile are copied into an integer array. The file is not closed. A pointer to the array is returned.
    * @param - std::ifstream& inputFile - Input file to be read in, int size - Size of the array to be created
    * @return - int* - Pointer to array created
    */
    static int* createArray(std::ifstream& inputFile, int size);



    /**
    * @pre - We assume original and copy are valid integer arrays with a valid int size
    * @post - All values from original are copied into copy
    * @param - int original[] - Contains values to be copied, int copy[] - Will contain copied values, int size - Size of both arrays
    * @return - None
    */
    static void copyArray(int original[], int copy[], int size);



};

#endif // SORTDRIVER_H
