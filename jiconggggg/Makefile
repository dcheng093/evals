# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 20:35:02 by jichong           #+#    #+#              #
#    Updated: 2025/11/11 15:54:45 by dcheng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
CFLAGSS	= -Wall -Wextra -Werror
AR	= ar -rcs
NAME	= libft.a
MAIN	= atoi bzero calloc strlen itoa strdup strchr strrchr\
		isalpha isdigit isalnum isascii isprint memset memcpy\
		memmove strlcpy strlcat toupper tolower strncmp memchr\
		memcmp strnstr atoi substr strjoin split strmapi\
		strtrim striteri putchar_fd putstr_fd putendl_fd putnbr_fd
BONUS	= lstnew lstadd_front lstsize lstlast lstadd_back\
		lstdelone lstclear lstiter lstmap
MAINFILES	= $(addprefix ft_,$(addsuffix .c, $(MAIN)))
BONUSFILES	= $(addprefix ft_,$(addsuffix .c, $(BONUS)))
MAINOBJ	= $(MAINFILES:.c=.o)
BONUSOBJ = $(BONUSFILES:.c=.o)

all:	$(NAME) bonus

$(NAME): $(MAINOBJ)
	$(AR) $(ARFLAGS) $@ $^

bonus:	$(BONUSOBJ)
	$(AR) $(ARFLAGS) $(NAME) $^

%.o : %.c
	$(CC) -c $(CFLAGSS) $< -o $@

clean:
	rm -f $(MAINOBJ) $(BONUSOBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
