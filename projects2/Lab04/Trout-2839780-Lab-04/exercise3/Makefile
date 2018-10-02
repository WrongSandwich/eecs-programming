fibo: main.o Fibonacci.o
				g++ -std=c++11 -g -o fibo main.o Fibonacci.o
main.o: Fibonacci.h main.cpp
				g++ -std=c++11 -c -g main.cpp
Fibonacci.o: Fibonacci.h Fibonacci.cpp
				g++ -std=c++11 -c -g Fibonacci.cpp
clean:
	rm *.o fibo
