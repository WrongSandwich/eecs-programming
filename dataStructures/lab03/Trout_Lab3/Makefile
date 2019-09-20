lab3: main.o Executive.o QuadHashTable.o DoubleHashTable.o
	g++ -std=c++11 -g -o lab3 main.o Executive.o QuadHashTable.o DoubleHashTable.o
main.o: DoubleHashTable.h QuadHashTable.h Executive.h main.cpp
	g++ -std=c++11 -c -g main.cpp
Executive.o: Executive.h Executive.cpp QuadHashTable.h DoubleHashTable.h
	g++ -std=c++11 -c -g Executive.cpp
DoubleHashTable.o: DoubleHashTable.h DoubleHashTable.cpp Review.h
	g++ -std=c++11 -c -g DoubleHashTable.cpp
QuadHashTable.o: QuadHashTable.h QuadHashTable.cpp Review.h
	g++ -std=c++11 -c -g QuadHashTable.cpp
clean:
	rm *.o lab3