Lab01: main.o Directory.o Course.o
				g++ -std=c++11 -g -o main main.o Directory.o Course.o
main.o: Directory.h Course.h main.cpp
				g++ -std=c++11 -c -g main.cpp
Directory.o: Course.h Directory.h Directory.cpp
				g++ -std=c++11 -c -g Directory.cpp
Course.o: Course.h Course.cpp
				g++ -std=c++11 -c -g Course.cpp
clean:
	rm *.o main
