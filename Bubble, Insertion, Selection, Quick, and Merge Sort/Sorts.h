/**
*	@file : Sorts.h
*	@author :  Alec Knutsen
*	@date : 2015.04.05
*	@brief: This class contains methods that sort an array through the sorting methods bubbleSort,insertionSort,mergeSort,quickSort, and selectionSort.
    @brief: Also, we have methods to check if an array is sorted, to time a sort, and to shuffle an array.
*/

#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED

#include <functional> // We include the functional library so we can use a method as as a parameter in another method

#include <cassert> // We import the cassert library, so we can kill any methods called if an array is not sorted after one of the sorting methods run

#include <random> // We import random to generate random numbers
#include <ctime> // We import ctime to seed the random number generator

#include <chrono> // We import the chrono library to time sorts


template <typename T> // We template the class
class Sorts {


public:


    /**
    * @pre - We assume the array passed in as a parameter contains valid index values. Furthermore, we assume the array has a valid size. Finally, we assume assert works correctly.
    * @post - This method sorts the array passed in as a parameter using the bubble sort method. If the array is not sorted after the method is called, the program will stop executing.
    * @param - T arr[] - The array that will be sorted, int size - The size of the array that will be sorted.
    * @return - None
    */
    static void bubblesort(T arr[], int size);



    /**
    * @pre - We assume the array passed in as a parameter contains valid index values and a valid size. Finally, we assume assert works correctly.
    * @post - This method sorts the array passed in as a parameter using the insertion sort method. If the array is not sorted after the method is called, the program will stop executing.
    * @param - T arr[] - The array that will be sorted, int size - The size of the array that will be sorted.
    * @return - None
    */
    static void insertionSort(T arr[], int size);



    /**
    * @pre - We assume the array passed in as a parameter is a valid array, and we assume the array size is a valid size. We assume the merge method works correctly. Finally, we assume assert works correctly.
    * @post - This method sorts the array passed in as a parameter using the mergsort algorithm. The sorting algorithm calls this method recursively, and calls the merge method.
    * @post - If the method does not sort the array, the assert statement will stop the program
    * @param - T arr[] - The array that will be sorted, int size - The size of the array that will be sorted.
    * @return - None
    */
    static void mergeSort(T arr[], int size);



    /**
    * @pre - We assume the array passed in as a parameter is a valid array, and we assume the array size is a valid size. We assume the quickSortRec method works correctly. Finally, we assume assert works correctly.
    * @post - This method sorts the array passed in as a parameter using the quicksort algorithm. The sorting algorithm calls the quicksortRec method to do the quicksort algorithm.
    * @post - The pivot is chosen as the last element in the array.
    * @post - If the method does not sort the array, the assert statement will stop the program
    * @param - T arr[] - The array that will be sorted, int size - The size of the array that will be sorted.
    * @return - None
    */
    static void quickSort(T arr[], int size);


    /**
    * @pre - We assume the array passed in as a parameter is a valid array, and we assume the array size is a valid size. We assume the quickSortRec method works correctly. Finally, we assume assert works correctly.
    * @post - This method sorts the array passed in as a parameter using the quicksort algorithm. The sorting algorithm calls the quicksortRec method to do the quicksort algorithm.
    * @post - The pivot is chosen as the median of the first middle and last element of each partition
    * @post - If the method does not sort the array, the assert statement will stop the program
    * @param - T arr[] - The array that will be sorted, int size - The size of the array that will be sorted.
    * @return - None
    */
    static void quickSortMedian(T arr[], int size);



    /**
    * @pre - We assume the array passed in at a parameter contains valid index values and a valid size. Finally, we assume assert works correctly.
    * @post - This method sorts the array passed in as a parameter using the selectionsort method. If the array is not sorted after the method is called, the program will stop executing.
    * @param - T arr[] - The array that will be sorted, int size - The size of the array that will be sorted.
    * @return - None
    */
    static void selectionSort(T arr[], int size);


    /**
    * @pre - We assume the array passed in at a parameter contains valid index values and a valid size.
    * @post - This method checks if the array passed in as a parameter is sorted in ascending order. If it is it, returns true. Otherwise, it returns false.
    * @param - T arr[] - The array that will be sorted, int size - The size of the array that will be sorted.
    * @return - bool - Returns true if the array is sorted. Returns false otherwise.
    */
    static bool isSorted(T arr[], int size);




    /**
    * @pre - We assume the function passed in as a parameter is a valid method. We assume the array passed in as a parameter is a valid array with valid T values. Finally, we assume the array has a valid size.
    * @pre - We assume the <chrono> library works properly, and we assume the assert statement works correctly.
    * @post - This method uses the sorting method passed in as a parameter to sort the array passed in as a parameter. The time of the sort is stored and returned.
    * @param - std::function<void)>(T[], int) - The sorting function, T arr[] - Array that will be sorted, int size - Size of the array that will be osrted
    * @return - double - The time that the sort took will be returned
    */
    static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);




private:



    /**
    * @pre - We assume the T pointers passed in are valid pointers, and the the two sizes are valid ints.
    * @post - This method merges the two arrays passed in as two T pointers. The final sorted array has the a1 pointer point to its front value.
    * @param - T* a1 - Pointer that points to the first value in an array, T* a2 - Points to the first value in another array, int size1 - Size of array pointed at by a1, int size2 - Size of array pointed at by a2.
    * @return - None
    */
    static void merge(T* a1, T* a2, int size1, int size2);



    /**
    * @pre - We assume the arr passed in as a parameter is a valid array. We assume first and last are valid integers. Finally, we assume median is a valid boolean
    * @pre - We assume the insertSort and partition method works properly.
    * @post - This method uses the quicksort algorithm to sort the array passed in as a parameter. Once the array is partitioned into a size of less than 3, we use the quicksort method to sort the partition.
    * @param - T arr[] - Array that will be sorted, int first - First index in arr, int last - Last index in arr, median -  Boolean that will tell quicksort how to choose the pivot (either median of 3 or last value)
    * @return - None
    */
    static void quickSortRec(T arr[], int first, int last, bool median);



    /**
    * @pre - We assume the array passed in is a valid array. We assume first and last are valid integers, while median is a valid boolean.
    * @post - This method takes the first middle and last values of array and sorts them. Then, the pivot is chosen as the middle value. Finally, the pivot and last value are swapped.
    * @post - This method is used by the partition method.
    * @param - T arr[] - Array that will be sorted, int first - First index in arr, int last - Last index in arr
    * @return - None
    */
    static void setMedianPivot(T arr[], int first, int last);



    /**
    * @pre - We assume the array passed in is a valid array. We assume first and last are valid integers, while median is a valid boolean. We also assume setMedianPivot functions (places the median of three values in the last index)
    * @post - This method partitions arr into the left (contains everything smaller than the pivot), and the right (contains everything larger than the pivot).
    * @post - If bool median is true, we take the pivot as the median of three values. If it is false, the pivot is the last value in the array.
    * @post - This method will be called in quickSortRec
    * @param - T arr[] - Array that will be sorted, int first - First index in arr, int last - Last index in arr, median -  Boolean that will tell partition how to choose the pivot (either median of 3 or last value)
    * @return - None
    */
    static int partition(T arr[], int first, int last, bool median);



    /**
    * @pre - We assume the array passed in at a parameter contains valid index values and a valid size. We assume a valid generator is passed in.
    * @post - This method uses a random number generator to swap each index of an array with another random index. It will be implemented in the bogosort method.
    * @param - T arr[] - The array that will be sorted, int size - The size of the array that will be sorted, std::default_random_engine& generator - Generator of random numbers;
    * @return - None
    */
    static void shuffle(T arr[], int size, std::default_random_engine& generator);


};


#include "Sorts.hpp" // We include the corresponding "Sorts.hpp" file



#endif // SORTS_H_INCLUDED
