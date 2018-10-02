harderChecker: main.o Checker.o
				g++ -std=c++11 -g -o harderChecker main.o Checker.o
main.o: Checker.h main.cpp
				g++ -std=c++11 -c -g main.cpp
Checker.o: Checker.h Checker.cpp
				g++ -std=c++11 -c -g Checker.cpp
clean:
	rm *.o harderChecker
