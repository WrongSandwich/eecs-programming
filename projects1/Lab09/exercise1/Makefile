exercise1: main.o employee.o employeeDriver.o
	g++ -std=c++11 -g -Wall main.o employee.o employeeDriver.o -o exercise1

main.o: main.cpp employee.h employeeDriver.h
	g++ -std=c++11 -g -Wall -c main.cpp

employeeDriver.o: employeeDriver.h employeeDriver.cpp
	g++ -std=c++11 -g -Wall -c employeeDriver.cpp

employee.o: employee.h employee.cpp
	g++ -std=c++11 -g -Wall -c employee.cpp

clean:
	rm *.o exercise1
