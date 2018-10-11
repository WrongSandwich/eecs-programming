Lab06: main.o Grammar.o Executive.o
				g++ -std=c++11 -g -o Lab09 main.o Grammar.o Executive.o
main.o: Grammar.h Executive.h main.cpp
				g++ -std=c++11 -c -g main.cpp
Grammar.o: Grammar.h Grammar.cpp
				g++ -std=c++11 -c -g Grammar.cpp
Executive.o: Executive.h Executive.cpp
				g++ -std=c++11 -c -g Executive.cpp
clean:
	rm *.o Lab06
