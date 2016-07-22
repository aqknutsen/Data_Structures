/**
*	@file : CyberChicken.cpp
*	@author : Alec Knutsen
*	@date : 2015.03.13
*	@brief: Implementation of the CyberChicken class
*/




#include "CyberChicken.h" // We include the corresponding CyberChickn.h file


CyberChicken::CyberChicken() { // This constructor sets the m_name and m_sound variables of the chicken inherited from FarmAnimal

m_name = "CyberChicken";

m_sound = "Resistance is Futile";

}

CyberChicken::~CyberChicken() { // Destructor deletes the instance
        delete this;
    
}



int CyberChicken::getCyberEggs() const {  // This method returns the m_eggs variable inherited from the Chicken class

    return(m_eggs);

}




void CyberChicken::setCyberEggs(int eggs) { // This method sets the m_eggs variable inherited from the Chicken class to the parameter passed in

    m_eggs = eggs;

}
