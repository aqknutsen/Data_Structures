
Run: main.o PreconditionViolationException.o
	g++ -g -std=c++11 -Wall main.o PreconditionViolationException.o -o Run

main.o: StackInterface.h main.cpp Stack.h Stack.hpp Node.h Node.hpp
	g++ -g -std=c++11 -Wall -c main.cpp


PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -std=c++11 -g -c PreconditionViolationException.cpp

clean:
	rm *.o
	clean done


