lab4: main.o Executive.o BinarySearchTree.o
	g++ -std=c++11 -g -o lab4 main.o Executive.o BinarySearchTree.o
main.o: BinarySearchTree.h Executive.h main.cpp
	g++ -std=c++11 -c -g main.cpp
Executive.o: BinarySearchTree.h Executive.h Executive.cpp
	g++ -std=c++11 -c -g Executive.cpp
BinarySearchTree.o: BinaryNode.h BinaryNode.cpp BinarySearchTree.h BinarySearchTree.cpp
	g++ -std=c++11 -c -g BinarySearchTree.cpp
clean:
	rm *.o lab4