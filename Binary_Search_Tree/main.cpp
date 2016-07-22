/**
*	@file :main.cpp
*	@author : Alec Knutsen
*	@date : 2015.04.13
*	@brief: main.cpp allows the user to interact with a BST
*/


#include <iostream> // We import iostream so we can get input from the user

#include <random> // We import random to generate random numbers
#include <ctime> // We import ctime to seed the random number generator

#include <cstdlib> // We include cstdlib to import atoi so we can convert command line arguments to integers


#include "BinarySearchTree.h" // We include BinarySearchTree.h, so we can use its methods



 /**
 * @pre - None
 * @post - This method gives the options that can be selected by our user
 * @param - None
 * @return - None
 */
void printMenu() {

    std::cout << "\n\nSelect from the following menu:\n"
            << "1) Add more values to original tree\n"
            << "2) Copy the original tree\n"
            << "3) Delete the original tree (one time only)\n"
            << "4) Print original tree\n"
            << "5) Print copy\n"
            << "6) Search original tree\n"
            << "7) Search copy\n"
            << "8) Exit\n"
            << "9) Sum Tree\n"
            << "10) Depth Tree\n"
            << "11) Num Nodes\n"
            << "Enter your choice: ";
}

 /**
 * @pre - None
 * @post - main.cpp allows the user to interact with a BST
 * @param - int arc - Number of command line arguments, char** argv - Command line arguments
 * @return - int - dummy return
 */
int main(int argc, char** argv) {

    std::default_random_engine generator(time(nullptr)); // We create a new generator and seed it
    std::uniform_int_distribution<int> distribution(-32000 ,32000); // We create a distribution which can generate numbers from -32000 to 32000



    BSTI<int>* test = new BinarySearchTree<int>(); //We create a new instance of BSTI pointer called test that points to a BinarySearchTree

    BSTI<int>* test2 = nullptr; //We create a new instance of BSTI pointer called test2 that points to a nullptr. It will be a copy of test if the user desires to clone the BST pointed at by test.

    if(argc ==2) {  // If the user passes in an extra command line argument, we fill the BST pointed at by test with the number of random values passed in by the user

        if(atoi(argv[1]) <= 0) { // If the user enters a negative number. We add no Nodes to the tree and print a message


            std::cout<<"We can not add a negative amount of numbers to the tree!"<<std::endl;

        }

        else { // If the user does enter a valid number of values, we proceed

            std::cout << "Filling original tree with " << atoi(argv[1]) << " values."<<std::endl;

            for (int i=0; i < std::atoi(argv[1]); i++) { // We use a for loop to populate the BSt

                int random_num = distribution(generator); // Get a random number

                std::cout<<"Adding " << random_num << " to original tree "<<std::endl;

                test->add(random_num); // Use the add method to put the value in the BST

            } // End of for loop

        } // End of inner else block

    } // End of outer if block


    int answer=0; // This variable will hold the input from the user for what option to select.
    int temp; // This will hold temporary int values


    while (answer!=8) { // This loop runs until the user answers 8 to exit

        printMenu(); // We print the menu each time the loop runs

        std::cin >> answer; // We store the users input in the variable answer


        if (answer ==1) { // If the answer is one (add), we get the user to input a value to add. Then, we add the answer to the BST pointed at by test.

            std::cout<<""<<std::endl;

            std::cout << "You chose 1"<<std::endl;


            if(test==nullptr) { // If test has been deleted, we cannot add the value

                std::cout<<"The tree does not exist. Cannot add."<<std::endl;

            }

            else { // If test is a valid BST, we add the value

            std::cout << "Input a value to add to the original: "<<std::endl;
            std::cin >> temp;
            std:: cout << "Adding " << temp << " to the original tree.."<<std::endl;

            test->add(temp); // We use the add method of the BinarySearchTree class

            }


        }

        else if (answer ==2) { // If the answer is two clone, we clone the BST pointed at by Test if it has not been deleted.

            std::cout<<""<<std::endl;

            std::cout << "You chose 2"<<std::endl;



            if(test==nullptr) { // If the test BST has been deleted, we print an error message.

                std::cout<<"The tree does not exist. Cannot clone."<<std::endl;

            }

            else { //If the test BST has not been deleted, we clone the tree and store the clone in test2

            std::cout<< "Cloning the binary search tree.."<<std::endl;

            test2 =test->clone(); // We use the clone method of Binary Search Tree


            }


        }

        else if (answer ==3) { // If the answer is three (delete original), we attempt to remove the tree pointed at by Test

            std::cout<<""<<std::endl;

            std::cout << "You chose 3"<<std::endl;



            if(test==nullptr) { // If the test tree has been deleted, we print an error message

                std::cout<<"The tree does not exist. Cannot delete."<<std::endl;

            }

            else { // If the test tree has not been deleted, we delete it and point test at nullptr


                delete test;

                test = nullptr;

                std::cout<< "Original tree deleted"<<std::endl;

            }

        }

        else if (answer ==4) { // If the user enters four (print the original tree), we attempt to print the tree in the order specified by the user if the tree exists


            std::cout<<""<<std::endl;

            std::cout << "You chose 4"<<std::endl;



            if(test==nullptr) { // If the tree has been deleted, we print an error message

                 std::cout<<"The tree does not exist. Cannot print."<<std::endl;

            }

            else { // If the tree is valid, we let the user chose which order to print in.

                int choice_order;

                std::cout << "\n\nprint order options:\n"
                << "0 - pre-order\n"
                << "1 - in-order\n"
                << "2 - post-order\n"
                << "Enter your choice: ";
                std::cin>>choice_order;

                while (choice_order < 0 || choice_order > 2) { // This runs until the user enters a valid choice

                    std::cout << "\n\nprint order options:\n"
                    << "0 - pre-order\n"
                    << "1 - in-order\n"
                    << "2 - post-order\n"
                    << "Enter your choice: ";
                    std::cin>>choice_order;

                }

                std::cout<<"You chose: "<<choice_order<<std::endl;

                if (choice_order==0) { // If the choice is one (PRE), we use the printTree method with PRE_ORDER

                    test->printTree(PRE_ORDER);

                }

                 else if (choice_order==1) { // If the choice is two (IN), we use the printTree method with IN_ORDER

                    test->sortedPrint();

                }

                else { // If the choice is one (POST), we use the printTree method with POST_ORDER

                    test->printTree(POST_ORDER);

                }


            } // End of outer else block



        } // End of outer else if block

        else if (answer ==5) { // If the user answers five, we attempt to print the cloned tree in a specified order if the tree exists

            std::cout<<""<<std::endl;

            std::cout << "You chose 5"<<std::endl;


            if(test2==nullptr) { // If the  cloned tree has been deleted, we print an error message

                std::cout<<"The tree does not exist. Cannot print."<<std::endl;

            }

            else { // If the cloned tree is valid, we let the user chose which order to print in.

                int choice_order;

                std::cout << "\n\nprint order options:\n"
                << "0 - pre-order\n"
                << "1 - in-order\n"
                << "2 - post-order\n"
                << "Enter your choice: ";
                std::cin>>choice_order;

                while (choice_order < 0 || choice_order > 2) { // This runs until the user enters a valid choice

                    std::cout << "\n\nprint order options:\n"
                    << "0 - pre-order\n"
                    << "1 - in-order\n"
                    << "2 - post-order\n"
                    << "Enter your choice: ";
                    std::cin>>choice_order;

                }

                std::cout<<"You chose: "<<choice_order<<std::endl;

                if (choice_order==0) { // If the choice is one (PRE), we use the printTree method with PRE_ORDER

                    test2->printTree(PRE_ORDER);

                }

                 else if (choice_order==1) { // If the choice is two (IN), we use the printTree method with IN_ORDER

                    test2->sortedPrint();

                }

                else { // If the choice is one (POST), we use the printTree method with POST_ORDER

                    test2->printTree(POST_ORDER);
                }

            } // End of outer else block

        } // End of outer else if block

        else if (answer ==6) { // If the user answers six (search original tree), we let the user input a value to search for, and we search the original tree if it exists

            std::cout<<""<<std::endl;

            std::cout << "You chose 6"<<std::endl;


          if(test==nullptr) { // If the tree has been deleted, we print an error message

                std::cout<<"The tree does not exist. Cannot search."<<std::endl;

          }

          else { // If the tree exists, we search for the value

            std::cout << "Enter a value to search for "<<std::endl;
            std::cin >> temp;
            std:: cout << "Searching for " << temp<< " in the original tree..."<< std::endl;

            try { // We try to use the search method to to find the value. If this try statement runs through, the value is found

                test->search(temp);

                std::cout<<""<<std::endl;

                std::cout<<temp << " found in tree." <<std::endl;

            }

            catch (ValueNotFoundException& e)  { // If the value cannot be found, this else statement runs. We print an error message

               std:: cout << e.what() << std::endl;

            }


          } // End of else block


        } // End of outer else if block

        else if(answer ==7) { // If the value is seven, we search the cloned tree for the value passed by the user if it exists

            std::cout<<""<<std::endl;

            std::cout << "You chose 7"<<std::endl;


           if(test2==nullptr) { // If the cloned tree has been deleted, we print an error message

                std::cout<<"The tree does not exist. Cannot search."<<std::endl;

          }

          else {

            std::cout << "Enter a value to search for "<<std::endl;
            std::cin >> temp;
            std:: cout << "Searching for " << temp<< " in the cloned tree..."<< std::endl;

            try { // If the cloned tree exists, we search for the value

                test2->search(temp);

                std::cout<<""<<std::endl;

                std::cout<<temp << " found in tree." <<std::endl;

            }

            catch (ValueNotFoundException& e)  { // If the value cannot be found, this catch statement runs. We print an error message

               std:: cout << e.what() << std::endl;

            }


          } // End of else block

        } // End of outer else if block

        else if (answer ==8) { // If the answer is eight, we print an exit message

                std::cout<<""<<std::endl;

                std::cout<<"You chose 8"<<std::endl;

                std::cout<<"Exiting... "<<std::endl;

        }

        else if (answer ==9) { // If the answer is eight, we print an exit message

                std::cout<<""<<std::endl;

                std::cout<<"You chose 9"<<std::endl;

                std::cout<<"Summing Values of original tree "<<std::endl;

                std::cout<<test->sumEntireTree();

        }

         else if (answer ==10) { // If the answer is eight, we print an exit message

                std::cout<<""<<std::endl;

                std::cout<<"You chose 10"<<std::endl;

                std::cout<<"Getting Depth of original tree "<<std::endl;

                std::cout<<test->maxDepth();

        }

         else if (answer ==11) { // If the answer is eight, we print an exit message

                std::cout<<""<<std::endl;

                std::cout<<"You chose 11"<<std::endl;

                std::cout<<"Getting number of nodes of original tree "<<std::endl;

                std::cout<<test->countNodes();

        }

        else { // If the choice input is not valid, we print a message

            std::cout<<"You chose " << answer << std::endl;

            std::cout<<"Enter a value between 1 and 8!"<<std::endl;

        }

    } // End of outer while loop

    delete test; // We delete the BST test
    delete test2; // We delete the BST test1


    return 0; // Dummy return

} // End of main
