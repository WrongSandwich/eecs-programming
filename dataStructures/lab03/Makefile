lab2: main.o Executive.o HashTable.o
	g++ -std=c++11 -g -o lab2 main.o Executive.o HashTable.o
main.o: HashTable.h Executive.h main.cpp
	g++ -std=c++11 -c -g main.cpp
Executive.o: HashTable.h Executive.h Executive.cpp
	g++ -std=c++11 -c -g Executive.cpp
HashTable.o: Node.h Node.cpp LinkedList.h LinkedList.cpp HashTable.h HashTable.cpp
	g++ -std=c++11 -c -g HashTable.cpp
clean:
	rm *.o lab2