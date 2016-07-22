/**
*	@file : NumberFileDriver.cpp
*	@author : Alec Knutsen
*	@date : 2015.04.05
*	@brief: Implementation of the NumberFileDriver.h file (see header file for method descriptions)
*/


#include "NumberFileDriver.h" // We include the corresponding NumberFileDriver.h file




void NumberFileDriver::run(int argc, char** argv) {


    NumberFileGenerator test; // We create a stack allocated object of type NumberFileGenerator


    int amount = atoi(argv[4]);  // We get the amount of numbers stored at the fifth command. atoi allows us to cast the command line stored to an int

    std::string file = argv[3]; // We get the inputFilename and the fourth command

    std::string option = argv[2]; // We get the type of file options (-a, -d, -r, -s) at the third command

    std::string create = argv[1]; // We get the second command (should be -create)

    if( create == "-create" && isValidOption(option) && amount > 0) { // If the user enters -create and a valid file command(-a,-r,-d,-s), and a valid amount this if statement runs


        if (option == "-a") { // If the user wants a file of ascending numbers, we call the ascending method from the NumberFileGenerator class

            test.ascending(file, amount);

        }

        else if (option == "-d") { // If the user wants a file of descending numbers, we call the descending method from the NumberFileGenerator class

            test.descending(file, amount);

        }

        else if (option == "-s") { // If the user wants a file of the same number amount of times, we call the singleValue method from the NumberFileGenerator class


              test.singleValue(file, amount, atoi(argv[5])); // We convert the amount of numbers we want stored to an int using atoi

        }

        else if (option == "-r") { // If the user wants a file of random numbers, we call the random method from the NumberFileGenerator class

                if (atoi(argv[5]) >= atoi(argv[6])) { // If min is greater than max, we print the helpMenu because this is an error. We also convert the commands specifing min and max to an int using atoi

                    printHelpMenu();

                }

                else { // If min is less than max, we call the random method

                    test.random(file, amount, atoi(argv[5]), atoi(argv[6])); // We also convert the commands specifing min and max to an int using atoi

                }

        } // End of inner else if block


    } // End of outer if statement


    else { // If one of the commands is invalid, we print the help menu

        printHelpMenu();
    }




}


void NumberFileDriver::printHelpMenu() {

    // The help menu

	std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
			<< "./prog -create -a filename amount\n"
			<< "./prog -create -d filename amount\n"
			<< "./prog -create -s filename amount value\n"
			<< "./prog -create -r filename amount min max\n"
			<< "Option explainations:\n"
			<< "\t-a for ascending\n"
			<< "\t-d for descending\n"
			<< "\t-s for a single value\n"
			<< "\t-r for random values\n"
			<< "\tfilename is the ouput file name\n"
			<< "\tamount is the amount of random numbers to place in the file\n"
			<< "\tvalue is the single number that will be written to file in -s mode\n"
			<< "\tmin is the low end of the range of random numbers\n"
			<< "\tmax is the high end (non-inclusive) of the range of random numbers\n";


}


bool NumberFileDriver::isValidOption(std::string option) {


    if ((option== "-a") || (option=="-d") || (option=="-s") || (option=="-r")) { // If the parameter is a valid file creation type we return true, otherwise, we return false

        return(true);

    }

    else {

        return(false);

    }

}
