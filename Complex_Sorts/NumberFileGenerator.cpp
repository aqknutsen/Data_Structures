/**
*	@file : NumberFileGenerator.cpp
*	@author : Alec Knutsen
*	@date : 2015.04.05
*	@brief: Implementation of the NumberFileGenerator.h file (see header file for method descriptions)
*/


#include "NumberFileGenerator.h" // We include the corresponding NumberFileGenerator.h file


void NumberFileGenerator::ascending(std::string fileName, int amount) {


    std::ofstream myOutputFile(fileName); // We create an outputFile



    myOutputFile << amount << "\n"; // We store the amount of numbers in the top of the file


    for (int i=0; i < amount; i++) { // This loop puts numbers in our file from 0 to amount-1 inclusive


        myOutputFile <<  i << "\n";

    } // End of for loop



    myOutputFile.close(); // We close the output file



}


void NumberFileGenerator::descending(std::string fileName, int amount) {

     std::ofstream myOutputFile(fileName); // We create an outputFile


     myOutputFile << amount << "\n"; // We store the amount of numbers in the top of the file


    for (int i = amount-1; i >= 0; i--) { // This loop puts numbers in our file from amount-1 to 0 inclusive

            myOutputFile <<  i << "\n";

    } // End of for loop

    myOutputFile.close(); // We close the output file



}

void NumberFileGenerator::random(std::string fileName, int amount, int min, int max) {

    std::ofstream myOutputFile(fileName); // We create an outputFile


    std::default_random_engine generator(time(nullptr)); // We declare a generator and seed the generator


    std::uniform_int_distribution<int> distribution(min,max); // We declare a distribution, and set the min and max of the distribution to the parameters passed in

    myOutputFile << amount << "\n"; // We store the amount of numbers in the top of the file


    for (int i=0; i <= amount-1; i++) { // This loop generates a random number each time it runs. The random number is put in the output file


        int random_num = distribution(generator); // We generate a random number each time the loop runs

        myOutputFile <<  random_num << "\n"; // We fill the file with a random number

    } // End of for loop

    myOutputFile.close(); // We close the output file




}


void NumberFileGenerator::singleValue(std::string fileName, int amount, int value) {

    std::ofstream myOutputFile(fileName); // We create an outputFile


    myOutputFile << amount << "\n"; // We store the amount of numbers in the top of the file


    for (int i=0; i < amount; i++) { // This loop loops through all the indexes of our nums array



        myOutputFile <<  value << "\n"; // We fill the array with the value amount times

    } // End of for loop

    myOutputFile.close(); // We close the output file



}
