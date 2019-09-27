lab4: main.o Executive.o BinaryTree.o
	g++ -std=c++11 -g -o lab4 main.o Executive.o BinaryTree.o
main.o: BinaryTree.h Executive.h main.cpp
	g++ -std=c++11 -c -g main.cpp
Executive.o: BinaryTree.h Executive.h Executive.cpp
	g++ -std=c++11 -c -g Executive.cpp
BinaryTree.o: BinaryNode.h BinaryNode.cpp BinaryTree.h BinaryTree.cpp
	g++ -std=c++11 -c -g BinaryTree.cpp
clean:
	rm *.o lab4