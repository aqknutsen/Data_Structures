/**
*	@file : Sorts.h
*	@author :  Alec Knutsen
*	@date : 2015.03.27
*	@brief: This class contains methods that sort an array through the sorting methods bubblesort, bogosort,insertionSort, and selectionSort. Finally, we have a method to check if an array is sorted, and a method to shuffle an array.
*/



#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED

#include <cassert> // We import the cassert library, so we can kill any methods called if an array is not sorted after one of the sorting methods run
#include <random> // We import random to generate random numbers
#include <ctime> // We import ctime to seed the random number generator



template <typename T> // We template the class
class Sorts {


public:



     /**
    * @pre - We assume the array passed in at a parameter contains valid T values at each index. Furthermore, we assume the array has a valid size. Finally, we assume assert works correctly.
    * @post - This method sorts the array passed in as a parameter using the bubble method. If the array is not sorted after the method is called, the program will stop executing.
    * @param - T arr[] - The array that will be sorted, int size - The size of the array that will be sorted.
    * @return - None
    */
    static void bubblesort(T arr[], int size);




    /**
    * @pre - We assume the array passed in at a parameter contains valid T values at each index. We assume the random number generator works correctly. We assume the isSorted and shuffle method work properly. Finally, we assume assert works correctly.
    * @pre - This sorting method is not efficient for sizes greater than ten.
    * @post - This method sorts the array passed in as a parameter using the bogosort method. If the array is not sorted after the method is called, the program will stop executing.
    * @param - T arr[] - The array that will be sorted, int size - The size of the array that will be sorted.
    * @return - None
    */
    static void bogosort(T arr[], int size);


    /**
    * @pre - We assume the array passed in at a parameter contains valid T values at each index. Finally, we assume assert works correctly.
    * @post - This method sorts the array passed in as a parameter using the insertionsort method. If the array is not sorted after the method is called, the program will stop executing.
    * @param - T arr[] - The array that will be sorted, int size - The size of the array that will be sorted.
    * @return - None
    */
    static void insertionSort(T arr[], int size);



    /**
    * @pre - We assume the array passed in at a parameter contains valid T values at each index. Finally, we assume assert works correctly.
    * @post - This method sorts the array passed in as a parameter using the selectionsort method. If the array is not sorted after the method is called, the program will stop executing.
    * @param - T arr[] - The array that will be sorted, int size - The size of the array that will be sorted.
    * @return - None
    */
    static void selectionSort(T arr[], int size);


    /**
    * @pre - We assume the array passed in at a parameter contains valid T values at each index and a valid size.
    * @post - This method checks if the array passed in as a parameter is sorted in ascending order. If the array is sorted, it returns true. Otherwise, it returns false.
    * @param - T arr[] - The array that will be checked, int size - The size of the array that will be checked
    * @return - bool - Returns true if the array is sorted. Returns false otherwise.
    */
    static bool isSorted(T arr[], int size);


private:

    /**
    * @pre - We assume the array passed in at a parameter contains valid index values and a valid size. We assume a valid generator is passed in.
    * @post - This method uses a random number generator to swap each index of an array with another random index. It will be implemented in the bogosort method.
    * @param - T arr[] - The array that will be shuffled, int size - The size of the array that will be shuffled, std::default_random_engine& generator - Generator of random numbers;
    * @return - None
    */
    static void shuffle(T arr[], int size, std::default_random_engine& generator);


};


#include "Sorts.hpp" // We include the corresponding "Sorts.hpp" file



#endif
