dll: main.o Executive.o DoublyLinkedList.o
	g++ -std=c++11 -g -o dll main.o Executive.o DoublyLinkedList.o
main.o: DoublyLinkedList.h Executive.h main.cpp
	g++ -std=c++11 -c -g main.cpp
Executive.o: DoublyLinkedList.h Executive.h Executive.cpp
	g++ -std=c++11 -c -g Executive.cpp
DoublyLinkedList.o: Node.h Node.cpp DoublyLinkedList.h DoublyLinkedList.cpp
	g++ -std=c++11 -c -g DoublyLinkedList.cpp
clean:
	rm *.o dll