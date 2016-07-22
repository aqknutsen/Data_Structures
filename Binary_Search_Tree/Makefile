
Run: main.o ValueNotFoundException.o
	g++ -g -std=c++11 -Wall main.o ValueNotFoundException.o -o Run

main.o: Node.h Node.hpp BSTI.h BinarySearchTree.h BinarySearchTree.hpp main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

ValueNotFoundException.o: ValueNotFoundException.h ValueNotFoundException.cpp
	g++ -std=c++11 -g -c ValueNotFoundException.cpp



clean:
	rm *.o
	clean done
