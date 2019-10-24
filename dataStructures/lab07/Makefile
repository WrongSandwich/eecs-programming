lab6: main.o Executive.o MinHeap.o MaxHeap.o
	g++ -std=c++11 -g -o lab6 main.o Executive.o MinHeap.o MaxHeap.o
main.o: Executive.h main.cpp
	g++ -std=c++11 -c -g main.cpp
Executive.o: MinHeap.h MaxHeap.h Executive.h Executive.cpp
	g++ -std=c++11 -c -g Executive.cpp
MinHeap.o: MinHeap.h MinHeap.cpp
	g++ -std=c++11 -c -g MinHeap.cpp
MaxHeap.o: MaxHeap.h MaxHeap.cpp
	g++ -std=c++11 -c -g MaxHeap.cpp
clean:
	rm *.o lab6