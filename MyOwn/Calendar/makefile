calendar.out : source/date.o source/main.o
	g++ source/date.o source/main.o -o calendar.out -std=c++11

source/date.o : source/date.cpp
	g++ -c source/date.cpp -o source/date.o -std=c++11

source/main.o : source/main.cpp
	g++ -c source/main.cpp -o source/main.o -std=c++11

clean:
	rm calendar.out source/date.o source/main.o