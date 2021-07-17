all: file1 file2 file3

file1: file1.o
	g++ file1.o -o file1

file2: file2.o
	g++ file2.o -o file2

file3: file3.o
	g++ file3.o -o file3

file1.o: file1.cpp
	g++ -c file1.cpp 

file2.o: file2.cpp
	g++ -c file2.cpp 

file3.o: file3.cpp
	g++ -c file3.cpp 

run:
	./file1 | ./file2 | ./file3

clean:
	rm *.o file1 file2 file3 result.txt