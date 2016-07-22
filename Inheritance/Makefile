
Run: main.o PreconditionViolationException.o AnimalPen.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o
	g++ -g -std=c++11 -Wall main.o PreconditionViolationException.o AnimalPen.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o -o Run

main.o: Node.h Node.hpp StackInterface.h Stack.h Stack.hpp AnimalPen.h FarmAnimal.h Cow.h Chicken.h CyberChicken.h main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp


CyberChicken.o: Chicken.h CyberChicken.h CyberChicken.cpp
	g++ -std=c++11 -g -c CyberChicken.cpp

Chicken.o: FarmAnimal.h Chicken.h Chicken.cpp
	g++ -std=c++11 -g -c Chicken.cpp

Cow.o: FarmAnimal.h Cow.h Cow.cpp
	g++ -std=c++11 -g -c Cow.cpp

FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -std=c++11 -g -c FarmAnimal.cpp

AnimalPen.o: AnimalPen.h AnimalPen.cpp Stack.h FarmAnimal.h Cow.h Chicken.h CyberChicken.h
	g++ -std=c++11 -g -c AnimalPen.cpp
PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp 
	g++ -std=c++11 -g -c PreconditionViolationException.cpp

clean:
	rm *.o
	clean done


