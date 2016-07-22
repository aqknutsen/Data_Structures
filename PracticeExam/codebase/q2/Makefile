q2: main.o Test.o
	g++ -g -Wall -std=c++11 Test.o main.o -o q2

main.o: StackOfAnything.h main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp

Test.o: Test.h Test.cpp
	g++ -g -Wall -std=c++11 -c Test.cpp
clean: 
	rm *.o q2
