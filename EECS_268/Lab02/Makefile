Browser: main.o Exec.o WebBrowser.o WebBrowserInterface.o
				g++ -std=c++11 -g -o Browser main.o Exec.o WebBrowser.o WebBrowserInterface.o
main.o: Exec.h main.cpp
				g++ -std=c++11 -c -g main.cpp
Exec.o: WebBrowser.h Exec.h Exec.cpp
				g++ -std=c++11 -c -g Exec.cpp
WebBrowser.o: WebBrowserInterface.h Node.h Node.cpp ListInterface.h ListInterface.cpp LinkedList.h
							LinkedList.cpp WebBrowser.h WebBrowser.cpp
				g++ -std=c++11 -c -g WebBrowser.cpp
WebBrowserInterface.o: WebBrowserInterface.h WebBrowserInterface.cpp
				g++ -std=c++11 -c -g WebBrowserInterface.cpp
clean:
	rm *.o Browser
