/**
*	@file : main.cpp
*	@author :  Alec Knutsen
*	@date : 2014.02.19
*	@brief: This class allows the user to add to the front or back of a DoubleLinedList, allows the user to insert behind a certain value and insert ahead of a certain value, allows the user to remove a value, and allows the user to print a DoubleLinkedList.
*/

#include <iostream> // We import <iostream> library so we can get input from the user
#include <stdexcept> // We import the <stdexcept> library since the methods use this library
#include <string> // We import the <string> library

#include "DoubleLinkedList.h" // We include the "DoubleLinkedList.h" file, so we can create an object of this class

using namespace std;

void printMenu() // This method gives the options that can be selected by our user
{
    std::cout << "\n\nSelect from the following menu:\n"
            << "1) push value onto front\n"
            << "2) push value onto back\n"
            << "3) insert behind a value\n"
            << "4) insert ahead of a value\n"
            << "5) remove value\n"
            << "6) print list\n"
            << "7) Quit\n"
            << "Your choice: ";
}


int main() {
    int answer =0; // This variable will hold the input from the user
    int temp; // This will hold temporary int values
    int temp2; // This will hold temporary int values

    DoubleLinkedList<int> test; // We create a new instance of the LinkedList class to use its methods. Also, we use an int for the template

    while (answer!=7) { // This loop runs until the user answers 7 to exit

        printMenu(); // We print the menu each time the loop runs

        std::cin >> answer; // We store the users input in the variable answer
        cout <<"You chose: " << answer<<endl;


        if (answer ==1) { // If the answer is one (push to front), we get the user to input a value to add. Then, we add the answer to the front of the DoubleLinkedList

            std::cout << "Give a value: "<<endl; // We ask the user to enter a value
            std::cin >> temp; // We store the value in temp
            std:: cout<<""<<endl;
            std:: cout << temp << " added to the front of the list."<<endl;

            test.pushFront(temp); // We use the pushFront method to add the value to the front of the DoubleLinkedList



        }

        else if (answer ==2) { // If the answer is two (push to back), we get the user to input a value to add. Then, we add the answer to the back of the DoubleLinkedList

            std::cout << "Give a value: "<<endl; // We ask the user to enter a value
            std::cin >> temp; // We store the value in temp
            std:: cout<<""<<endl;
            std:: cout << temp << " added to the back of the list."<<endl;

            test.pushBack(temp); // We use the pushBack method to add the value to the back of the DoubleLinkedList

        }

        else if (answer ==3) { // If the answer is three (insertBehind), we attempt to insert a value behind some value in the list

            std::cout << "Give a value to insert."<<endl; // We ask the user to input a value to insert
            std::cin >> temp2; // We store the value to insert in temp2
            std::cout << "Pick a value to insert behind."<<endl; // We ask the user to input a value to insert behind
            std::cin >> temp; // We store the value to insert in temp
            std::cout << ""<<endl;
            std:: cout << "Attempting to insert " << temp2 << " behind " << temp <<endl;

           try { // We try to use the insertBehind method to insert the user value behind the value. If this try statement runs through, the value is added
                test.insertBehind(temp, temp2);
                std::cout<<""<<endl;
                std::cout<<temp2 << " inserted behind " << temp <<endl;
            }
           catch (std::runtime_error& e)  { // If the value cannot be added, this else statement runs. We print an error message
               std:: cout << e.what() << std::endl;
           }

        }
        else if (answer ==4) { // If the answer is four (insertAhead), we attempt to add a value in front of a certain value

            std::cout << "Give a value to insert."<<endl; // We ask the user to input a value to insert
            std::cin >> temp2; // We store the value to insert in temp2
            std::cout << "Pick a value to insert ahead of."<<endl; // We ask the user to input a value to insert behind
            std::cin >> temp; // We store the value to insert in temp
            std::cout << ""<<endl;
            std:: cout << "Attempting to insert " << temp2 << " ahead of " << temp <<endl;

           try { // We try to use the insertBehind method to insert the user value behind the value. If this try statement runs through, the value is added
                test.insertAhead(temp, temp2);
                std::cout<<""<<endl;
                std::cout<<temp2 << " inserted ahead of " << temp <<endl;
            }
           catch (std::runtime_error& e)  { // If the value cannot be added, this else statement runs. We print an error message
               std:: cout << e.what() << std::endl;
           }

        }

        else if (answer ==5) { // If the user enters five (remove), we attempt to remove a value

            std::cout << "Give a value to remove. "<<endl; // We ask the user to find a value to remove
            std::cin >> temp; // We store the value in temp
            std:: cout << "You gave " << temp <<endl;

           if(test.remove(temp)) { // If the value is found, the value is removed
                std::cout <<""<<endl;
                std::cout <<temp <<" removed from list."<<endl;
            }
           else { // If the value is not found, we tell the user so
               std:: cout << temp << " could not be removed from list."<<endl;
           }

        }

        else if (answer ==6) { // If the user answers six, we print the list

            if(test.isEmpty()) { // If the list is empty, we let the user know

                 std::cout << "List is empty."<<endl;
            }

            else { // If the list is not empty, we print the list using the printList method of the DoubleLinkedList class

            test.printList();

            }

        }

        else if(answer ==7) { // If the value is seven, we let the user know that the program is exiting

             std::cout << "" <<endl;
             std::cout << "Program Ending..."<<endl;


        }

        else { // If the user enters a number that is not 1-7, we let them know


            std::cout << "Invalid Choice."<<endl;

        }
    }
    return 0;
}

