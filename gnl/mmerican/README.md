*This project has been created as part of the 42 curriculum by mmerican.*

# Get Next Line
*Reading from line from a file descriptor is FAR too tedious*

## Description

The goal of *get_next_line* is to create a function that takes in a file descriptor and outputs the next line in the file as a C-style string (unless an error occurs, or there is nothing left to read).

A *file descriptor* is an integer that is sort of like an identifier for a file that's in the program's open file table. When a file is opened, it's given a file descriptor (typically the lowest positive integer that hasn't been used yet).
There are also some special file descriptors: 0 for stdin, 1 for stdout, and 2 for stderr. Negative values are used to indicate errors in opening files. File descriptors can also be used for other things, such as network connections.

The function ```get_next_line()``` lets you read from file descriptors, one line at a time, which makes it much easier to parse data in human-readable formats.

## Instructions
To compile the source code into a library, you need to use these 3 BASH commands:

```cc -Wall -Wextra -Werror -c get_next_line.c get_next_line_utils.c```
// *This will compile the source files into object files. The -Wall -Wextra -Werror flags aren't really necessary unless a modification to the source files is made.*
// *You may also add in the -D BUFFER_SIZE=n flag to customise the size of the buffer used by read().*

```ar rcs get_next_line.a get_next_line.o get_next_line_utils.o```
// *This will create the library. You can use the object files directly instead, but I don't recommend it because it can cause issues if you forget to include one or the other.*

```rm -f get_next_line.o get_next_line_utils.o```
// *This will delete the object files. You may skip this step if you want to keep them.*

To use the library, just include the library in your compiler call.

Example:

```cc <your source files> get_next_line.a -o <binary name>```



You can also include the source files directly in your compiler call. Example:

```cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c <your source files> -o <program name>```

### *Warning*
Due to me not implementing the bonus features, get_next_line() can only be used on one file descriptor at a time. If two file descriptors are used at once, the contents of the files can get mixed up. This can be mitigated by reading the entirety of one file before starting on the next one.

## Algorithm
My algorithm uses a fixed-size static buffer, and two extra static variables for keeping track of the end of the buffer, and which characters have already been returned. All of the static variables are stored in a helper function, ```read_stuff()```.

When a call to ```read_stuff()``` is made, the function will first check if the buffer is empty, or if all of the characters in the buffer have already been "used up". If this is the case, then it will make a call to the library function, ```read()```.

In either case, ```read_stuff()``` will return the characters starting from the start of the buffer (or from the previous newline found), until the next newline stored in the buffer (or until the end of the buffer, whichever comes first).

The main function, ```get_next_line()``` will keep calling ```read_stuff()``` and will keep appending each string returned by ```read_stuff()``` to the previous strings, until a newline/EOF is found.

I chose this method because it was simple and relatively easy to implement, with few edge cases to work around. I used a static buffer to store the return value of ```read()``` as opposed to a dynamically-allocated buffer because it reduces the number of ```malloc()``` calls, lowering the risk of weird memory errors.

## Resources
I used the following manual pages:
- man 3 read
- man 2 open

*To my knowledge*, the only AI tool I used in this project was Microsoft Visual Studio's Intellicode auto-completion feature. I verified that the code that it was suggesting was what I was going to type anyway.
