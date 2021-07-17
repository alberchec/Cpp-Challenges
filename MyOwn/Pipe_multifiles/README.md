# Pipe multifiles and C++

This folder contains three program files, where I learned how to get outputs from one C++ program and pipe it to another one. It has also a makefile, to make compiling and running easier, and a text file named input.

The first C++ file pipes outputs to the second and this to the third.

From what I understand, with this arrangement, I could get a file that its confiability needs testing, then replace file2 with it and at last implement inputs required by file2 into input.txt. File1 would act like if the user was sending inputs to file2 and file3 would receive file2's outputs and save then at results.txt.

This way it'd be possible to check if file2 (or the program that needs testing) is working as it should.

The makefile deals with compiling the programs and running the executables. On terminal just type 'make' and then 'make run' for it to execute.