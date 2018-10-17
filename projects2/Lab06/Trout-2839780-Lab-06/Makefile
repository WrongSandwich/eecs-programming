Lab06: main.o Grammar.o Executive.o ProductionRule.o
				g++ -std=c++11 -g -o Lab06 main.o Grammar.o Executive.o ProductionRule.o
main.o: Executive.h main.cpp
				g++ -std=c++11 -c -g main.cpp
Executive.o: Executive.h Executive.cpp Grammar.h
				g++ -std=c++11 -c -g Executive.cpp
Grammar.o: Grammar.h Grammar.cpp ProductionRule.h
				g++ -std=c++11 -c -g Grammar.cpp
ProductionRule.o: ProductionRule.h ProductionRule.cpp
				g++ -std=c++11 -c -g ProductionRule.cpp
clean:
	rm *.o Lab06
