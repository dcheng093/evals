# Cursus42_ft_printf
*This project has been created as part of the 42 curriculum by stee.*

# Overview (Description)
`ft_printf` is one of the second-level projects in the 42 Cursus, following `libft`, `get_next_line`, and `Born2BeRoot`. The purpose of this project is simple; to recreate the functionality of the `printf` function from standard I/O library (`<stdio.h>`). This project does not encompass all functionalities, but the crux of the function is replicated.

# Supported Format Specifiers (Guide)
As afforementioned, the function created within the scope of this project only accounts for a number of specifiers, this segment will list and explain each one.

| Specifier   | Description                             |
| ----------- | --------------------------------------- |
| `%c`        | Prints a single character               |
| `%s`        | Prints a string                         |
| `%p`        | Prints a pointer address in hexadecimal |
| `%d` / `%i` | Prints a signed decimal integer         |
| `%u`        | Prints an unsigned decimal integer      |
| `%x`        | Prints a lowercase hexadecimal integer  |
| `%X`        | Prints an uppercase hexadecimal integer |
| `%%`        | Prints a literal percent sign           |

# Running and Testing (Instructions)
This section describes the post git-clone process of compiling and testing that you can replicate. Furthermore, more details are entailed regarding the makefile to ensure ease of use.

## Compilation
A makefile has been included to ease the compilation process. The makefile creates a library containing the `printf` function named `libftprintf.a`. Below are some rules specified in the makefile for ease of use.

`make` - Simply creates the library. <br>
`make clean` - Removes object files. <br>
`make fclean` - Removes object files and the library file (*.a). <br>
`make re` - Executes `make fclean && make` consecutively. <br>

## Testing (Resource Used)
Similar to previous projects, a community supported tester was used to validate the results before submission. The tester used can be accessed in this repository through this link: https://github.com/Tripouille/printfTester#

# Learning Outcomes

This project's main "teaching point" was variadic functions. Specifically these refer to the collection of functions in the `<stdarg.h>` library. Beyond this, it also builds on the "modularity" and "readability" thinking that has been building over the past projects. 

# Author

**Karma0151235**

42 Kuala Lumpur | Sunway University | Lancaster University 

