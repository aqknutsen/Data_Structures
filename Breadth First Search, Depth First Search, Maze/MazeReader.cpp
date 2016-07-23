/**
*	@file :MazeReader.h
*	@author : Alec Knutsen
*	@date : 2015.04.18
*	@brief: Implementation of the MazeReader.h file (see header file for method descriptions)
*/

#include "MazeReader.h" // We include the corresponding MazeReader.h file



MazeReader::MazeReader(std::string file) throw (MazeCreationException) {

    std::ifstream m_in(file); // We create an input stream and pass the file parameter

    if (m_in.good()) { // If the file is readable, we proceed

        m_in >> m_rows; // We first store the rows


        m_in >> m_cols; // We next store the columns

        if (m_rows <= 0 || m_cols < 0) { // If the rows or columns are less than 0, we throw an error

            throw(MazeCreationException("Both the rows and columns for the maze size must be greater than 0!"));

        } // End of inner if

        else { // If the rows and columns are valid, we proceed

            m_maze = new char*[m_rows]; // We initialize the m_maze array to be an array of char pointers

            for(int i = 0; i < m_rows; i++) { // We use a for loop to initialize each char pointer to point to a char array

                m_maze[i] = new char[m_cols];

            } // End for loop

            m_in >>startRow; // We get the startRow info

            m_in >>startCol; // We get the starCol info

            if ((startRow < 0 || startRow > m_rows-1) || (startCol < 0 || startCol > m_cols-1)) { // If the startRow or starCol is not in valid range, we throw an exception

                for(int i = 0; i < m_rows; i++) { // This for loop deletes each array that is pointed at by each m_maze row index

                    delete[] m_maze[i];

                }

                delete[] m_maze; // This deletes the array of char pointers that pointed to the char arrays

                throw(MazeCreationException("Invalid starting position!"));

            } // End if

            else { // If the startRow and startCol are valid, we proceed


                /**
                * A double for loop initializes all indices of the m_maze array with the maze from the input file
                */

                for(int i=0; i < m_rows; i++) {

                    for(int j=0; j<m_cols; j++) {


                        m_in >> m_maze[i][j];


                    } // End inner for loop

                } // End outer for loop


            } // End else

        } // End else

        m_in.close(); // We close the file

    } // End of outer if

    else { // If the file is not found, we throw an exception

        throw(MazeCreationException("File not Found!"));

    }


}



MazeReader::~MazeReader() {

    for(int i = 0; i < m_rows; i++) { // This for loop deletes each array that is pointed at by each m_maze row index

        delete[] m_maze[i];

    }

    delete[] m_maze; // This deletes the array of char pointers that pointed to the char arrays

}




char** MazeReader::getMaze() const {


    return(m_maze); // Return the m_maze variable

}


int MazeReader::getCols() const {

    return(m_cols); // Return the m_cols variable

}



int MazeReader::getRows() const {

    return(m_rows); // Return the m_rows variable

}




int MazeReader::getStartCol() const {

    return(startCol); // Return the startCol variable

}



int MazeReader::getStartRow() const {

    return(startRow); // Return the start row variable

}



/**
*Not implemented see header file
*/
void MazeReader::readMaze()	throw (MazeCreationException) {



}
