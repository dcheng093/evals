*This project has been created as part of the 42 curriculum by yoowong yoowong@student.42kl.edu.my.*

**DESCRIPTION**
The goal of the get_next_line (abbreviated GNL) project is to read and retrieve a line from a text file until it reaches a new line or end of file. The text file is pointed to by the file descriptor.

**INSTRUCTIONS**
To utilize GNL, compile get_next_line.c, get_next_line_utils.c, get_next_line.h and a main file which contains the name of the text file which the caller wish to read. GNL Bonus is similar with the additional ability to read from different file descriptors without losing track of each one.

**RESOURCES**
Medium.com contains a very nice step to step guide by LAnnur-S for the string approach. *https://medium.com/@lannur-s/gnl-c3cff1ee552b*.
Google Gemini and Anthropic Claude AI were used as a guide for different approaches and general Q&A for this project. Gemini was also used for debugging the main code.

**TECHNICAL CHOICES**
The string method was chosen as the approach is relative straightforward and more intuitive.

**TECHNICAL IMPLEMENTATION**
The implementation is done by creating the static variable *stash and helper functions from libft, including ft_strchr, ft_substr, ft_strlen and ft_strjoin. 

GNL will first attempt to read from the file descriptor and store the data in a temporary buffer with a designated buffer size unless it reaches end of file (EOF). While not reaching a line break ('\n') or EOF, it will combine the strings read by the buffer.

Next, GNL will extract the line of characters from the combined string up to the line break or null terminator ('\0'). The line will be what GNL returns to the caller.

And finally, GNL will store the leftover characters (whatever after the line break) in the static variable for further usage if applicable. The old stash will be freed to prevent memleak.

GNL Bonus is roughly the same except we store the stash in an array of array.