/**
*	@file : SortDriver.cpp
*	@author : Alec Knutsen
*	@date : 2015.04.05
*	@brief: Implementation of SortDriver.h (look at header file for method descriptions)
*/


#include "SortDriver.h" // We include the corresponding SortDriver.h file




void SortDriver::run(int argc, char** argv) {


    Sorts<int> test; // We create an instance of the Sorts class with a template type of int

    if(areParametersValid(argv[2], argv[3]) && isSortedValid(argv[1]) ) { // If the command is -sort. we have a valid sort mode, and we have a valid input file, this if statement runs


        std::string mode = argv[2]; // We store the sort mode either (-bubble, -selection, -insertion, -merge, -quick, -quick3, or -all)

        std::ifstream file(argv[3]); // We get the input file

        std::ofstream myOutputFile(argv[4]); // We create an output file

        int size = getFileCount(file); // We get the number of integers in the file



        int* nums = createArray(file, size); // We create an array with the same size as the number of values in the file


        file.close(); // We close the input file




        /**
        * These integers are used to store the time of the sorts
        */

        double time1;
        double time2;
        double time3;
        double time4;
        double time5;
        double time6;

        if (mode == "-bubble") { // If the command is -bubble, we do bubblesort on the array from the inputfile using sortTimer. We format the timing information and put it in the outputfile.



            time1 = test.sortTimer(test.bubblesort, nums, size);

            myOutputFile << "Bubble sort sorted " << size << " numbers in "
            << std::fixed << std::showpoint
            << std::setprecision(8) << time1
            << " seconds."<<std::endl;


        }

        else if (mode== "-selection") { // If the command is -selection, we do selectionsort on the array from the inputfile using sortTimer. We format the timing information and put it in the outputfile.

             time1 = test.sortTimer(test.selectionSort, nums, size);

             myOutputFile << "Selection sort sorted " << size << " numbers in "
             << std::fixed << std::showpoint
             << std::setprecision(8) << time1
             << " seconds."<<std::endl;



        }

        else if (mode== "-insertion") { // If the command is -insertion, we do insertionsort on the array from the inputfile using sortTimer. We format the timing information and put it in the outputfile.

            time1 = test.sortTimer(test.insertionSort, nums, size);

            myOutputFile << "Insertion sort sorted " << size << " numbers in "
            << std::fixed << std::showpoint
            << std::setprecision(8) << time1
            << " seconds."<<std::endl;

        }

        else if (mode== "-quick") { // If the command is -quick, we do quicksort on the array from the inputfile using sortTimer. We format the timing information and put it in the outputfile.


            time1 = test.sortTimer(test.quickSort, nums, size);

            myOutputFile << "Quick sort sorted " << size << " numbers in "
            << std::fixed << std::showpoint
            << std::setprecision(8) << time1
            << " seconds."<<std::endl;





        }


        else if (mode== "-quick3") { // If the command is -quick3, we do quicksort (with median pivot) on the array from the inputfile using sortTimer. We format the timing information and put it in the outputfile.


            time1 = test.sortTimer(test.quickSortMedian, nums, size);

            myOutputFile << "Quick sort (with median) sorted " << size << " numbers in "
            << std::fixed << std::showpoint
            << std::setprecision(8) << time1
            << " seconds."<<std::endl;



        }


        else if (mode== "-merge") { // If the command is -merge, we do mergesort on the array from the inputfile using sortTimer. We format the timing information and put it in the outputfile.

            time1 = test.sortTimer(test.mergeSort, nums, size);



            myOutputFile << "Merge sort sorted " << size << " numbers in "
            << std::fixed << std::showpoint
            << std::setprecision(8) << time1
            << " seconds."<<std::endl;


        }


        else if (mode== "-all") { // If the command is -bubble, we do all sorts on the array from the inputfile using sortTimer. We format the timing information and put it in the outputfile.

            int* copy1 = new int[size]; // We create a copy of the original array

            copyArray(nums,copy1,size);

            time1 = test.sortTimer(test.bubblesort, nums, size); // We first time bubble sort using the orignal array.

            int* copy2 = new int[size]; // We create a copy of copy1 before we modify it

            copyArray(copy1,copy2,size);


            time2 = test.sortTimer(test.selectionSort, copy1, size); // We time selection sort using the copy1 array.

            int* copy3 = new int[size]; // We create a copy of copy2 before we modify it

            copyArray(copy2,copy3,size);

            time3 = test.sortTimer(test.insertionSort, copy2, size); // We time insertion sort using the copy2 array.


            int* copy4 = new int[size]; // We create a copy of copy3 before we modify it

            copyArray(copy3,copy4,size);

            time4 = test.sortTimer(test.quickSort, copy3, size); // We time quickSort sort using the copy3 array.


            int* copy5 = new int[size]; // We create a copy of copy4 before we modify it
            copyArray(copy4,copy5,size);


            time5 = test.sortTimer(test.quickSortMedian, copy4, size); // We time quick sort (with median) using the copy4 array.


            time6 = test.sortTimer(test.mergeSort, copy5, size); // We time merge sort using the copy5 array.


            /**
            * We put all the timing information in the output file
            */



            myOutputFile << "Bubble sort sorted " << size << " numbers in "
            << std::fixed << std::showpoint
            << std::setprecision(8) << time1
            << " seconds."<<std::endl;


            myOutputFile << "Selection sort sorted " << size << " numbers in "
            << std::fixed << std::showpoint
            << std::setprecision(8) << time2
            << " seconds."<<std::endl;

            myOutputFile << "Insertion sort sorted " << size << " numbers in "
            << std::fixed << std::showpoint
            << std::setprecision(8) << time3
            << " seconds."<<std::endl;


            myOutputFile << "Quick sort sorted " << size << " numbers in "
            << std::fixed << std::showpoint
            << std::setprecision(8) << time4
            << " seconds."<<std::endl;

            myOutputFile << "Quick sort (with median) sorted " << size << " numbers in "
            << std::fixed << std::showpoint
            << std::setprecision(8) << time5
            << " seconds."<<std::endl;


            myOutputFile << "Merge sort sorted " << size << " numbers in "
            << std::fixed << std::showpoint
            << std::setprecision(8) << time6
            << " seconds."<<std::endl;


            /**
            * We deleted all the copied arrays
            */

            delete[] copy1;
            delete[] copy2;
            delete[] copy3;
            delete[] copy4;
            delete[] copy5;

        } // End of else if block

        delete[] nums; // We delete the original nums array


        myOutputFile.close(); // We close the output file



     } // End of outer if block


     else { // If one of the commands is not valid, we print the sort help menu

        printHelpMenu();

     }



}

void SortDriver::printHelpMenu(){

    /**
    * Help menu for sorting commands
    */

	std::cout << "\nSorting is done one of the following ways:\n\n"
			<< "./prog -sort -bubble inputFile outputFile\n"
			<< "./prog -sort -selection inputFile outputFile\n"
			<< "./prog -sort -insertion inputFile outputFile\n"
			<< "./prog -sort -quick inputFile outputFile\n"
			<< "./prog -sort -quick3 inputFile outputFile\n"
			<< "./prog -sort -merge inputFile outputFile\n"
			<< "./prog -sort -all inputFile outputFile\n"
			<< "Option explainations:\n"
			<< "\t-bubble to time bubble sort and store all timing results in outputFile\n"
			<< "\t-selection to time selection sort and store all timing results in outputFile\n"
			<< "\t-insertion to time insertion sort and store all timing results in outputFile\n"
			<< "\t-quick to time quick sort and store all timing results in outputFile\n"
			<< "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
			<< "\t-merge to time merge sort  and store all timing results in outputFile\n"
			<< "\t-all to time all of the sorts and store all timing results in outputFile\n"
			<< "\tinputFile must be file created by a NumberFileGenerator\n"
			<< "\toutputFile must be to a valid path. It will hold the timing results\n";

}



bool SortDriver::isFileAcessible(std::string fileName) {

    std::ifstream file(fileName); // We create an input stream to the file

    if(file.good()) { // If the file is a valid file, we return false

        return(true);

    }

    else { // If the file is not valid, we return false

        return(false);

    }

    file.close(); // We close the file

}


bool SortDriver::isSortedValid(std::string sortParameter) {

    if (sortParameter=="-sort") { // If the sort parameter is -sort (valid), we return true

        return(true);

    }

    else { // If the sort parameter is not valid, we return false

        return(false);
    }


}







bool SortDriver::areParametersValid(std::string sortName, std::string inputFileName) {

    if (sortName=="-bubble" || sortName=="-selection" || sortName=="-insertion" || sortName=="-quick" || sortName=="-quick3" || sortName=="-merge" || sortName=="-all") { // If one of the sorting types is valid, this if statement runs


        if(isFileAcessible(inputFileName)) { // If the file is valid, we return true

            return(true);

        }

        else { // If the file is invalid, we return false

            return(false);

        }

    } // End of outer if block

    else { // If the type of sort is invalid we return false

        return(false);
    }


}



int SortDriver::getFileCount(std::ifstream& inputFile) {


    int amount;

    inputFile >> amount; // This will get the number stored in the top of inputFile and store it in amount

    return(amount); // We return amount representing the number of integers in inputFile


}

int* SortDriver::createArray(std::ifstream& inputFile, int size) {




    int* nums = new int[size]; // We create an array



    for (int i = 0; i < size; i++) { // This for loop takes each value from inputFile and puts them into the nums array

        inputFile >> nums[i];

    }

    return(nums); // We return a pointer to the nums array

}


void SortDriver::copyArray(int original[], int copy[], int size) {

    for (int i =0; i < size; i ++) { // This for loop copies each value from original into copy

        copy[i]=original[i];

    }



}
