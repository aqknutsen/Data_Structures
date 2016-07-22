/**
*	@file : main.cpp
*	@author :  Alec Knutsen
*	@date : 2014.02.06
*	@brief: This class allows the user to add to the front or back of a linkedlist, allows the user to remove from the front or back of a linkedlist, print a linkedlist, and search for a value in a linkedlist.
*/

#include <iostream> // We import iostream so we can get input from the user
#include "LinkedList.h"

using namespace std;

void printMenu() // This method gives the options that can be selected by our user
{
    std::cout << "\n\nSelect from the following menu:\n"
            << "1) Add to the front of the list\n"
            << "2) Add to the end of the list\n"
            << "3) Remove from front of the list\n"
            << "4) Remove from back of the list\n"
            << "5) Print the list\n"
            << "6) Search for value\n"
            << "7) Exit\n"
            << "8) Move Node\n"
            << "9) Remove Node\n"
            << "10) Insert Node\n"
            << "Enter your choice: ";
}


int main()
{
    int answer; // This variable will hold the input from the user
    int temp; // This will hold temporary int values
    bool my_bool; // A variable that will temporarily hold booleans

    LinkedList test; // We create a new instance of the LinkedList class to use its methods

    while (answer!=7) { // This loop runs until the user answers 7 to exit

        printMenu(); // We print the menu each time the loop runs

        std::cin >> answer; // We store the users input in the variable answe


        if (answer ==1) { // If the answer is one (add to front), we get the user to input a value to add. Then, we add the answer to the front of the linkedlist

            std::cout << "You chose 1"<<endl;
            std::cout << "Input a value to add: "<<endl;
            std::cin >> temp;
            std:: cout << "Adding " << temp << " to the list..."<<endl;

            test.addFront(temp); // We use the add front method of the LinkedList class



        }

        else if (answer ==2) { // If the answer is two (add to back), we get the user to input a value to add. Then, we add the answer to the back of the linkedlist

            std::cout << "You chose 2"<<endl;
            std::cout << "Input a value to add: "<<endl;
            std::cin >> temp;
            std:: cout << "Adding " << temp << " to the list..."<<endl;

            test.addBack(temp); // We use the add back method of the LinkedList class

        }

        else if (answer ==3) { // If the answer is three (removeFront), we attempt to remove a value from the front of the list

            std::cout << "You chose 3"<<endl;
            std::cout<< "Attempting removal from front of list.."<<endl;

            my_bool = test.removeFront(); // We call the removeFront method of the Linkedlist class

            if(my_bool) { // If the removal is successful, we print a statement letting the user know
                 std::cout << "Removal Successful."<<endl;
            }

            else { // If the removal is not successful, we print a statement letting the user know
                 std::cout << "There are no values to remove."<<endl;
            }

        }

        else if (answer ==4) { // If the user enters four (removeBack), we attempt to remove a value from the back of the list

            std::cout << "You chose 4"<<endl;
            std::cout<< "Attempting removal from the back of list.."<<endl;


            my_bool = test.removeBack(); // We call the removeBack method of the LinkedList class

            if(my_bool) { // If the removal is successful, we print a statement letting the user know
                 std::cout << "Removal Successful."<<endl;
            }

            else { // If the removal is not successful, we print a statement letting the user know
                 std::cout << "There are no values to remove."<<endl;
            }

        }

        else if (answer ==5) { // If the user answers five, we print the list

            std::cout << "You chose 5"<<endl;
            std::cout << "Printing List..."<<endl;

            if(test.isEmpty()) { // If the list is empty, we let the user know

                 std::cout << "List is empty."<<endl;
            }

            else { // If the list is not empty, we print the list using the printList method of the LinkedList class

            test.printList();

            }

        }

        else if (answer ==6) { // If the user answers six (search), we let the user input a value to search for

            std::cout << "You chose 6"<<endl;
            std::cout << "Enter a value to search for: "<<endl;
            std::cin >> temp;
            std:: cout << "Searching for " << temp<< "..."<< endl;

           my_bool = test.search(temp); // We use the search method of the LinkedList class to search for the value


           if (my_bool) { // If the value is in the list, we let the user know
               std::cout << temp << " is in the list!"<<endl;
           }

           else { // If the value is not in the list, we let the user know
               std::cout << temp << " is not in the list!"<<endl;
           }


        }

        else if(answer ==7) { // If the value is seven, we let the user know that the program is exiting

             std::cout << "You chose 7"<<endl;
             std::cout << "Exiting..."<<endl;


        }

        else if (answer ==8) { // If the user answers six (search), we let the user input a value to search for

            int start = 0;
            int endi = 0;
            std::cout << "You chose 8" <<endl;
            std::cout << "Enter a start index "<<endl;
            std::cin >> start;
            std::cout << "Enter an end index "<<endl;
            std::cin >> endi;
            std:: cout << "Attempting Swap " <<std::endl;

            try {

                test.moveNode(start,endi);

            }

            catch(std::runtime_error& e) {

                std::cout<<e.what()<<std::endl;


            }


        }

        else if (answer ==9) { // If the user answers six (search), we let the user input a value to search for

            int index = 0;
            std::cout << "You chose 8" <<endl;
            std::cout << "Enter an index to remove "<<endl;
            std::cin >> index;
            std:: cout << "Attempting Removal " <<std::endl;

            try {

                test.removeAt(index);
                std::cout<<"Removal Successful"<<std::endl;

            }

            catch(std::runtime_error& e) {

                std::cout<<e.what()<<std::endl;


            }


        }

        else if (answer ==10) { // If the user answers six (search), we let the user input a value to search for

            int index = 0;
            int value =0;
            std::cout << "You chose 10" <<endl;
            std::cout << "Enter an index to add at "<<endl;
            std::cin >> index;
             std::cout << "Enter a value to add "<<endl;
            std::cin >> value;
            std:: cout << "Attempting Addition " <<std::endl;

            try {

                test.insertAt(index, value);
                std::cout<<"Addition Successful"<<std::endl;

            }

            catch(std::runtime_error& e) {

                std::cout<<e.what()<<std::endl;


            }


        }

        else { // If the user enters a number that is not 1-7, we let them know

            std::cout << "You chose " << answer<<endl;

            std::cout << "Invalid Choice."<<endl;

        }
    }

    return 0;
}
