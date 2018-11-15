TreeLab: main.o Executive.o PrecondViolationExcep.o
				g++ -std=c++11 -g -o TreeLab main.o Executive.o PrecondViolationExcep.o
main.o: Executive.h PrecondViolationExcep.h main.cpp
				g++ -std=c++11 -c -g main.cpp
Executive.o: PrecondViolationExcep.h BinaryNode.h BinaryNode.cpp BinaryTreeInterface.h BinaryNodeTree.cpp BinaryNodeTree.h StackInterface.h Stack.h Stack.cpp Node.h Node.cpp Executive.h Executive.cpp
				g++ -std=c++11 -c -g Executive.cpp
PrecondViolationExcep.o: PrecondViolationExcep.h PrecondViolationExcep.cpp
				g++ -std=c++11 -c -g PrecondViolationExcep.cpp
clean:
	rm *.o TreeLab
