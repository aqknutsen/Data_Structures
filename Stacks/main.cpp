/**
*	@file : main.cpp
*	@author :  Alec Knutsen
*	@date : 2014.02.26
*	@brief: This class allows the user to add to the front of two different stacks, allows the user to see the front T value of two stacks,  allows the user to print values from two stacks, allows the user to remove the front Node object of two Stacks, and allows the user to compare the sizes of two Stacks.
*/


using namespace std;


#include <iostream> // We import <iostream> library so we can get input from the user
#include <stdexcept> // We import the <stdexcept> library since the methods use this library
#include <string> // We import the <string> library, so we can use string types


#include "Stack.h" // We include our Stack class, so we can make Stack objects


/**
 * @pre - None
 * @post - This method gives the options that can be selected by our user
 * @param - None
 * @return - None
 */
void printMenu()
{
    std::cout << "\n\nSelect an action:\n"
            << "1)Add something to stack 1\n"
            << "2)Add something to stack 2\n"
            << "3) See what is at the top of stack 1\n"
            << "4) See what is at the top of stack 2\n"
            << "5) Print contents in stack 1\n"
            << "6) Print contents in stack 2\n"
            << "7) Remove something from stack 1\n"
            << "8) Remove something from stack 2\n"
            << "9) Compare Stacks\n"
            << "10) Quit\n"
            << "Enter choice: ";
}


/**
 * @pre - We assume our overloaded operators function as expected (see Stack.h class for description). Furthermore, we assume our Stack objects function as expected
 * @post - This method does all comparisions for the size of two Stacks. If the statement is true a one is shown. If the statement is false, a 0 is shown
 * @param - const StackInterface<T>& s1, const StackInterface<T>& s2 - These parameters are two StackInterface objects. Because we cannot declare objects of interfaces, and we can use derived classes as base class parameters, we will pass two Stack objects into this method.
 * @return - None
 */
template <typename T> // This method is templated
void compareStacks(const StackInterface<T>& s1, const StackInterface<T>& s2) {
    std::cout 	<< "\nComparison of stacks:\n"
            << "lane 1 < lane 2: " <<  (s1 <  s2) 	<< "\n"
            << "lane 1 > lane 2: " <<  (s1 >  s2) 	<< "\n"
            << "lane 1 >= lane 2: " << (s1 >= s2) 	<< "\n"
            << "lane 1 <= lane 2: " << (s1 <= s2) 	<< "\n"
            << "lane 1 == lane 2: " << (s1 == s2) 	<< "\n"
            << "lane 1 != lane 2: " << (s1 != s2) 	<< "\n";
}


int main() {

    int answer =0; // This variable will hold the input from the user
    std::string temp; // This will hold temporary String values

    StackInterface<std::string>* lane1 = new Stack<std::string>(); // We create a StackInterface pointer called lane1 that points to a Stack object (polymorphism)
    StackInterface<std::string>* lane2 = new Stack<std::string>();  // We create a StackInterface pointer called lane2 that points to a Stack object (polymorphism)

    while (answer!=10) { // This loop runs until the user answers 10 to exit

        printMenu(); // We print the menu each time the loop runs

        std::cin >> answer; // We store the users input in the variable answer
        std::cout <<"You chose: " << answer<<std::endl; // We print the users choice


        if (answer ==1) { // If the answer is one (add to Stack 1), we get the user to input a value to add. Then, we add the answer to the front of Stack 1

            std::cout << "What is going in Stack 1?: "<<endl; // We ask the user to enter a value
            std::cin >> temp; // We store the value in temp
            std:: cout << temp << " added sucessfuly to stack 1."<<endl;

            lane1->push(temp); // We use the push method to add the value to the front of the Stack



        }

        else if (answer ==2) { // If the answer is two (add to Stack 2), we get the user to input a value to add. Then, we add the answer to the front of Stack 2


            std::cout << "What is going in Stack 2?: "<<endl; // We ask the user to enter a value
            std::cin >> temp; // We store the value in temp
            std:: cout << temp << " added sucessfuly to stack 2."<<endl;

            lane2->push(temp); // We use the push method to add the value to the front of Stack 2.
        }

        else if (answer ==3) { // If the answer is three (peek at the top of Stack 1), we attempt to return the T value at the top of Stack 1



           try { // We try to use the peek method. If this try statement runs through, the T value is shown to the user.

               std::cout<<lane1->peek()<<std::endl;

            }

           catch (std::exception& e)  { // If the Stack is empty, this catch statement runs. We print an error message

               std:: cout << e.what() << std::endl;

           }

        }
        else if (answer ==4) { // If the answer is four (peek at the top of Stack 2), we attempt to return the T value at the top of Stack 2


            try { // We try to use the peek method. If this try statement runs through, the T value is shown to the user.

                std::cout<<lane2->peek()<< std::endl;

             }

            catch (std::exception& e)  { // If the Stack is empty, this catch statement runs. We print an error message

                std:: cout << e.what() << std::endl;

            }

        }

        else if (answer ==5) { // If the user enters five (print Stack 1), we use the print method to print Stack 1

           lane1->print();

        }

        else if (answer ==6) { // If the user enters six (print Stack 2), we use the print method to print Stack 2
            lane2->print();

        }

        else if(answer ==7) { // If the user enters seven (remove from Stack 1), we attempt to remove a value from Stack 1.


            try { // We try to use the pop method to remove the front Node object. If this try statement runs through, the object is removed

                std::cout << lane1->pop() << " removed from stack 1"<<endl;

             }
            catch (std::exception& e)  { // If the Stack is empty, this catch block runs. We print an error message

                std:: cout << e.what() << std::endl;

            }


        }

        else if(answer ==8) { // If the user enters eight (remove from Stack 2), we attempt to remove a value from Stack 2.

            try { // We try to use the pop method to remove the front Node object. If this try statement runs through, the object is removed

               std::cout << lane2->pop() << " removed from stack 2"<<endl;

             }

            catch (std::exception& e)  { // If the Stack is empty, this catch block runs. We print an error message

                std:: cout << e.what() << std::endl;

            }

        }

        else if(answer ==9) { // If the user enters nine (compare stacks), we call the comapreStacks method on our two Stack objects to compare the size of the Stacks.

           compareStacks(*lane1,*lane2);
        }

        else if(answer == 10) { // If the user enters ten, the loop breaks, and the program ends.

            std::cout << "" <<endl;
            std::cout << "Program Ending..."<<endl;
        }

        else { // If the user enters a number that is not 1-10, we let them know.


            std::cout << "Invalid Choice."<<endl;

        }

    }

    delete lane1; // We delete our StackInterface pointer lane1
    delete lane2; // We delete our StackInterface pointer lane2


    return 0;

}
