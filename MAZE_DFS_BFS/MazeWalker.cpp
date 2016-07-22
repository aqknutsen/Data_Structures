/**
*	@file :MazeWalker.cpp
*	@author : Alec Knutsen
*	@date : 2015.04.18
*	@brief: Implementation of the MazeWalker.h file (see header file for method descriptions)
*/

#include "MazeWalker.h" // We include the corresponding MazeWalker.h file

#include <iostream> // We include iostream to print data



MazeWalker::MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs) {

    m_maze = mazePtr; // We set the m_maze char** pointer to the parameter passed in representing the maze

    Position start(startRow,startCol); // We create a temporary starting position

    m_startPos = start; // We set the class variable m_startPos to the temporary variable holding the starting position

    m_curPos = start; // We set the current position to the starting position initially

    m_rows = rows; // We store the number of rows of the maze in m_rows

    m_cols = cols; // We store the number of columns of the maze in m_rows

    m_isDFS = dfs; // We store bool dfs in m_isDFS(true for depth first search, false for breadth first search)

    m_visited = new bool*[m_rows]; // We initializes the m_visited rows that are pointers

        for(int i = 0; i < rows; i++) { // We initializes all the pointers of m_visited to point at bool arrays

            m_visited[i] = new bool[cols];

        }

    /**
    * A double for loop initializes the m_visited array with true and false representing the visited positions in the maze
    **/

    for (int i =0 ; i < rows; i++) {

        for (int j=0; j < cols; j++) {

            if(m_startPos.getRow() == i && m_startPos.getCol() ==j) { // We set the starting position to 1, already visited

                m_visited[i][j] = true;

            }

            else { // We set all other positions besides the starting position to 0, not visited

                m_visited[i][j] = false;

            }

        } // End of inner for loop

    } // End of outer for loop

}


void MazeWalker::walkMaze() {

    if(m_isDFS) { // If we m_isDFS is true, we use a stack for a depth first search

        m_moveStack.push(m_startPos); // We initially push the starting position on the stack

        printMaze(); // We print the initial info

        while(!(m_moveStack.empty())) { // While the stack is not empty, this loop runs

            m_moveStack.pop(); // We first pop of old values at the top of the stack that have been read

            storeValidMoves(); // We get all the valid moves which are pushed onto the stack

            if(m_moveStack.empty()) { // If the stack is out of moves, we print a message and delete the m_visited array. We also break the loop since no exit exists


                std::cout<<"No way out!"<<std::endl;


                for(int i = 0; i < m_rows; i++) {

                    delete[] m_visited[i];

                } // End of for loop

                delete[] m_visited;

                break; // Break the loop

            } // End of if block

            else { // If the stack is not empty, we move the m_currPos to the top of the stack and print the maze information for that position

                move(m_moveStack.top());

                printMaze();

            }

            if(isGoalReached()) { // If after moving the curr Position the exit is found, we print a message, delete the m_visited array, and break the loop

                std::cout<<"Exit found!";


                for(int i = 0; i < m_rows; i++) {

                    delete[] m_visited[i];

                } // End of for loop

                delete[] m_visited;

                break; // Break the while loop

            } // End of if block

        } // End of inner else block

    } // End of outer if block

    else { // If m_DFS is false, we use a queue for a breadth first search


         m_moveQueue.push(m_startPos); // We initially push the starting position on the queue

         printMaze(); // We print the initial information

        while(!(m_moveQueue.empty())) { // While the queue is not empty, we continue the while loop

            m_moveQueue.pop(); // We first pop of the value at the top of the queue (last value put in)

            storeValidMoves(); // We get all other valid moves added to the queue

            if(m_moveQueue.empty()) { // If the queue is empty, we print a message, delete the m_visited array, and break the loop since no way out exists

                std::cout<<"No way out!"<<std::endl;

                 for(int i = 0; i < m_rows; i++) {

                    delete[] m_visited[i];

                } // End of for loop

                delete[] m_visited;

                break; // We break the while loop

            } // End of if block

            else { // If the queue is not empty, we move the m_currPos to the oldest element in the queue using the move method. Also, we print the maze information

                move(m_moveQueue.front());

                printMaze();

            }

            if(isGoalReached()) { // If after moving the position, we have found the exit, we print a message, delete the m_visited array, and break the while loop

                std::cout<<"Exit found!";

                for(int i = 0; i < m_rows; i++) {

                    delete[] m_visited[i];

                } // End of for loop

                delete[] m_visited;

                break; // We break the loop


            } // End of if block

        } // End of while loop

    } // End of outer else block


}



void MazeWalker::storeValidMoves() {

    if(m_isDFS) { // If m_isDFS we adjust our stack, depth first search

        /**
        * If the new position is a passage  or an exit E, and it has not been visited (m_visited = false), we push the new position onto the stack
        */
        if(m_curPos.getRow()-1 >= 0) { // We first check that moving to the new position. If it is, we proceed

            if ((m_maze[m_curPos.getRow()-1][m_curPos.getCol()] =='P' || m_maze[m_curPos.getRow()-1][m_curPos.getCol()] =='E') && (m_visited[m_curPos.getRow()-1][m_curPos.getCol()] == false)) {

                m_moveStack.push(Position(m_curPos.getRow()-1,m_curPos.getCol()));

            } // End of inner if

        } // End of outer if

        /**
        * If the new position is a passage  or an exit E, and it has not been visited (m_visited = false), we push the new position onto the stack
        */
        if(m_curPos.getRow()+1 < m_rows) { // We first check that moving to the new position. If it is, we proceed

            if ((m_maze[m_curPos.getRow()+1][m_curPos.getCol()] =='P' || m_maze[m_curPos.getRow()+1][m_curPos.getCol()] =='E') && (m_visited[m_curPos.getRow()+1][m_curPos.getCol()] == false)) {

               m_moveStack.push(Position(m_curPos.getRow()+1,m_curPos.getCol()));

            } // End of inner if

        } // End of outer if

        if(m_curPos.getCol()-1 >= 0) { // We first check that moving to the new position. If it is, we proceed


            /**
            * If the new position is a passage  or an exit E, and it has not been visited (m_visited = false), we push the new position onto the stack
            */
            if ((m_maze[m_curPos.getRow()][m_curPos.getCol()-1] =='P' || m_maze[m_curPos.getRow()][m_curPos.getCol()-1] =='E') && (m_visited[m_curPos.getRow()][m_curPos.getCol()-1] == false)) {

                m_moveStack.push(Position(m_curPos.getRow(),m_curPos.getCol()-1));

            } // End of inner if s

        } //  End of outer if

        if(m_curPos.getCol()+1 < m_cols) { // We first check that moving to the new position. If it is, we proceed

            /**
            * If the new position is a passage  or an exit E, and it has not been visited (m_visited = false), we push the new position onto the stack
            */
            if ((m_maze[m_curPos.getRow()][m_curPos.getCol()+1] =='P' || m_maze[m_curPos.getRow()][m_curPos.getCol()+1] =='E') && (m_visited[m_curPos.getRow()][m_curPos.getCol()+1] == false)) {

                m_moveStack.push(Position(m_curPos.getRow(),m_curPos.getCol()+1));

            } // End of inner if

        } // End of outer if

    } // End of outer if

    else { // If m_DFS is false, we use our queue for a breadth first search


        if(m_curPos.getRow()-1 >= 0) { // We first check that moving to the new position. If it is, we proceed

            /**
            * If the new position is a passage  or an exit E, and it has not been visited (m_visited = false), we push the new position onto the queue
            */
            if ((m_maze[m_curPos.getRow()-1][m_curPos.getCol()] =='P' || m_maze[m_curPos.getRow()-1][m_curPos.getCol()] =='E') && (m_visited[m_curPos.getRow()-1][m_curPos.getCol()] == false)) {


                m_moveQueue.push(Position(m_curPos.getRow()-1,m_curPos.getCol()));

            } // End of inner if

        } // End of outer if

        /**
        * If the new position is a passage  or an exit E, and it has not been visited (m_visited = false), we push the new position onto the queue
        */
        if(m_curPos.getRow()+1 < m_rows) { // We first check that moving to the new position. If it is, we proceed

            if ((m_maze[m_curPos.getRow()+1][m_curPos.getCol()] =='P' || m_maze[m_curPos.getRow()+1][m_curPos.getCol()] =='E') && (m_visited[m_curPos.getRow()+1][m_curPos.getCol()] == false)) {

               m_moveQueue.push(Position(m_curPos.getRow()+1,m_curPos.getCol()));

            } // End of inner if

        } // End of outer if

        /**
        * If the new position is a passage  or an exit E, and it has not been visited (m_visited = false), we push the new position onto the queue
        */
        if(m_curPos.getCol()-1 >= 0) { // We first check that moving to the new position. If it is, we proceed

            if ((m_maze[m_curPos.getRow()][m_curPos.getCol()-1] =='P' || m_maze[m_curPos.getRow()][m_curPos.getCol()-1] =='E') && (m_visited[m_curPos.getRow()][m_curPos.getCol()-1] == false)) {


                m_moveQueue.push(Position(m_curPos.getRow(),m_curPos.getCol()-1));

            } // End of inner if

        } // End of outer if


        /**
        * If the new position is a passage  or an exit E, and it has not been visited (m_visited = false), we push the new position onto the queue
        */
        if(m_curPos.getCol()+1 < m_cols) { // We first check that moving to the new position. If it is, we proceed

            if ((m_maze[m_curPos.getRow()][m_curPos.getCol()+1] =='P' || m_maze[m_curPos.getRow()][m_curPos.getCol()+1] =='E') && (m_visited[m_curPos.getRow()][m_curPos.getCol()+1] == false)) {


                m_moveQueue.push(Position(m_curPos.getRow(),m_curPos.getCol()+1));

            } // End of inner if

       } // End of outer if

    } // End of outer else


}


void MazeWalker::move(Position& p) {

    m_curPos = p; // We set the current position to the position passed in

    m_visited[m_curPos.getRow()][m_curPos.getCol()] = true; // We set the corresponding position in the m_visited array to true (visited), so that the position will not be visited again

}


bool MazeWalker::isGoalReached() const {

    if(m_maze[m_curPos.getRow()][m_curPos.getCol()]== 'E') { // If the current position in the m_maze array is an E exit, we return true

        return(true);

    }

    else { // If we have not reached the exit, we return false

        return(false);

    }


}


void MazeWalker::printMaze() {


    /**
    * A double for loop is used to print the m_visited array, showing the visited positions
    */
    for(int i =0; i < m_rows; i++) {

        for(int j=0; j < m_cols; j++) {

            std::cout<<m_visited[i][j];

        } // End of inner for loop

        std::cout<<""<<std::endl;

    } // End of outer for loop

    std::cout<<"Visiting Position: "<< m_curPos.getRow() << "," << m_curPos.getCol() << ":"<<std::endl; // We print the current position
    std::cout<<"----------------------------"<<std::endl;

}
