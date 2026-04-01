*This project has been created as part of the 42 curriculum by ryeong.*

# Project: get_next_line

## Description
The function will read a file containing text passed in using a file descriptor, and print out **one line** from the text. Repeated function calls will read and print the next line of the file and so on until the end of the file where it will then only print `(null)`.

Notes:
- The function should be able to read text from a file and from the standard input as well.
- When printing out the line, it should also include the newline as part of the text if it exists.

### Explanation and Justification of Algorithm Used
For my implementation of the function, i used a static 2d array called `stash` to store the contents of the buffer everytime `read()` is called. The function will first continously read the file and store the contents into `stash` until the end of file. Then i have a seperate function to extract one line from `stash` and print it out and then update the `stash` to remove the line that was extracted. This repeats for everytime the function is called until `stash` is empty where it will now be `NULL`.

Since `stash` is a 2d array, it can handle multiple file descriptors by only storing the contents in the respective index based on the file descriptor's number.

*This is a basic explanation of the function. More details will be shown and explained during evaluation if needed.*

## Instructions
- *You may skip step `1)` and `2)` if you have your own way of testing the code*

- *Step `1)` and `2)` assumes you are using my main function to test*

### 1)

Make sure you have some textfiles ready so it can be read. The contents can be anything or even nothing.

### 2)
Modify the variables `file1` to `file3` in the `main function` to match the name of your text files.

eg:
```
char *file1 = "test1.txt";
char *file2 = "test2.txt";
char *file3 = "test3.txt";
```

*You may modify the code further to handle more text files if you want.*

~~I am too lazy to make it modular, deal with it. hard coding moment.~~

### 3)
When compiling, you must include all the nessary .c files. (not including the .h file)
 - If you are using my main function: 
 	- Make sure the `main function` and its respective `include headers` are uncommented before compiling.

eg:
```
cc -Wall -Wextra -Werror <files>.c
./a.out
```

By default the `BUFFER_SIZE` is set to 42. To change the `BUFFER_SIZE`, add `-D BUFFER_SIZE=n` to the shell command. (`n` can be any integer)

eg:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 <files>.c
./a.out
```

**Important: The code must be able to compile _with and without_ the `-D BUFFER_SIZE` flag.**

## Resources
#### Readme
- https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax

#### General
- https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line // mainly used as a starting point to begin visualizing how the function will work and what libft functions i can take to help.
- https://www.geeksforgeeks.org/c/static-variables-in-c/
- https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/

### Declaration of AI Use
- Used to help debug and identify where memory leak errors are in the code.
- Discovered a trick from AI to help reduce line code regarding the `return()` where you can actually add additional parameters inside it.