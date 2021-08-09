calendar.out : source/calendar.o source/main.o
	g++ source/calendar.o source/main.o -o calendar.out -std=c++11

source/calendar.o : source/calendar.cpp
	g++ -c source/calendar.cpp -o source/calendar.o -std=c++11

source/main.o : source/main.cpp
	g++ -c source/main.cpp -o source/main.o -std=c++11

clean:
	rm calendar.out source/calendar.o source/main.o