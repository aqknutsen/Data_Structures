/**
*	@file : Sorts.hpp
*	@author :  Alec Knutsen
*	@date : 2015.03.27
*	@brief: This class contains methods that sort an array through the sorting methods bubblesort, bogosort,insertionSort, and selectionSort. Finally, we have a method to check if an array is sorted, and a method to shuffle an array
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
void Sorts<T>::bogosort(T arr[], int size) {

    std::default_random_engine generator1(time(nullptr)); // We create a random number generator called generator1 and we seed the generator

    while (!(isSorted(arr, size))) { // While isSorted returns false, the array is not sorted, so this while loop runs


           shuffle(arr, size, generator1); // We use the shuffle method to shuffle the array until it is sorted.

    }



assert(Sorts<T>::isSorted(arr, size)); // If the array is not sorted after the algorithm is run through, the program is killed using this assert statement

}


template <typename T> // We template the method
void Sorts<T>::insertionSort(T arr[], int size) {


    for(int i = 1; i < size; i++) { // We loop through all the values in the array passed in except the first value.




        for (int j=i; j > 0; j--) { // We partition the array into sorted and unsorted sides. The indices left than j represents a sorted array. Everything to the right of j is not sorted.This for loop moves the smallest value to the front of the left sorted side.


              if (arr[j] < arr[j-1]) { // If we find a smaller value in the sorted side, we swap values

                 T temp = arr[j]; // We store the array value at index value temporarily

                 arr[j] = arr[j-1]; // We swap values


                 arr[j-1] = temp; // We swap values


              } // End of if statement


          } // End of inner for loop


     } // End of outer for loop

    assert(Sorts<T>::isSorted(arr, size)); // If the array is not sorted after the algorithm is run through, the program is killed using this assert statement



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
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator) {


    std::uniform_int_distribution<int> distribution(0,size-1); // This distribution will be used with the generator passed in as a parameter to get a random index of an array

    for (int i =0; i <= size-1; i++) { // We loop through all the values in the array passed in


        int random_index = distribution(generator); // We generate a random number using the generator and random distribution each time the loop is run

        T temp = arr[i]; // We store our arr[i] value in temp

        arr[i] = arr[random_index]; // We swap the arr[i] with an array value at a random index

        arr[random_index] = temp; // We swap the array value at the random index with the array value at index i


    } // End of for loop


}
