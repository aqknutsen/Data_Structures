q1: main.o Test.o
	g++ -g -std=c++11 main.o Test.o -o q1

main.o: main.cpp DoubleLinkedList.h DoubleLinkedList.hpp Node.h Node.hpp Test.h
	g++ -g -std=c++11 -c main.cpp

Test.o:Test.h Test.cpp
	g++ -g -std=c++11 -c Test.cpp

clean:
	rm *.o q1
