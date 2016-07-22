/**
*	@file : FarmAnimal.cpp
*	@author : Alec Knutsen
*	@date : 2015.03.13
*	@brief: Implementation of the FarmAnimal class
*/


#include "FarmAnimal.h" // We include the corresponding FarmAnimal.h file


FarmAnimal::FarmAnimal() { // At construction time we the set the animals m_name and m_sound to unset
    m_name = "unset";
    m_sound = "unset";
}



std::string FarmAnimal::getName() const { // This get method returns the name of the FarmAnimal

    return(m_name);
}



void FarmAnimal::setName(std::string name) { // This method sets the name of the FarmAnimal to the parameter passed in

    m_name = name;

}



std::string FarmAnimal::getSound() const { // This method gets the sound of the FarmAnimal

    return(m_sound);
}



void FarmAnimal::setSound(std::string sound) { // This method sets the sound of the FarmAnimal to the parameter passed in


    m_sound = sound;

}
