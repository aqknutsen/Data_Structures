/**
*	@file : AnimalPen.cpp
*	@author : Alec Knutsen
*	@date : 2015.03.13
*	@brief: Implementation of the AnimalPen class
*/


# include "AnimalPen.h" // We include the corrsponding AnimalPen.h file



AnimalPen::AnimalPen() {}; // Default constructor




AnimalPen::~AnimalPen() {

   double total_milk = 0; // This variable will hold the milk produced by the whole FarmAnimal stack
   double total_eggs = 0; // This variable will hold the eggs produced by the whole FarmAnimal stack

    while(!(isPenEmpty())) { // While the AnimalPen Stack is not empty, this statement runs


    FarmAnimal* a = this->peakAtNextAnimal(); // We return the FarmAnimal pointer contained in the front Node of the AnimalPen Stack


    if (a->getName()=="CyberChicken") { // If the pointer points to a Cyberchicken object, this if statement runs

            CyberChicken* chick1 = static_cast <CyberChicken*>(a); // We cast the FarmAnimal pointer to a CyberChicken pointer so we can use the getcyberEggs method of the CyberChicken class

             std::cout << "This Cyber Chicken laid " << chick1->getCyberEggs() << " cyber eggs.Humanity is in trouble."<<std::endl; // We print the number of eggs

             total_eggs += chick1->getCyberEggs(); // We add the number of eggs to our cumulative total

             std::cout <<  "Upon release the "<<chick1->getName()<< " said " <<chick1->getSound() << "."<<std::endl; // We print a goodbye message

             std::cout << "CyberChicken Destructor called."<<std::endl; // We print the destructor called statement

             std::cout<<""<<std::endl;


        }


        else if (a->getName()=="Chicken") { // If the pointer points to a Chicken object, this if statement runs

             Chicken* chick2 = static_cast <Chicken*>(a);

             std::cout << "Chicken unable to lay eggs.Perhaps cybornetic implants will help?"<<std::endl; // We print a message

             std::cout <<  "Upon release the "<<chick2->getName()<< " said " <<chick2->getSound() << "."<<std::endl; // We print a goodbye message

             std::cout << "Chicken Destructor called."<<std::endl; // We print the destructor called statement


             std::cout<<""<<std::endl;

        }


        else if (a->getName()=="Cow") { // If the pointer points to a Cow object, this if statement runs

              Cow* cow1 = static_cast <Cow*>(a);

              std::cout << "This cow produced " << cow1->getMilkProduced() << " gallons of milk."<<std::endl; // We print the amount of milk produced by the cow

              total_milk += cow1->getMilkProduced(); // We add the milk to our cumulative total

              std::cout <<  "Upon release the "<<cow1->getName()<< " said " <<cow1->getSound() << "."<<std::endl; // We print a goodbye message

              std::cout << "Cow Destructor called."<<std::endl; // We print the destructor called statement


              std::cout<<""<<std::endl;

        }


        delete a; // We delete the FarmAnimal pointer


        this->releaseAnimal(); // We release the Node containing the FarmAnimal pointer we removed

    } // End of while loop


    std::cout<<"Your farm produced " << total_milk <<  " of milk and "  << total_eggs<< " eggs."; // We print the toal number of eggs and milk produced by the Animal Pen Stack

}




void AnimalPen::addAnimal(FarmAnimal* animal) { // We use the push method inherited from the Stack Class to add Node containing a FarmAnimalPointer to the stack

        this->push(animal);


}




FarmAnimal* AnimalPen::peakAtNextAnimal() { // We use the peak method inherited from the Stack Class to return the FarmAnimal pointer at the front of the AnimalPen Stack

    return(this->peek());


}




void AnimalPen::releaseAnimal() { // We use the pop method inherited from the Stack Class to release the front Node in the AnimalPen Stack.

    this->pop();

}




bool AnimalPen::isPenEmpty() { // This method uses the isEmpty method of the Stack class to determine if a AnimalPen Stack is empty.

    if (this->isEmpty()) { // If the pen is empty, we return true

        return(true);

    }

    else { // If the pen is not empty, we return false

        return(false);

    }

}
