calendar.out : calendar.o main.o
	g++ calendar.o main.o -std=c++11

calendar.o : calendar.cpp
	g++ -c calendar.cpp -std=c++11

main.o : main.cpp
	g++ -c main.cpp -std=c++11

clean:
	rm calendar.out calendar.o main.o