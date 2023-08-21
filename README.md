# 42_GNL
This project is about programming a function that returns a line read from a FD (file descriptor).

# I - Project Introduction
By calling the GNL function in a loop, the text in fd is read one line at a time until EOF is reached.

Even if the file is read to the end the first time the GNL function is called, the second time it is called, it must start at the second line.

The function should work properly when reading from file, from redirection, or from stdin.

This program must be compiled with the -D BUFFER_SIZE=xx flag. That is, the read function must use the BUFFER_SIZE defined at compile time to read from standard input or from a file.

The function should work properly even when BUFFER_SIZE is 1, 9999, or 10000000 (10 million).

Succeeding get_next_line with Single Static Variable.

Making it a function that can manage multiple file descriptors. For example, if file descriptors 3, 4, and 5 can be read, get_next_line should be able to be called once on 3, once on 4, then once on 3, then once on 5. without losing the reading thread of each descriptor.

# II - A Few Rules
Prototype: int get_next_line(int fd, char **line);

Parameters: File descriptor for reading and the value of what has been read.

Return value: 1 for a line has been read, 0 for EOF has been reached and -1 for an error happened.

External functs allowed: read, malloc and free.
