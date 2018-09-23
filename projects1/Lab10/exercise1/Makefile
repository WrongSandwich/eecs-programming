exercise1: main.o DMV.o DriversLicenseRecord.o
	g++ -std=c++11 -g -Wall main.o DMV.o DriversLicenseRecord.o -o exercise1

main.o: main.cpp DMV.h DriversLicenseRecord.h
	g++ -std=c++11 -g -Wall -c main.cpp

DriversLicenseRecord.o: DriversLicenseRecord.h DriversLicenseRecord.cpp
	g++ -std=c++11 -g -Wall -c DriversLicenseRecord.cpp

DMV.o: DMV.h DMV.cpp
	g++ -std=c++11 -g -Wall -c DMV.cpp

clean:
	rm *.o exercise1
