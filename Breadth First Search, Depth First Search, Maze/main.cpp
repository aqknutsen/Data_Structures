/**
*	@file :main.cpp
*	@author : Alec Knutsen
*	@date : 2015.04.18
*	@brief: Main takes in a file and search option from command line, reads in the file, and attempts to traverse the message. Error messages are printed if errors are encountered.
*/

#include <iostream> // We include iostream to print data

#include "MazeReader.h" // We include MazeReader to read in the maze

#include "MazeWalker.h" // We include MazeWalker to traverse the maze

int main(int argc, char** argv) {


  if(argc < 3 || argc > 3) { // If we have more or less than 3 command line arguments, we print an error message

    std::cout<< "Enter only three arguments!"<<std::endl;

  }

  else { // If we have three command line arguments we proceed


    try { // We try to read the maze and traverse it. If the search option is invalid we print an error message.

        std::string filename = argv[1]; // We get the filename at index 1.

        MazeReader test = MazeReader(filename); // We create a new MazeReader object and pass filename as a parameter.

        std::string option = argv[2]; // We read in the search option.

        if(option=="-dfs") { // If the search is depth first, we pass true to the MazeWalker constructor, and use the walkMaze method to traverse the maze.

          MazeWalker test1 = MazeWalker(test.getMaze(),test.getStartRow(),test.getStartCol(),test.getRows(),test.getCols(), true);

          test1.walkMaze();

        } // End of inner if

        else if(option=="-bfs") { // If the search is breadth first, we pass false to the MazeWalker constructor, and use the walkMaze method to traverse the maze.


           MazeWalker test1 = MazeWalker(test.getMaze(),test.getStartRow(),test.getStartCol(),test.getRows(),test.getCols(), false);

           test1.walkMaze();

        } // End of inner else if

        else { // If the search option is not valid, we print an error

            std::cout<<"You did not enter a valid search command!"<<std::endl;

        } // End of inner else

    } // End of try block

    catch(MazeCreationException& e) { // If their was an error taking in the file, we catch the exception and print the error message

        std::cout<<e.what()<<std::endl;

    } // End of catch block


  } // End of outer else block

  return(0); // Dummy return

} // End of main
