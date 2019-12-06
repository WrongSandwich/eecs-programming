lab11: main.o Executive.o DisjointSet.o Node.o Graph.o
	g++ -std=c++11 -g -o lab11 main.o Executive.o DisjointSet.o Node.o Graph.o
main.o: DisjointSet.h Executive.h main.cpp Graph.h
	g++ -std=c++11 -c -g main.cpp
Executive.o: DisjointSet.h Executive.h Executive.cpp Graph.h
	g++ -std=c++11 -c -g Executive.cpp
DisjointSet.o: Node.h DisjointSet.h DisjointSet.cpp
	g++ -std=c++11 -c -g DisjointSet.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -c -g Node.cpp
Graph.o: Graph.h Graph.cpp Edge.h
	g++ -std=c++11 -c -g Graph.cpp
clean:
	rm *.o lab11