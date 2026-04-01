*This project has been created as part of the 42 curriculum by nzhuravl*

# Libft

## Description

Libft is a custom implementation of the standard C library functions, designed to strengthen mastery of memory operations, pointer manipulation, and modular C design.  
This project is often one of the first major steps at 42, and its goal is to build a foundational library that mimics and reimplements many core functions of libc.

The library includes:

- Standard character and string functions (`ft_strlen`, `ft_strchr`, `ft_strdup`, etc.)
- Memory functions (`ft_memcpy`, `ft_memset`, `ft_calloc`, etc.)
- List utilities (singly linked list operations like `ft_lstnew`, `ft_lstmap`, etc.)
- Additional custom functions (e.g. `ft_split`, `ft_itoa`, etc.)

## Instructions

To compile the library:

```bash
make
```

This will create `libft.a`, a static library archive containing all the compiled object files.

To clean build files:

```bash
make clean     # removes .o files
make fclean    # removes .o files and libft.a
```

To recompile from scratch:

```bash
make re
```

To use this library in another project, include the `libft.h` header and link `libft.a` during compilation:

```c
#include "libft.h"
```

```bash
gcc main.c -L. -lft
```

## Resources

### References

- [The C Programming Language – Kernighan & Ritchie](https://en.wikipedia.org/wiki/The_C_Programming_Language)
- [cplusplus.com](https://cplusplus.com/reference/clibrary/)
- [GNU C Library documentation](https://www.gnu.org/software/libc/manual/)

### Use of AI

AI was used in the following ways:
- Explaining obscure or undefined behavior in edge cases
- Reviewing logic for memory safety
- Clarifying pointer arithmetic and type-casting nuances
- Writing Readme files

## Library Overview

Libft is split into logical sections:

### Part 1 – libc Functions

Reimplementations of standard libc functions like:

- `ft_strlen`, `ft_strncmp`, `ft_memcpy`, `ft_strchr`, `ft_isalpha`, etc.

### Part 2 – Additional Functions

Higher-level utility functions such as:

- `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_strtrim`, `ft_strjoin`

### Part 3 – Linked List Functions

A full singly linked list module:

- `ft_lstnew`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`
- `ft_lstiter`, `ft_lstdelone`, `ft_lstclear`, `ft_lstmap`

All functions conform to 42's memory safety standards and Norminette style guide.
