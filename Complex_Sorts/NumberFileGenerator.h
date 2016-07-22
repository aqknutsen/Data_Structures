/**
*	@file : NumberFileGenerator.h
*	@author : Alec Knutsen
*	@date : 2015.04.05
*	@brief: This class contains methods that will store numbers in a file: either random numbers, numbers from 0 to some amount in ascending or descending orders, or a single value a certain amount of times.
*/

#ifndef NUMBERFILEGENERATOR_H
#define NUMBERFILEGENERATOR_H


#include <fstream> // We include <fstream> library to manipulate files

#include <random> // We import random to generate random numbers
#include <ctime> // We import ctime to seed the random number generator


class NumberFileGenerator {

public:


    /**
    * @pre - We assume fileName is a valid string and a valid filename. We assume amount is greater than zero. We assume the <fstream> library works properly.
    * @post - A file is  created containing amount of numbers. The numbers in the file are created from 0 to amount-1 in order.
    * @param - std::string fileName - fileName where the numbers will be stored, amount - amount of numbers to be stored
    * @return - None
    */
    static void ascending(std::string fileName, int amount);


    /**
    * @pre - We assume fileName is a valid string and a valid filename. We assume amount is greater than zero. We assume the <fstream> library works properly.
    * @post - A file is  created containing amount of numbers. The numbers in the file are created from amount-1 to 0 in order.
    * @param - std::string fileName - fileName where the numbers will be stored, amount - amount of numbers to be stored
    * @return - None
    */
    static void descending(std::string fileName, int amount);


    /**
    * @pre - We assume fileName is a valid string and a valid filename. We assume amount is greater than zero, and that min is less than max. We assume the <fstream>, <random>, and <ctime> libraries work properly
    * @post - A file is  created containing amount of numbers. The numbers in the file are random from min to max inclusive
    * @param - std::string fileName - fileName where the numbers will be stored, amount - amount of numbers to be stored, min - Minimum value that a number can, max- Maximum number that a value can be
    * @return - None
    */
    static void random(std::string fileName, int amount, int min, int max);



    /**
    * @pre - We assume fileName is a valid string and a valid filename. We assume amount is greater than zero. We assume that value is a valid integer. We assume the <fstream> library works properly.
    * @post - A file is  created containing amount of value.
    * @param - std::string fileName - fileName where the numbers will be stored, amount - amount of numbers to be stored, value - Only value to be put in the file
    * @return - None
    */
    static void singleValue(std::string fileName, int amount, int value);







};

#endif // NUMBERFILEGENERATOR_H
