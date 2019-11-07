lab8: main.o Executive.o LeftistHeap.o
	g++ -std=c++11 -g -o lab8 main.o Executive.o LeftistHeap.o
main.o: LeftistHeap.h Executive.h main.cpp
	g++ -std=c++11 -c -g main.cpp
Executive.o: LeftistHeap.h Executive.h Executive.cpp
	g++ -std=c++11 -c -g Executive.cpp
LeftistHeap.o: BinaryNode.h BinaryNode.cpp LeftistHeap.h LeftistHeap.cpp
	g++ -std=c++11 -c -g LeftistHeap.cpp
clean:
	rm *.o lab8