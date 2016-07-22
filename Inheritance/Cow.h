/**
*	@file : Cow.h
*	@author : Alec Knutsen
*	@date : 2015.03.13
*	@brief: This method inherits from the FarmAnimal Class. It inherits the name and sound variables of FarmAnimal along with the getters and setters for each variable.
*   @brief: This method has its own variable m_milkProduced and corresponding getters and setters. The constructor sets the name to Cow and sound to Moo. The desctructor is the default destructor.
*/


/**
* The ifndef, define block is used to avoid redefintion and other errors that can occur
* during compilation.
* NOTE: the #endif at the end of the file.
*/


#ifndef COW_H_INCLUDED
#define COW_H_INCLUDED

#include "FarmAnimal.h" // We include the FarmAnimal class so we can inherit from it.

class Cow: public FarmAnimal { // We inherit from the FarmAnimal class

public: // The destructor and constructor and the getters and setters are public


     /**
     * @pre - None
     * @post - This constructor sets m_name to Cow and m_sound to Moo
     * @param - None
     */
    Cow();


   /**
   * @pre - None
   * @post - This desctructor will delete a Cow object after it is removed by the stack or called by the delete keyword.
   * @param - None
   */
    ~Cow();


     /**
     * @pre - We assume the m_milkProduced variable has been initialized at construction time
     * @post - This method returns the m_milkProduced variable
     * @param - None
     * @return - double - Represents m_milkProduced
     */
    double getMilkProduced() const;


    /**
     * @pre - We assume a double has been passed as a parameter to the method
     * @post - If the double parameter is greater than zero, the method sets the m_milkProduced varaible to the parameter. If the parameter is less than or equal to 0, m_milkProduced is set to 0.
     * @param -
     * @return -
     */
    void setMilkProduced(double gallons);



protected: // The m_milkProduced variable is protected. It can be used freely in inherited class. It cannot be accessed directly through the instance of a Cow object.

    double m_milkProduced; // Represents the milk the cow produced.



};

#endif
