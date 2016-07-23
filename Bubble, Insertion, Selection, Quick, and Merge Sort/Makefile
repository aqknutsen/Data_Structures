
Run: main.o NumberFileDriver.o NumberFileGenerator.o SortDriver.o
	g++ -g -std=c++11 -Wall main.o NumberFileDriver.o NumberFileGenerator.o SortDriver.o -o Run

main.o: Sorts.h Sorts.hpp main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

SortDriver.o: SortDriver.h SortDriver.cpp
	g++ -std=c++11 -g -c SortDriver.cpp

NumberFileGenerator.o: NumberFileGenerator.h NumberFileGenerator.cpp
	g++ -std=c++11 -g -c NumberFileGenerator.cpp

NumberFileDriver.o: NumberFileDriver.h NumberFileDriver.cpp
	g++ -std=c++11 -g -c NumberFileDriver.cpp

clean:
	rm *.o
	clean done
