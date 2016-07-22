
Run: main.o
	g++ -g -std=c++11 -Wall main.o -o Run

main.o: HeapInterface.h ArrayMinHeap.h ArrayMinHeap.hpp main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

clean:
	rm *.o
	clean done
