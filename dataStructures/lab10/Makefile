lab10: main.o Executive.o BinomialHeap.o BinomialNode.o
	g++ -std=c++11 -g -o lab10 main.o Executive.o BinomialHeap.o BinomialNode.o
main.o: BinomialHeap.h Executive.h main.cpp
	g++ -std=c++11 -c -g main.cpp
Executive.o: BinomialHeap.h Executive.h Executive.cpp
	g++ -std=c++11 -c -g Executive.cpp
BinomialHeap.o: BinomialNode.h BinomialHeap.h BinomialHeap.cpp
	g++ -std=c++11 -c -g BinomialHeap.cpp
BinomialNode.o: BinomialNode.h BinomialNode.cpp
	g++ -std=c++11 -c -g BinomialNode.cpp
clean:
	rm *.o lab10