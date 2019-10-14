lab6: main.o Executive.o MinHeap.o
	g++ -std=c++11 -g -o lab6 main.o Executive.o MinHeap.o
main.o: Executive.h main.cpp
	g++ -std=c++11 -c -g main.cpp
Executive.o: MinHeap.h Executive.h Executive.cpp
	g++ -std=c++11 -c -g Executive.cpp
MinHeap.o: MinHeap.h MinHeap.cpp
	g++ -std=c++11 -c -g MinHeap.cpp
clean:
	rm *.o lab6