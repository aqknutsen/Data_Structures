/**
*	@file : AnimalPen.h
*	@author : Alec Knutsen
*	@date : 2015.03.13
*	@brief: This class inherits from the Stack class. As a result, it inherits the push, pop, peak, size, and isEmpty methods from the Stack class.
*   @brief: This class is a specialized stack. The Nodes it contains will hold a FarmAnimal pointer to a FarmAnimal object (can be Cow, Chicken, or CyberChicken). Each Node also contains a pointer to the next Node object.
*   @brief: This class contains methods that allow you to push an Animal pointer onto the front of the stack, peak at the front Animal pointer, release the front Node Object, and check if the AnimalPen (Stack) is Empty
*   @brief: The constructor is the deafult constructor
*   @brief:The destructor first deletes the object that the FarmAnimal pointer points to in each Node. Then, it uses the releaseAnimal method to remove the corresponding Node. This runs into all Nodes are released of the Stack are removed.
*/



/**
* The ifndef, define block is used to avoid redefintion and other errors that can occur
* during compilation.
* NOTE: the #endif at the end of the file.
*/



#ifndef ANIMALPEN_H_INCLUDED
#define ANIMALPEN_H_INCLUDED


#include "Stack.h" // We include the Stack.h that we inherit from


/**
*We include FarmAnimal and all of its descendants, since we cast to FarmAnimal descendants in our destructor.
*/
#include "FarmAnimal.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"


#include <iostream> // We include iostream because we print statements in the destructor



class AnimalPen: public Stack<FarmAnimal*> {

public: // All methods are public


    /**
     * @pre - None
     * @post - Default Constructor
     * @param - None
     */
    AnimalPen();


    /**
     * @pre - We assume each element in the stack contains a valid FarmAnimal pointer that points to a FarmAnimal or one of its descendants. We also assume the releaseAnimal() method functions properly.
     * @post - The destructor first deletes the object that the FarmAnimal pointer points to in each Node. Then, it uses the releaseAnimal method to remove the corresponding Node. This runs into all Nodes are released of the Stack are removed.
     * @post - Each time a FarmAnimalPointer is removed we print the corresponding number of milk or eggs the animal produced, we print the goodbye message, and we print the destructor called message. At the end, we print the total milk and eggs produced by all animals in the stack.
     * @param -None
     */
   ~AnimalPen();


     /**
     * @pre - We assume the push method of the Stack class works properly
     * @post - This methods uses the push method of the Stack class to add a Node containing an FarmAnimal pointer to the AnimalPen stack.
     * @param - FarmAnimal* animal - Represents the FarmAnimal pointer put in the New Node
     * @return - None
     */
    void addAnimal(FarmAnimal* animal);


    /**
    * @pre - We assume the peek method of the Stack class works properly
    * @post - This methods uses the peek method of the Stack class to return the FarmAnimal pointer in the Node that was added last to the Stack
    * @param - None
    * @return - FarmAnimal* - Returns
    *  the FarmAnimal pointer in the Node that was added last to the Stack
    */
    FarmAnimal* peakAtNextAnimal();


    /**
    * @pre - We assume the pop method of the Stack class works properly
    * @post - This methods uses the pop method of the Stack class to remove a Node containing an FarmAnimal pointer from the AnimalPen stack.
    * @param - None
    * @return - None
    */
    void releaseAnimal();


    /**
    * @pre - We assume the isEmpty method of the Stack class works properly
    * @post - This methods returns true if our AnimalPen Stack is empty. Otherwise, it returns false
    * @param - None
    * @return - bool
    */
    bool isPenEmpty();




};

#endif
