Browser: main.o Exec.o WebBrowser.o
				g++ -std=c++11 -g -o Browser main.o Exec.o WebBrowser.o
main.o: Exec.h main.cpp
				g++ -std=c++11 -c -g main.cpp
Exec.o: WebBrowser.h Exec.h Exec.cpp
				g++ -std=c++11 -c -g Exec.cpp
WebBrowser.o: WebBrowserInterface.h Node.h Node.cpp ListInterface.h LinkedList.h LinkedList.cpp WebBrowser.h WebBrowser.cpp
				g++ -std=c++11 -c -g WebBrowser.cpp
clean:
	rm *.o Browser
