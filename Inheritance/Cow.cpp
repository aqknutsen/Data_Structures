/**
*	@file : Cow.cpp
*	@author : Alec Knutsen
*	@date : 2015.03.13
*	@brief: Implementation of the Cow class
*/


#include "Cow.h" // We include the corresponding Cow.h file


Cow::Cow() { // This constructor sets the m_name and m_sound variables of the cow inherited from FarmAnimal

    m_name = "Cow";
    m_sound = "Moo";

}

Cow::~Cow() { // Destructor deletes the instance

    delete this;
}



double Cow::getMilkProduced() const { // This method returns the m_milkProduced

    return(m_milkProduced);
}



void Cow::setMilkProduced(double gallons) { // This method sets the m_milkProduced variable

    if(gallons > 0) { // If the parameter is greater than 0, the m_milkProduced variable is set to the parameter


        m_milkProduced = gallons;

    }
    else { // If the parameter passed in is less than or equal to 0, the m_milkProduced variable is set to 0

        m_milkProduced = 0;
    }
}
