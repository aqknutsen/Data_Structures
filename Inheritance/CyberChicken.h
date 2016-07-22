/**
*	@file : CyberChicken.h
*	@author :  Alec Knutsen
*	@date : 2015.03.13
*	@brief: This method inherits from the grandfather class FarmAnimal and the parent class Cchicken.
*   @ brief: It inherits the name and sound variables of FarmAnimal along with the getters and setters for each variable. Also, it inherits the protected variable m_eggs and corresponding getters and setters from the Chicken class
*   @brief: This method has getter and setter methods for the m_eggs variable inherited from the Chicken class. The constructor sets the name to CyberChicken and sound to Resistance is Futile. The desctructor is the default destructor.
*/


/**
* The ifndef, define block is used to avoid redefintion and other errors that can occur
* during compilation.
* NOTE: the #endif at the end of the file.
*/

#ifndef CYBERCHICKEN_H_INCLUDED
#define CYBERCHICKEN_H_INCLUDED


#include "Chicken.h" // We include the Chicken.h file, so we can inherit from it. Note that since Chicken inherits from FarmAnimal, we will get all the public and protected methods and variables from the FarmAnimal class.

class CyberChicken: public Chicken { // We inherit from the Chicken class

public: // All varaibles and methods in this class are public


    /**
    * @pre - None
    * @post - This constructor sets m_name to CyberChicken and m_sound to Resistance is Futile at construction time
    * @param - None
    */
    CyberChicken();



    /**
    * @pre - None
    * @post - This desctructor will delete a CyberChicken object after it is removed by the stack or called by the delete keyword.
    * @param - None
    */
    ~CyberChicken();



    /**
    * @pre - We assume the m_eggs variable inherited from the CyberChicken class has been initialized at construction time
    * @post - This method returns the m_eggs variable
    * @param - None
    * @return - int - Represents m_eggs
    */
    int getCyberEggs() const;




    /**
    * @pre - We assume the parameter passed into this method is a valid integer
    * @post - This method sets the m_eggs variable inherited from the Chicken class to the parameter passed in
    * @param - int eggs
    * @return - None
    */
    void setCyberEggs(int eggs);

};


#endif
