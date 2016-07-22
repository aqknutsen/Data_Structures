/**
*	@file : main.cpp
*	@author : Alec Knutsen
*	@date : 2015.03.13
*	@brief: The main file creates a Stack and lets a user add animals to the stack as long as they want. It release all animals, and the AnimalPen destructor handles all print statements.
*/


#include <iostream> // We include the iostream library since we print stuff
#include <string> // We include the string library since we use strings in main

using namespace std;


/**
*We include all of FarmAnimal's descendants so we can create instance of Cows, Chickens, and CyberChickens. Also, we include AnimalPen, so we can make an AnimalPen stack to store our FarmAnimal pointers.
*/
#include "AnimalPen.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"



/**
 * @pre - We return the parameter passed is a valid FarmAnimal object or a valid one of its descendants.
 * @post - This method will print a statement including the FarmAnimal's name and sound
 * @Note - This method is not used since the AnimalPen destructor handles all the print statements
 * @param - const FarmAnimal& animal - Represents the Animal object passed in. It could be of type FarmAnimal, Cow, Chicken, or CyberChicken. We pass the object by reference so we alter the object itself, not a copy of the object.
 * @return -
 */
void goodbyeMessage(const FarmAnimal& animal) {

    cout <<  "Upon release the "<<animal.getName()<< " said " <<animal.getSound() << "."<<endl; // We print the statement containing the parameters corresponding name and sound


}




/**
 * @pre - We assume the addAnimal method works properly. Also, we assume each animal's corresponding eggs or milk methods work properly. Finally, we assume the AnimalPen destructor works.
 * @post - The main file creates a Stack and lets a user add animals to the stack as long as they want. It release all animals, and the AnimalPen destructor handles all print statements.
 * @Note - This goodbyeMessage method is not used since the AnimalPen destructor handles all the print statements
 * @param - None
 * @return - int - We return 0
 */
int main()

{

    std::string answer = "n"; // This variable holds the user choice to keep adding animals

    int choice; // This variable holds the choice of which animal type the user wants to add

    double choice2; // This variable holds the choice of how many eggs or how many gallons of milk the user wants to add


    AnimalPen* new_pen = new AnimalPen(); // We create an AnimalPen pointer called new_pen


    while (answer!= "y") { // While the user wants to keep adding animals, this while loop runs

        // We print a menu

        std::cout<< "Select an animal to add to the pen:"<<endl;
        std::cout<< "1.) Cow (produces milk)"<<endl;
        std::cout<< "2.) Chicken (cannot lay eggs)"<<endl;
        std::cout<< "3.) Cyber Chicken (seems dangerous, but lays eggs)"<<endl;
        std::cin>>choice;
        std::cout<<"---------------------------------------------------"<<endl;
        std::cout<<""<<endl;


        if (choice ==1) { // If the user wants to add a cow, this if statement runs

             Cow* c = new Cow(); // We create a Cow pointer
             std::cout<< "choice: How many gallons of milk did this cow produce?:"<<endl; // We get user input for gallons of milk

             std::cin>>choice2;

             c->setMilkProduced(choice2); // We set the gallons of milk of the corresponding Cow object

             new_pen->addAnimal(c); // We add the Cow to the AnimalPen Stack

        }

        else if (choice ==2) { // If the user wants to add a chicken, this if statement runs

             Chicken* ch = new Chicken(); // We create a Chicken pointer

             std::cout<< "choice: Add an eggless chicken to the pen? OK. You're the boss."<<endl; // We print a statement

             new_pen->addAnimal(ch); // We add the Chicken to the AnimalPen Stack

        }

        else if (choice ==3) { // If the user wants to add a CyberChicken, this if statement runs

           CyberChicken* cch = new CyberChicken(); // We create a CyberChicken pointer

            std::cout<< "choice: How many eggs did this cyber chicken produce?:"<<endl; // We get user input for number of eggs

            std::cin>>choice2;

            cch->setCyberEggs(choice2); // We set the number of eggs of the corresponding CyberChicken object
            new_pen->addAnimal(cch); // We add the CyberChicken to the AnimalPen Stack

        }


        std::cout<<""<<endl;
        std::cout << "Done adding animals? (y/n): "<<endl; // We ask the user if they want to add another animal
        std::cin >> answer; // We store the input in the variable answer
        std::cout<<""<<endl;

    } // End of While Loop


    std::cout<<"Releasing all animals!"<<endl; // We let the user know the AnimalPen destructor will be called after they do not want to add anymore animals
    std::cout<<""<<endl;
    std::cout<<"-------------------------"<<endl;
    std::cout<<""<<endl;


    delete new_pen; // We call the destroctuor of AnimalPen

    return 0;

}
