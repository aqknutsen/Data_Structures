Run: main.o ValueNotFoundException.o
	g++ -g -std=c++11 -Wall main.o ValueNotFoundException.o -o Run

main.o: main.cpp BinarySearchTree.h BinarySearchTree.hpp Node.h Node.hpp ValueNotFoundException.h BSTI.h
	g++ -g -std=c++11 -Wall -c main.cpp

ValueNotFoundException.o: ValueNotFoundException.h ValueNotFoundException.cpp
	g++ -g -std=c++11 -Wall -c ValueNotFoundException.cpp

clean:
	rm *.o
	clean done
