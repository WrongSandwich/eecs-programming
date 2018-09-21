CPUScheduler: main.o Scheduler.o PrecondViolationExcep.o
				g++ -std=c++11 -g -o CPUScheduler main.o Scheduler.o PrecondViolationExcep.o
main.o: Scheduler.h PrecondViolationExcep.h main.cpp
				g++ -std=c++11 -c -g main.cpp
Scheduler.o: PrecondViolationExcep.h Node.h Node.cpp ListInterface.h LinkedList.h LinkedList.cpp StackInterface.h Stack.h Stack.cpp QProcess.cpp QProcess.h QueueInterface.h Queue.h Queue.cpp Scheduler.o Scheduler.cpp
				g++ -std=c++11 -c -g Scheduler.cpp
PrecondViolationExcep.o: PrecondViolationExcep.h PrecondViolationExcep.cpp
				g++ -std=c++11 -c -g PrecondViolationExcep.cpp
clean:
	rm *.o CPUScheduler
