lab9: main.o Executive.o SkewHeap.o
	g++ -std=c++11 -g -o lab9 main.o Executive.o SkewHeap.o
main.o: SkewHeap.h Executive.h main.cpp
	g++ -std=c++11 -c -g main.cpp
Executive.o: SkewHeap.h Executive.h Executive.cpp
	g++ -std=c++11 -c -g Executive.cpp
SkewHeap.o: BinaryNode.h BinaryNode.cpp SkewHeap.h SkewHeap.cpp
	g++ -std=c++11 -c -g SkewHeap.cpp
clean:
	rm *.o lab9