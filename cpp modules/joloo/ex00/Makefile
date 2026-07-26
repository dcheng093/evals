NAME = a.out
# CC=g++
# CFLAGS=-Wall -Wextra -Werror -g -std=c++98
CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98
SOURCES	= \
main.cpp \
Fixed.cpp

all: $(NAME)

OBJECTS = $(SOURCES:.cpp=.o)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) 

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
