lab7: main.o Executive.o MinMaxHeap.o
	g++ -std=c++11 -g -o lab7 main.o Executive.o MinMaxHeap.o
main.o: Executive.h main.cpp
	g++ -std=c++11 -c -g main.cpp
Executive.o: MinMaxHeap.h Executive.h Executive.cpp
	g++ -std=c++11 -c -g Executive.cpp
MinMaxHeap.o: MinMaxHeap.h MinMaxHeap.cpp
	g++ -std=c++11 -c -g MinMaxHeap.cpp
clean:
	rm *.o lab7