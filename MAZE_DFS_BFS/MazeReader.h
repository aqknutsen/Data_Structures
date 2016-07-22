/**
*	@file :MazeReader.h
*	@author : Alec Knutsen
*	@date : 2015.04.18
*	@brief: This class contains a constructor that initializes all member variables, and a destructor that deallocates the array containing the maze information.
*   @brief: We also have get methods for the number of rows and columns, and the starting position.
*/


#ifndef MAZEREADER_H
#define MAZEREADER_H


#include <fstream> // Include the fstream library to take in files

#include "MazeCreationException.h" // Include Mazecreationexception to throw errors


class MazeReader {

public:


/**
*@pre - We assume the parameter passed in is a valid string. We assume the MazeCreationException class functions properly. We assume the fstream library functions properly
*@post - A MazeReader is created. A 2D char array is allocated with the maze information.
*@param - std::string file - Filename containing the maze
*@throws MazeCreationExecption if any of the following is true:
    *-The file could not be opened
    *-The rows or cols are zero or less
    *-The start position listed is outside the ranges described by the rows and columns
    *-You do NOT have to check each character for validity, only the rows, cols, and starting position.
*/
MazeReader(std::string file) throw (MazeCreationException);



/**
 * @pre - None
 * @post - The maze is deallocated using a for loop.
 * @param - None
*/
~MazeReader();



/**
* @pre - The file was formatted and read in correctly
* @post - Returns the m_maze variable
* @param - none
* @return - char** Returns pointer to the maze
*/
char** getMaze() const;



/**
* @pre - The file was formatted and read in correctly
* @post - Returns the m_cols variable
* @param - none
* @return - int - Returns m_cols
*/
int getCols() const;



/**
* @pre - The file was formatted and read in correctly
* @post - Returns the m_rows variable
* @param - none
* @return - int - Returns m_rows
*/
int getRows() const;



/**
* @pre - The file was formatted and read in correctly
* @post - Returns the startCol variable
* @param - none
* @return - int - Returns startCol
*/
int getStartCol() const;



/**
* @pre - The file was formatted and read in correctly
* @post - Returns the startRow variable
* @param - none
* @return - int - Returns startRow
*/
int getStartRow() const;



protected:


/**
* NOTE: I did not implement this method because creating std::ifstream m_in as a class pointer variable and using it in this method was giving me errors. I used the constructor to read the maze.
* @pre - The file was formatted and read in correctly
* @post - None
* @param - none
* @return - none
*/
void readMaze()	throw (MazeCreationException);



private:

    char** m_maze; // Stores the maze information from the file

    int m_rows; // Stores the number of rows of the maze

    int m_cols; // Stores the number of columns in the maze

    int startRow; // Stores the starting row number

    int startCol; // Stores the starting column number

    std::string m_filename; // Stores the input filename


};

#endif
