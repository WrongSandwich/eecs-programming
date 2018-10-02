perm: main.o Permuter.o
				g++ -std=c++11 -g -o perm main.o Permuter.o
main.o: Permuter.h main.cpp
				g++ -std=c++11 -c -g main.cpp
Permuter.o: Permuter.h Permuter.cpp
				g++ -std=c++11 -c -g Permuter.cpp
clean:
	rm *.o perm
