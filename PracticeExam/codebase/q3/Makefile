q3: main.o Test3.o
	g++ -g -std=c++11 main.o Test3.o -o q3

main.o: main.cpp Queue.h 
	g++ -g -std=c++11 -c main.cpp
	
Test3.o: Test3.h Test3.cpp Queue.h Queue.hpp
		g++ -g -std=c++11 -c Test3.cpp
clean: 
	rm *.o q3
