Run: main.o Node.o LinkedList.o
	g++ -std=c++11 -g main.o Node.o LinkedList.o -o Run

main.o: main.cpp LinkedList.h
	g++ -std=c++11 -g -c main.cpp

LinkedList.o: LinkedList.h LinkedList.cpp Node.h
	g++ -std=c++11 -g -c LinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp

clean:
	rm *.o
	clean done

