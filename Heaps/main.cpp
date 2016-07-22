

#include <iostream> // We import iostream so we can get input from the user

#include <random> // We import random to generate random numbers
#include <ctime> // We import ctime to seed the random number generator

#include <cstdlib> // We include cstdlib to import atoi so we can convert command line arguments to integers


#include "ArrayMinHeap.h"



void printMenu() {

    std::cout << "\n\nSelect from the following menu:\n"
            << "1)Get the Number of Nodes\n"
            << "2) Return the height of the heap\n"
            << "3) Peek at the top value in the heap\n"
            << "4) Add a value to the heap\n"
            << "5) Pop a value off of the heap\n"
            << "6) Delete the Heap\n"
            << "7) Print the heap in sorted order\n"
            << "8) Exit\n"
            << "Enter your choice: ";
}


int main(int argc, char** argv) {

    std::default_random_engine generator(time(nullptr)); // We create a new generator and seed it
    std::uniform_int_distribution<int> distribution(-30 ,30); // We create a distribution which can generate numbers from -32000 to 32000



    HeapInterface<int>* test = nullptr;


    if(argc ==2) {  // If the user passes in an extra command line argument, we fill the BST pointed at by test with the number of random values passed in by the user

        if(atoi(argv[1]) <= 0) { // If the user enters a negative number. We add no Nodes to the tree and print a message


            std::cout<<"We can not add a negative amount of numbers to the heap!"<<std::endl;

        }

        else { // If the user does enter a valid number of values, we proceed

            int* tempArray = new int[atoi(argv[1])];

            std::cout << "Filling original heap with " << atoi(argv[1]) << " values."<<std::endl;

            for (int i=0; i < std::atoi(argv[1]); i++) { // We use a for loop to populate the BSt

                int random_num = distribution(generator); // Get a random number

                std::cout<<"Adding " << random_num << " to the heap "<<std::endl;

                tempArray[i] = random_num;

            } // End of for loop

            test = new ArrayMinHeap<int>(tempArray,atoi(argv[1])); //We create a new instance of BSTI pointer called test that points to a BinarySearchTree
            delete[] tempArray;
        } // End of inner else block

    } // End of outer if block

    else {

        int size;
        int value;
        int* tempArray;

        std::cout<<"Enter a heap size: "<<std::endl;
        std::cin>>size;
        while(size<=0) {
            std::cout<<"Enter a heap size greater than 0!"<<std::endl;
            std::cin>>size;

        }

        tempArray = new int[size];

        for (int i=0; i < size; i++) {

            std::cout<<"Enter a value: "<<std::endl;
            std::cin>>value;
            tempArray[i] = value;
        }

        test = new ArrayMinHeap<int>(tempArray,size);
        delete[] tempArray;

    }


    int answer=0; // This variable will hold the input from the user for what option to select.


    while (answer!=8) { // This loop runs until the user answers 8 to exit

        printMenu(); // We print the menu each time the loop runs

        std::cin >> answer; // We store the users input in the variable answer


        if (answer ==1) { // If the answer is one (add), we get the user to input a value to add. Then, we add the answer to the BST pointed at by test.

            std::cout<<""<<std::endl;

            std::cout << "You chose 1"<<std::endl;


            std::cout<<"The Number of Nodes in the heap is " << test->getNumberofNodes()<<std::endl;


        }


        else if (answer ==2) { // If the answer is one (add), we get the user to input a value to add. Then, we add the answer to the BST pointed at by test.

            std::cout<<""<<std::endl;

            std::cout << "You chose 2"<<std::endl;


            std::cout<<"The height of the heap is " << test->getHeight()<<std::endl;


        }

        else if (answer ==3) { // If the answer is three (delete original), we attempt to remove the tree pointed at by Test

            std::cout<<""<<std::endl;

            std::cout << "You chose 3"<<std::endl;

            std::cout<< "Attempting Peek..."<<std::endl;

            try {

                std::cout<<test->peekTop() <<std::endl;
                std::cout<<"Peek successful"<<std::endl;
            }

            catch(std::runtime_error& e) {

                std::cout<<e.what()<<std::endl;
            }

        }

        else if (answer ==4) { // If the user enters four (print the original tree), we attempt to print the tree in the order specified by the user if the tree exists

            int value;

            std::cout<<""<<std::endl;

            std::cout << "You chose 4"<<std::endl;


            std::cout<<"Enter a value to add: "<<std::endl;
            std::cin>>value;

            std::cout<<"Adding value to the heap... "<<std::endl;



            if(test->add(value)) {

                std::cout<<"Value added to heap!"<<std::endl;
            }
            else {


                std::cout<<"Value exists in heap already!"<<std::endl;
            }

        } // End of outer else if block

         else if (answer ==5) { // If the user enters four (print the original tree), we attempt to print the tree in the order specified by the user if the tree exists


            std::cout<<""<<std::endl;

            std::cout << "You chose 5"<<std::endl;


            std::cout<<"Removing value from heap... "<<std::endl;

            if(test->remove()) {

                std::cout<<"Value removed!"<<std::endl;
            }

            else {

                std::cout<<"Heap is empty!"<<std::endl;
            }

        } // End of outer else if block

        else if (answer ==6) { // If the user answers six (search original tree), we let the user input a value to search for, and we search the original tree if it exists

            std::cout<<""<<std::endl;

            std::cout << "You chose 6"<<std::endl;


            std::cout<<"Deleting heap..."<<std::endl;
            test->clear();
            std::cout<<"Program Ending"<<std::endl;
            delete test;
            test = nullptr;
            break;

        } // End of outer else if block

        else if(answer ==7) { // If the value is seven, we search the cloned tree for the value passed by the user if it exists

            std::cout<<""<<std::endl;

            std::cout << "You chose 7"<<std::endl;

            std::cout<<"Attempting to Sort..."<<std::endl;

            if(test->getNumberofNodes()==0 || test->getNumberofNodes()==1) {

                std::cout<<"Sort failed"<<std::endl;
            }

            else {


                int* sort_array = new int[test->getNumberofNodes()];

                test->heapSort(sort_array);

                for(int i=0; i < test->getNumberofNodes(); i++) {

                    std::cout<<sort_array[i]<<std::endl;
                }

                delete[] sort_array;
                sort_array=nullptr;

            }




        } // End of outer else if block

        else if (answer ==8) { // If the answer is eight, we print an exit message

                std::cout<<""<<std::endl;

                std::cout<<"You chose 8"<<std::endl;

                std::cout<<"Exiting... "<<std::endl;

        }


        else { // If the choice input is not valid, we print a message

            std::cout<<"You chose " << answer << std::endl;

            std::cout<<"Enter a value between 1 and 8!"<<std::endl;

        }

    } // End of outer while loop

    delete test; // We delete the BST test
    test = nullptr;


    return 0; // Dummy return

} // End of main
