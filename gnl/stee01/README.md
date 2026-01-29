# Cursus42_get_next_line
*This project has been created as part of the 42 curriculum by stee.*

# Overview (Description)
get_next_line is apart of the second group of projects. The idea is to return the next line being read from the file descriptor. The `BUFFER_SIZE` variable can be redefined using the additional flag `-D BUFFER_SIZE=n` during the compilation process.

# Running and Testing (Instructions)

This project includes `main.c` and `*.txt` files for easy testing purposes. Follow the instructions below to test the project; this process assumes a CLI interaction with the project.

## Compilation
```
# Full Command for Compilation
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl_test

# Run the Compiled Test Executable
./gnl_test

# Compile with Bonus Files
gcc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus

# Run the Bonus Test Executable
./gnl_bonus
```

## Testing (Resource Used)

Similarly, we utilize community testers to verify the correctness and robustness of our solution. This was done after self-testing. To access the tester directory, please proceed to this link: https://github.com/Tripouille/gnlTester.

# Project Details

`get_next_line.c` contains the main functions; the process of which starts from a static cache aiming to contain the contents read from the file. The general flow starts from `ft_readline`, where the cache starts storing contents from the file and checks whether there is a `'\n'` present within the cache, if so, the line will be extracted using `ft_extract` into a different line, then, the cache would be cleared of the line that has been returned from that iteration. `ft_append` simply appends each buffer line into the cache.

`get_next_line_utils` contain the different helper functions used in main, as libft was not allowed in the scope of this project.

# Learning Outcomes

This project aims to solidify concepts of static variables and buffer handling. Personally, I had the opportunity to consolidate knowledge regarding I/O as well as writing robust code whilst maintaining readability and sanitisation of code.


