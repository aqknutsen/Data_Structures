/**
*	@file :MazeWalker.h
*	@author : Alec Knutsen
*	@date : 2015.04.18
*	@brief: This class contains a constructor that initializes all member variables. The walkMaze traverses a maze and either finds and end r no end. The storeValidMoves, move, printMaze, and isGoalReached methods are heleper methods
*/


#ifndef MAZEWALKER_H
#define MAZEWALKER_H

#include <stack> // We include the stack library since will be using a stack for depth first search

#include <queue> // We include the queue library since we will be using a queue for breadth first search

#include <iostream> // We include iostream to print data

#include "Position.h" // We include Position.h since we will use Position objects to represents a position in the maze


class MazeWalker {

public:


/**
* @pre - We assume the mazePtr is a valid char** array. We assume all ints and bools are valid.
* @post - Sets the m_maze variable to mazePtr. All the row and column variables as well as the bool m_dfs. Finally, the 2D m_visited array is initialized and given values
* @param - char** mazePtr - Represents maze to be read in by MazeReader, int startRow - Starting position in the maze, int startCol - Starting position in the maze
* @param - int rows - Number of rows in the maze, int cols - Number of columns in the maze, bool dfs - True if the user wants depth first search, false otherwis
*/
MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs);



/**
* @pre - We assume the methods of the stack and queue library work properly. We assume m_visited and m_maze have been initialized. We assume all other methods in this class function properly.
* @post - This method uses the methods of stack and queue as well as the storeValidMoves, printMaze, move, and isGoalReached methods to walk through a maze.
* @post - If no way out is found, we print a message saying so. If we find out way out, we print a message saying so. We use a stack for (dfs) and a queue for (bfs). The m_visited array is deleted after the method is done.
* @param - None
* @return - None
*/
void walkMaze();


/**
* @pre - We assume m_visited has been initialized and m_curPos has been initialized.
* @post - Helper method. Uses a double for loop to print the m_visited array. Also prints the current position.
* @param - None
* @return - None
*/
void printMaze();



protected:


/**
* @pre - We assume all member variables have been initialized. We assume the stack and queue libraries function properly
* @post - This methods pushes valid moves onto our class stack (if m_dfs is true) or our class queue (if m_bfs) is false. First, it checks if the next move is in the boundaries.
* @post - Then, it checks if the move (either one left, one right, one up, or one down) is valid (if it has not been visited previously and if the maze character is P or E). If it is valid, the Position is pushed onto the stack or queue
* @param - None
* @return - None
*/
void storeValidMoves();



/**
* @pre - We assume Position is a valid position
* @post - Sets m_curPos to the parameter passed in. Also changes the corresponding position in the m_visited array to true (1), so that the position will not be visited again.
* @param - Position& p - Position to be visited
* @return - None
*/
void move(Position& p);


/**
* @pre - We m_maze has been initialized.
* @post - Returns true if the end has been reached the current position in the m_maze error is the character E. Returns false otherwise.
* @param - bool - Returns true if the end has been reached the current position in the m_maze error is the character E. Returns false otherwise.
* @return - None
*/
bool isGoalReached() const;




bool m_isDFS; // (True if a depth first search is used to be used. False for breadth first

char** m_maze; // Will hold the characters representing the maze

bool** m_visited; // Will store 0's (false - not visited) and 1's (true - visited), so that the position in the m_maze array will not be visited again.

int m_rows, m_cols; // Represents the number of rows and columns in the maze


/*
* Represents the current position  and starting position in the maze. I initialized the variables here because I was getting an error otherwise. The variables will be again reset in the constructor.
*/
Position m_curPos = Position(0,0);

Position m_startPos = Position(0,0);

std::stack<Position> m_moveStack; // Stack used for depth first search

std::queue<Position> m_moveQueue; // Queue used for breadth first search








};

#endif // MAZEWALKER_H
