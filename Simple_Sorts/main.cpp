/**
*	@file : main.cpp
*	@author :  Alec Knutsen
*	@date : 2015.03.27
*	@brief: The main method creates an array of random integers of specified size by the user. It will sort the array based on a sorting algorithm chosen by the user.
*   @brief: We display the time of the sort, and the sorted array. The user is allowed to keep building and sorting as long as they desire.
*/

#include <iostream> // We include the iostream library to print data.
#include <iomanip> //  We include the iomanip library to format printed data.
#include <string> // We include the string library since string variables will be used.

#include "Sorts.h" // We include the Sorts.h file since we will use the sorting algorithms in this file.


#include <random> // We include the random library for our random generator
#include <ctime> // We include the ctime library so we can seed the generator
#include <chrono> // We include the chrono library so we can time the sorting algorithms


using namespace std;




/**
* @pre - We assume the parameters size, min, and max have been initialized to valid integers. We assume the random generator and distribution function properly.
* @post - This method populates an array of size with random of integers chosen from min. to max.
* @param - int size - Size of the array passed in, int min - Minimum value that a value can be in the array, int max - Maximum value that a value can be in the array
* @return - int* - Returns a pointer to an integer array populated with random values.
*/

int* createRandomIntArray(int size, int min, int max) {


    int* nums = new int[size]; // We declare an integer pointer that points to the first index of an integer array of size passed in as a parameter


    std::default_random_engine generator(time(nullptr)); // We declare a generator and seed the generator


    std::uniform_int_distribution<int> distribution(min,max); // We declare a distribution, and set the min and max of the distribution


    for (int i=0; i <= size-1; i++) { // This loop loops through all the indexes of our nums array


        int random_num = distribution(generator); // We generate a random number each time the loop runs

        nums[i] = random_num; // We fill the array with a random number

    } // End of for loop




    return(nums); // We return the pointer to the array of random integers.

}



/**
* @pre - None
* @post - This method prints a menu of sorting algorithms. It will be sed in the main method
* @param - None
* @return - None
*/
void printMenu() {

	std::cout 	<< "\n\nSelect a sort:\n"
			<< "1) Bubble Sort\n"
			<< "2) Insertion Sort\n"
			<< "3) Selection Sort\n"
			<< "4) Bogo Sort (use only with very small arrays!)\n"
			<< "Enter choice: ";
}



/**
* @pre - We assume all the methods of the Sorts class function properly. Also, we assume the the user enters valid inputs for array size, min value, and max value. Also, we assume the methods in the ctime library function properly.
* @post - The main method creates an array of random integers of specified size by the user. It will sort the array based on a sorting algorithm chosen by the user.
* @post - We display the time of the sort, and the sorted array. The user is allowed to keep building and sorting as long as they desire.
* @param - None
* @return - int - Returns 0
*/
int main() {

    Sorts<int> test; // We create a stack allocated object of the class Sorts, so we are not in charge of deleting this object

    std::string answer = "n"; // Answer will ask the user if they want to do the creating and sorting process all over again
    int choice; // Choice will hold the answer for what type of sort the user wants
    std::string choice2; // Choice2 will ask whether the user wants to print the unsorted array
    std::string choice3; // Choice3 will ask whether the user wants to print the sorted array




    int arr_size; // Holds the arr_size given by the user
    int min_Val; // Holds the min_Val given by the user
    int max_Val; // Holds the max_Val given by the user


    std::chrono::system_clock::time_point start; // Holds the start time before a sorting algorithm begins
    std::chrono::system_clock::time_point stop; // Holds the stop time after a sorting algorithm finishes
    std::chrono::duration<double> elapsed; // Holds the total time the sort took.

    while (answer!="y") { // If the user, wants to keep creating and sorting array this while loop runs



        printMenu(); // We use the printMenu method to get the users input for sorting method.
        std::cin >> choice; // We store the value in choice

        while (1>choice || 4 < choice) { // If the user did not make a valid choice, this while loop runs. It will continue to run until the user enters valid input.

            std::cout << "You did not enter a valid sort choice";
            printMenu();
            std::cin >> choice;

        }

        std::cout << "Input a size for the random array: "; // We get the user's input for arr_size and store it in arr_size
        std::cin >> arr_size;
        std::cout << ""<<std::endl;

         while (arr_size <= 0) { // If the user did not make a valid choice, this while loop runs. It will continue to run until the user enters valid input for arr_size

            std::cout << "You did not enter a valid array size"<<std::endl;
            std::cout << "Input a size for the random array: ";
            std::cin >> arr_size;
            std::cout << ""<<std::endl;

        }

        std::cout <<"Input a lower bound on the range of random numbers: "; // We get the user input for min value that can be stored in the array
        std::cin >> min_Val;
        std::cout << ""<<std::endl;

        std::cout <<"Input an upper bound on the range of random numbers: "; // We get the user input for max value that can be stored in the array
        std::cin >> max_Val;
        std::cout << ""<<std::endl;

        int* arr = createRandomIntArray(arr_size, min_Val, max_Val); // We create a heap allocated array of random integer values of size inputted by the user using the createRandomIntArray method

        std:: cout << "Do you want to print the unsorted array? (y/n): "; // We ask the user if they want to print the unsorted array, and store the answer in choice2
        std::cin >> choice2;

        if (choice2 == "y") { // If they do want to print the unsorted array, this if statement runs

            std::cout << "Here is the unsorted array: " <<std::endl;
            std:: cout << "[";


            for (int i=0; i <= arr_size - 1; i++) { // We loop through all the values in the array




                if (i <arr_size-1) { // If the array index is not the last index, we print the array value and a comma

                     std::cout << arr[i] << ",";

                }

                else if (i==arr_size-1) { // If the array index is the last index, we print the array value and a bracket

                    std::cout << arr[i] << "]"<<std::endl;

                }


            } // End of for loop

        } // End of if block

        std::cout<<""<<std::endl;


        if (choice == 1) { // If the user enters 1 for bubble sort, we sort the array using bubble sort and store the start, stop, and elapsed time that the method took.


            std::cout << "Sorting with bubble sort..."<<std::endl;


            start = std::chrono::system_clock::now();

            test.bubblesort(arr, arr_size);

            stop = std::chrono::system_clock::now();

            elapsed = (stop-start);


        } // End of if block

        else if (choice ==2) { // If the user enters 2 for insertion sort, we sort the array using insertion sort and store the start, stop, and elapsed time that the method took.

            std::cout << "Sorting with insertion sort..."<<std::endl;

            start = std::chrono::system_clock::now();

            test.insertionSort(arr, arr_size);

            stop = std::chrono::system_clock::now();

            elapsed = (stop-start);


        } // End of else if block

        else if (choice == 3) { // If the user enters 3 for selection sort, we sort the array using selection sort and store the start, stop, and elapsed time that the method took.

            std::cout << "Sorting with selection sort..."<<std::endl;

            start = std::chrono::system_clock::now();

            test.selectionSort(arr, arr_size);

            stop = std::chrono::system_clock::now();

            elapsed = (stop-start);



        } // End of else if block

        else if (choice == 4) { // If the user enters 4 for bogo sort, we sort the array using bogo sort and store the start, stop, and elapsed time that the method took.


            std::cout << "Sorting with bogo sort..."<<std::endl;


            start = std::chrono::system_clock::now();

            test.bogosort(arr, arr_size);

            stop = std::chrono::system_clock::now();

            elapsed = (stop-start);




        } // End of else if block

        std::cout <<"Do you want to print the sorted array? (y/n): "; // We ask the user if they want to print the sorted array. We store the input in choice3
        std::cin >> choice3;


        if (choice3 == "y") { // If the user does want to print the sorted array, this if statement runs


            std::cout << "Here is the sorted array: " <<std::endl;
            std:: cout << "[";


            for (int i=0; i <= arr_size - 1; i++) { // We loop through all the values in the sorted array




                if (i <arr_size-1) { // If the array index is not the last index, we print the array value and a comma

                     std::cout << arr[i] << ",";

                }

                else if (i==arr_size-1) { // If the array index is the last index, we print the array value and a bracket

                    std::cout << arr[i] << "]"<<std::endl;

                }


            } // End of for loop

        } // End of if block

        std::cout << ""<<std::endl;


        /**
         * We print the sorting time information
        */
        std::cout << arr_size << " numbers were sorted in ";
        std::cout << fixed << showpoint;
        std::cout << std::setprecision(8) << elapsed.count();
        std::cout << " seconds."<<std::endl;


        delete [] arr; // We delete the sorted array

        std::cout<<""<<std::endl;

        std::cout << "Do you want to quit? (y/n): "; // We ask if the user wants to go again, storing the input in answer.
        std::cin >> answer;


    } // End of outer while loop


    return 0;

}
