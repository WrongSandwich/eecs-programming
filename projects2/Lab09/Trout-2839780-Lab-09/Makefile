SearchTreeLab: main.o Executive.o NotFoundException.o InvalidSetEntryRequest.o Task.o
				g++ -std=c++11 -g -o SearchTreeLab main.o Executive.o NotFoundException.o InvalidSetEntryRequest.o Task.o
main.o: Executive.h main.cpp
				g++ -std=c++11 -c -g main.cpp
Executive.o: Task.h  InvalidSetEntryRequest.h NotFoundException.h Executive.h Executive.cpp BinaryNode.h BinaryNode.cpp BinarySearchTree.h BinarySearchTree.cpp
				g++ -std=c++11 -c -g Executive.cpp
NotFoundException.o: NotFoundException.h NotFoundException.cpp
				g++ -std=c++11 -c -g NotFoundException.cpp
InvalidSetEntryRequest.o: InvalidSetEntryRequest.h InvalidSetEntryRequest.cpp
				g++ -std=c++11 -c -g InvalidSetEntryRequest.cpp
Task.o: Task.h Task.cpp
				g++ -std=c++11 -c -g Task.cpp
clean:
	rm *.o SearchTreeLab
