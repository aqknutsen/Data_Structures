/**
*	@file : Chicken.h
*	@author : Alec Knutsen
*	@date : 2015.03.13
*	@brief: This method inherits from the FarmAnimal Class. It inherits the name and sound variables of FarmAnimal along with the getters and setters for each variable.
*   @brief: This method has its own variable m_eggs and corresponding getters and setters. The constructor sets the name to Chicken and sound to cluck. The desctructor is the default destructor.
*/


/**
* The ifndef, define block is used to avoid redefintion and other errors that can occur
* during compilation.
* NOTE: the #endif at the end of the file.
*/

#ifndef CHICKEN_H_INCLUDED
#define CHICKEN_H_INCLUDED

#include "FarmAnimal.h"  // We include the FarmAnimal class so we can inherit from it.

class Chicken: public FarmAnimal { // We inherit from the FarmAnimal class


public: // The constructor and destructor of this class are public


    /**
    * @pre - None
    * @post - This constructor sets m_name to Chicken and m_sound to Cluck at construction time
    * @param - None
    */
    Chicken();



    /**
    * @pre - None
    * @post - This desctructor will delete a Chicken object after it is removed by the stack or called by the delete keyword.
    * @param - None
    */
   ~Chicken();


protected: // The m_eggs variable, getEggs and setEggs methods are protected. They can be used freely within a derived class, but cannot be used by instances of a Chicken object.


    /**
    * @pre - We assume the m_eggs variable has been initialized at construction time
    * @post - This method returns the m_eggs variable
    * @param - None
    * @return - int - Represents m_eggs
    */
    int getEggs() const;



     /**
     * @pre - We assume the parameter passed into this method is a valid integer
     * @post - This method sets the m_eggs variable to the parameter passed in
     * @param - int eggs
     * @return - None
     */
    void setEggs(int eggs);



    int m_eggs; // Represents the number of eggs of the chicken



};

#endif
