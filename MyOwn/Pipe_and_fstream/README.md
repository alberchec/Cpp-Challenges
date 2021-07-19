# Pipe and c++ fstream

This folder contains two c++ programs. File1 generates outputs that can be piped to file2.

File2 requires one argument, that is used to set the name of a txt file where file2 writes to.

After compiling both programs, this can be done with the provided makefile, you should enter in the terminal the following cmd: " ./file1 | ./file2 name_of_output_file.txt ".