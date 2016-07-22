/**
*	@file :Position.h
*	@author : Alec Knutsen
*	@date : 2015.04.18
*	@brief: This class initializes m_row and m_col at construction time. It also has get methods for both variables.
*/



#ifndef POSITION_H
#define POSITION_H

class Position {

public:


    /**
    * @pre - None
    * @post - This constructor initializes the m_row and m_col to the two parameters respectively
    * @param - int row - Represents the rows of the maze, int col - Represents the columns of the maze
    */
    Position(int row, int col);


    /**
    * @pre - None
    * @post - Returns m_row
    * @param - None
    * @return - int - Returns m_row
    */
    int getRow() const;


    /**
    * @pre - None
    * @post - Returns m_col
    * @param - None
    * @return - int - Returns m_col
    */
    int getCol() const;

private:

    int m_row; // Represents the row position

    int m_col; // Represents the column position





};

#endif
