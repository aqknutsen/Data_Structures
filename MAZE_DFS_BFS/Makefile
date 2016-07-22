
Run: main.o MazeCreationException.o Position.o MazeReader.o MazeWalker.o
	g++ -g -std=c++11 -Wall main.o MazeCreationException.o Position.o MazeReader.o MazeWalker.o -o Run

main.o: MazeReader.h MazeWalker.h main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

MazeWalker.o: Position.h MazeWalker.h MazeWalker.cpp
	g++ -std=c++11 -g -c MazeWalker.cpp

MazeReader.o: MazeCreationException.h MazeReader.h MazeReader.cpp
	g++ -std=c++11 -g -c MazeReader.cpp

Position.o: Position.h Position.cpp
	g++ -std=c++11 -g -c Position.cpp

MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -std=c++11 -g -c MazeCreationException.cpp



clean:
	rm *.o
	clean done
