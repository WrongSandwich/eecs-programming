Lab09: main.o Flood.o MapReader.o
				g++ -std=c++11 -g -o Lab09 main.o Flood.o MapReader.o
main.o: Flood.h MapReader.h main.cpp
				g++ -std=c++11 -c -g main.cpp
Flood.o: Flood.h Flood.cpp
				g++ -std=c++11 -c -g Flood.cpp
MapReader.o: MapReader.h MapReader.cpp
				g++ -std=c++11 -c -g MapReader.cpp
clean:
	rm *.o Lab09
