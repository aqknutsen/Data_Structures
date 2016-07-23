/**
*	@file : Sorts.hpp
*	@author :  Alec Knutsen
*	@date : 2015.04.05
*	@brief: Implementation of the Sorts.h file (see header file for method descriptions).
*/





template <typename T> // We template the method
void Sorts<T>::bubblesort(T arr[], int size) {

    bool sorted = false;


    while (! sorted) { // While the array passed in is not sorted, this loop runs


        sorted = true; // We first assume the array is sorted


        for (int i =0; i < size-1; i++) { // This loop runs through all the indices of the array except the last element


            if (arr[i] > arr[i+1]) { // If the previous array value is greater than the next array value, this if statement runs


                sorted = false; // This will make the while loop run again

                int hold = arr[i]; // This temporarily holds the previous array value

                arr[i] = arr[i+1]; // The previous array value gets swapped with the next array value

                arr[i+1] = hold; // The next array value becomes the previous array value


            } // End of if block


        } // End of for loop


    } // End of while loop


    assert(Sorts<T>::isSorted(arr, size)); // If the array is not sorted after the algorithm is run through, the program is killed using this assert statement

}





template <typename T> // We template the method
void Sorts<T>::insertionSort(T arr[], int size) {


    for(int i = 1; i < size; i++) { // We loop through all the values in the array passed in except the first value.




        for (int j=i; j > 0; j--) { // We partition the array into sorted and unsorted sides. The indices left of j represents a sorted array. Everything to the right of j is not sorted.This for loop moves the smallest value to the front of the left sorted side.


              if (arr[j] < arr[j-1]) { // If we find a smaller value in the sorted side, we swap values

                 T temp = arr[j]; // We store the array value at index value temporarily

                 arr[j] = arr[j-1]; // We swap values


                 arr[j-1] = temp; // We swap values


              } // End of if statement


          } // End of inner for loop


     } // End of outer for loop

    assert(Sorts<T>::isSorted(arr, size)); // If the array is not sorted after the algorithm is run through, the program is killed using this assert statement



}




template <typename T>
void Sorts<T>::mergeSort(T arr[], int size) {

    if (size <= 1) { // By calling the method recursively, we break the array into pieces until we reach an array of size 1. Then, we return

            return;

     }



    else {

        int mid = size/2; // Each time the method is called the array is divided into smaller pieces


        mergeSort(arr, mid); // Mergesort is called recursively on the left side

        mergeSort(arr+mid, size-mid); // Mergesort is called recursively on the right side

        merge(arr, arr+mid,mid,size-mid); // Merge merges the arrays divided in two


    }

    assert(Sorts<T>::isSorted(arr, size)); // If the array is not sorted after the algorithm is run through, the program is killed using this assert statement


}


template <typename T> // We template the method
void Sorts<T>::quickSort(T arr[], int size) {


    quickSortRec(arr, 0, size-1,false); // We call quickSortRec to preform the quicksort algorithm by choosing the pivot as the last value in each partition



    assert(Sorts<T>::isSorted(arr, size)); // If the array is not sorted after the algorithm is run through, the program is killed using this assert statement


}


template <typename T> // We template the method
void Sorts<T>::quickSortMedian(T arr[], int size) {


    quickSortRec(arr, 0, size-1, true); // We call quickSortRec to preform the quicksort algorithm by choosing the pivot as the median of three values


    assert(Sorts<T>::isSorted(arr, size));  // If the array is not sorted after the algorithm is run through, the program is killed using this assert statement


}



template <typename T> // We template the method
void Sorts<T>::selectionSort(T arr[], int size) {

    int minIndex;

    for (int i=0; i < size-1; i++) { // This loop loops through all the indexes in the array


        minIndex = i; // We assume the min value is at index i



        for (int j = i + 1; j < size; j++) { // This loop also loops through all the indexes in the array starting from the i + 1 index. It compares all values to the min value at index i. If we find a smaller value, it will change the min index.
                                            // At the end of the loop, the smallest value is found in the subarray from index i +1 to the last index.


            if (arr[j] < arr[minIndex]) { // If a smaller value is found in an index higher than i, we change the minIndex


                minIndex = j;


            } // End of if block


        } // End of inner for loop


        if (minIndex!= i) { // If the minimum value is found other than the assumed i index value, we swap


            int temp = arr[i]; // We store the temporary previous min value in temp


            arr[i] = arr[minIndex]; // We set arr[i] to the minimum value


            arr[minIndex] = temp; // We set the old minimum value index to temp


        } // End of if block


    } // End of outer for loop


assert(Sorts<T>::isSorted(arr, size)); // If the array is not sorted after the algorithm is run through, the program is killed using this assert statement


}


template <typename T> // We template the method
bool Sorts<T>::isSorted(T arr[], int size) {


    for (int i=0; i < size-1; i++) { // This loop loops through all the values in the array passed in as a parameter


        if (arr[i] > arr[i+1]) { // If two index values by each other are not sorted in ascending order, we return false because the array is not sorted


            return (false);


        } // End of if block


    } // End of for loop


    return(true); // If the whole loop is run through, and no two indexes are out of order, we return true



}


template <typename T> // We template the method
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size) {



    std::chrono::system_clock::time_point start; // Holds the start time before a sorting algorithm begins
    std::chrono::system_clock::time_point stop; // Holds the stop time after a sorting algorithm finishes
    std::chrono::duration<double> elapsed; // Holds the total time the sort took.


    start = std::chrono::system_clock::now(); // We get the start time


    sort(arr, size); // We preform the sort



    stop = std::chrono::system_clock::now(); // We get the stop time

    assert(Sorts<T>::isSorted(arr, size)); // If the array is not sorted after the algorithm is run through, the program is killed using this assert statement

    elapsed = (stop-start); // We get the total time the sort took




    return(elapsed.count()); // We return the time the sort took

}






template <typename T> // We template the method
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2) {



    int size = size1+size2; // We combine the sizes of the two arrays passed in as parameters

    T tempArray[size]; // We create a temporary array to store values when we combine the two arrays

    int index =0;  // This will hold the index of our temporary array

    int first1 = 0; // This will hold the index of the array pointed at by a1

    int first2 = 0;  // This will hold the index of the array pointed at by a2


    while ((first1 < size1) && (first2 < size2)) { // This while loop runs until one of the arrays either a1 or a2 is looped through

        /**
        * We compare each corresponding value of a1 and a2. The smaller values goes in our temp array.
        */

        if (a1[first1] < a2[first2]) { // If the smaller value comes from a1, we put the value in temp array. We go to the next index in a1

            tempArray[index] = a1[first1];

            first1++;

        } // End of if block

        else { // Else the smaller value comes from a2, we put the value in temp array. We go to the next index in a2


            tempArray[index] = a2[first2];

            first2 ++;

        } // End of else block

        index ++; // Once we have a value in our temp array, we iterate to the next index

    } // End of while loop


    while (first1 < size1) { // If our first while loop, looped through all the values in a2, but not a1, we store the rest of the values from the a1 array in the temp array

        tempArray[index] = a1[first1];

        first1++;

        index++;
    }

    while (first2 < size2) { // If our first while loop, looped through all the values in a1, but not a2, we store the rest of the values from the a2 array in the temp array

        tempArray[index] = a2[first2];

        first2++;

        index++;
    }

    for (int i =0; i < size; i++) { // This for loop copies all values from our temparray into the array pointed at by a1

        a1[i] = tempArray[i];

    } // End of for loop


}

template <typename T> // We template the method
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median) {


    if (first - last + 1 < 3) { // If the size of the partition of the array passed in is less than three, we use insertionSort to sort the size less than 3 partition

            insertionSort(arr,last-first+1);

    }

    else { // If the size of the partition is not less than three, we continue to partition the array and call quickSort recursively

        int pivotIndex = partition(arr, first, last, median); // We call the partition method to partition our array


        quickSortRec(arr,first, pivotIndex-1, median); // We call the method recursively on the left side of the partition



        quickSortRec(arr,pivotIndex+1, last, median); // We call the method recursively on the right side of the partition


    }




}


template <typename T> // We template the method
void Sorts<T>::setMedianPivot(T arr[], int first, int last) {

    int pivot; // This int will hold our pivot value

    int temp; // This int will temporarily hold array values

    int mid = (last-first+1)/2; // We get the middle value of the array passed in

    if (arr[first] > arr[mid]) { // If the first value is greater than the middle value, we swap the array values

        arr[first] = temp;

        arr[first] = arr[mid];

        arr[mid] = temp;

    }

    if (arr[mid] > arr[last]) { // If the middle of the array is less than the last value, we swap the array values

        arr[mid] = temp;

        arr[mid] = arr[last];

        arr[last] = temp;

    }

    if (arr[first] > arr[mid]) { // One more time, if the first value is greater than the middle value, we swap the array values

        arr[first] = temp;

        arr[first] = arr[mid];

        arr[mid] = temp;

    }

    pivot = arr[mid]; // We get the pivot as the median of three values

    arr[last] = temp;

    arr[last] = pivot; // We move the pivot value to the last value in the array

    arr[mid] = temp; // We move the last value to the middle in the array

}

template <typename T> // We template the method
int Sorts<T>::partition(T arr[], int first, int last, bool median) {

    if (median) { // If median is true, we use the setMedianPivot to choose the pivot

        setMedianPivot(arr, first, last); // We get the pivot as the median of the first middle and last values, and this method puts the array in the last index

        int indexFromLeft = first + 1; // Because we used setMedianPivot we know the first value in the array will be in the right place. Thus, we will start the partition from the second value

        int indexFromRight = last-1; // Because we used setMedianPivot we know the last value in the array will be the pivot. Thus, we will start the partition from the second to last value


        int pivot = arr[last]; // We know the pivot will be in the last value

        bool stop = false;

        while (!stop) { // This loop will run until the indices corresponding to each partition have crossed into the other


            while(arr[indexFromLeft] < pivot) { // This loop will run until a value in the left partition is greater than the pivot

                indexFromLeft++;

            } // End of inner while loop

            while(arr[indexFromRight] > pivot) { // This loop will run until a value in the right partition is less than the pivot

                indexFromRight--;

            } // End of inner while loop

            if (indexFromLeft < indexFromRight) { // We know that we have found two values that we need to be swapped. We make sure the the left index has not crossed into the right partition and vice versa. If not, we swap

                int temp = arr[indexFromLeft];

                arr[indexFromLeft] = arr[indexFromRight]; // Swap values

                arr[indexFromRight] = temp; // Swap values

                indexFromLeft++; // Proceed to the next index

                indexFromRight--; // Proceed to the next index


            } // End of if statement

            else { // Once we have run through each partition, this else statement will cause the outer while loop to finish. THe left partition contains all values left than the pivot and the right partition contains all values greater than the pivot

                stop = true;

            }

        } // End of outer while loop

        /**
        * We swap the pivot with the value at indexFromLeft.
        * We know the pivot is in the right place
        */

        arr[last] = arr[indexFromLeft];

        arr[indexFromLeft] = pivot;



        return(indexFromLeft); // We return the pivot index


    } // End of outer if block

    else { // If median is false, we make the pivot value the last value in the array


        int indexFromLeft = 0; // We start the partition from the first value

        int indexFromRight = last-1; // We end the partition at the second to last value since the last value is the pivot


        int pivot = arr[last]; // We make the pivot the last value

        bool stop = false;

        while (!stop) { // This loop will run until the indices corresponding to each partition have crossed into the other


            while(arr[indexFromLeft] < pivot) { // This loop will run until a value in the left partition is greater than the pivot

                indexFromLeft++;

            } // End of inner while loop

            while(arr[indexFromRight] > pivot) { // This loop will run until a value in the right partition is less than the pivot

                indexFromRight--;

            } // End of inner while loop

            if (indexFromLeft < indexFromRight) { // We know that we have found two values that we need to be swapped. We make sure the the left index has not crossed into the right partition and vice versa. If not, we swap

                int temp = arr[indexFromLeft];

                arr[indexFromLeft] = arr[indexFromRight]; // swap

                arr[indexFromRight] = temp; // swap

                indexFromLeft++; // Proceed to the next index.

                indexFromRight--; // Proceed to the next index


            } // End of if block

            else { // Once we have run through each partition, this else statement will cause the outer while loop to finish. THe left partition contains all values left than the pivot and the right partition contains all values greater than the pivot

                stop = true;

            }

        } // End of outer while loop


         /**
        * We swap the pivot with the value at indexFromLeft.
        * We know the pivot is in the right place
        */

        arr[last] = arr[indexFromLeft];
        arr[indexFromLeft] = pivot;


        return(indexFromLeft); // We return the index of the pivot


    } // End of outer else blockS



}



template <typename T> // We template the method
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator) {


    std::uniform_int_distribution<int> distribution(0,size-1); // This distribution will be used with the generator passed in as a parameter to get a random index of an array

    for (int i =0; i <= size-1; i++) { // We loop through all the values in the array passed in


        int random_index = distribution(generator); // We generate a random number using the generator and random distribution each time the loop is run

        T temp = arr[i]; // We store our arr[i] value in temp

        arr[i] = arr[random_index]; // We swap the arr[i] with an array value at a random index

        arr[random_index] = temp; // We swap the array value at the random index with the array value at index i


    } // End of for loop


}
