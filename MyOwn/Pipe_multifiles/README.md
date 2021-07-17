# Pipe with C++

This folder contains three files, where I learned how to get outputs from one C++ program and pipe it to another one. It also has a makefile.

I used three files, so the first pipes outputs to the second and this to the third.

From what I understand, with this arrangement, I could get a file that its confiability needs testing, then replace it with file2 and finally implement files 1 and 3. File1 would act like if the user was sending inputs to file2 and file3 would receive file2's outputs and save then at results.txt.

This way it'd be possible to check if file2 (or the program that needs testing) is working as it should.

The makefile deals with compiling the programs and running the executables. On terminal just type 'make' and then 'make run' for it to execute.