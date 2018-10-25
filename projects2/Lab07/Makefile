Lab07: main.o Executive.o
				g++ -std=c++11 -g -o Lab07 main.o Executive.o
main.o: Executive.h main.cpp
				g++ -std=c++11 -c -g main.cpp
Executive.o: Executive.h Executive.cpp mergesort.cpp bubbleSort.cpp quicksort.cpp selectionSort.cpp insertionSort.cpp
				g++ -std=c++11 -c -g Executive.cpp
clean:
	rm *.o Lab07
