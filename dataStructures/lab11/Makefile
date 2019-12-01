lab11: main.o Executive.o DisjointSet.o Node.o
	g++ -std=c++11 -g -o lab11 main.o Executive.o DisjointSet.o Node.o
main.o: DisjointSet.h Executive.h main.cpp
	g++ -std=c++11 -c -g main.cpp
Executive.o: DisjointSet.h Executive.h Executive.cpp
	g++ -std=c++11 -c -g Executive.cpp
DisjointSet.o: Node.h DisjointSet.h DisjointSet.cpp
	g++ -std=c++11 -c -g DisjointSet.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -c -g Node.cpp
clean:
	rm *.o lab11