/**
*	@file :Position.cpp
*	@author : Alec Knutsen
*	@date : 2015.04.18
*	@brief: Implementation of the Position.h file (see header file for method descriptions
*/

#include "Position.h" // We include the corresponding Position.h file




Position::Position(int row, int col) {

    m_row = row; // We set m_row to the parameter passed in col

    m_col = col; // We set m_col to the parameter passed in col

}


int Position::getRow() const {


    return(m_row); // We return m_row

}


int Position::getCol() const {

    return(m_col); // We return m_col

}
