/**
*	@file : Chicken.cpp
*	@author : Alec Knutsen
*	@date : 2015.03.13
*	@brief: Implementation of the Chicken class
*/



#include "Chicken.h" // We include the corresponding Chicken.h file


Chicken::Chicken() {  // This constructor sets the m_name and m_sound variables of the chicken inherited from FarmAnimal

    m_name = "Chicken";
    m_sound = "Cluck";

}


Chicken::~Chicken() { // Destructor deletes the instance

    delete this;
    
}

int Chicken::getEggs() const { // This method returns the m_eggs variable

    return(m_eggs);

}


void Chicken::setEggs(int eggs) { // This method sets the m_eggs variable to the parameter passed in

    m_eggs = eggs;

}



