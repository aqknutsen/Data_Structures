/**
*	@file : FarmAnimal.h
*	@author : Alec Knutsen
*	@date : 2015.03.13
*   @brief: This class will contain variables representing the name and sound of an animal. We will have getter and setters methods for the name and sound. The constructor will initiall set the name and sound to "unset"
*	@brief: This class will serve as a base class for the Cow and Chicken class. Futhermore, it will be the grandfather class of CyberChicken.
*/


/**
* The ifndef, define block is used to avoid redefintion and other errors that can occur
* during compilation.
* NOTE: the #endif at the end of the file.
*/



#ifndef FARMANIMAL_H_INCLUDED
#define FARMANIMAL_H_INCLUDED


#include <string> // We include the string library since our name and sound variables will be stored as strings



class FarmAnimal {

public:


     /**
     * @pre - None
     * @post - This method sets the m_name and m_sound variables to the string "unset"
     * @param -None
     */
    FarmAnimal();


    /**
     * @pre - We assume m_name has been initialized to a valid string at construction time.
     * @post - This method returns the m_name variable.
     * @param - None
     * @return - std::string - Returns the m_name variable.
     */
    std::string getName() const;


     /**
     * @pre - We assume the method is called with a valid string as a parameter.
     * @post -This method sets the m_name variable to the string passed in as a parameter.
     * @param - std::string name - The m_name variable will be set to this parameter
     * @return - None
     */
    void setName(std::string name);


    /**
     * @pre - We assume m_sound has been initialized to a valid string at construction time.
     * @post - This method returns the m_sound variable.
     * @param - None
     * @return - std::string - Returns the m_sound variable.
     */
    std::string getSound() const;


    /**
    * @pre - We assume the method is called with a valid string as a parameter.
    * @post -This method sets the m_sound variable to the string passed in as a parameter.
    * @param - std::string sound - The m_sound variable will be set to this parameter
    * @return - None
    */
    void setSound(std::string sound);





protected:

    std::string m_name; // This variable will hold the name of the animal

    std::string m_sound; // This varaible will hold the sound of the animal


};


#endif
