# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/02 14:47:03 by dganapat          #+#    #+#              #
#    Updated: 2025/11/14 20:51:23 by dcheng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

AR = ar rcs

SRC = ft_isascii.c \
	ft_isprint.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlen.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_memcmp.c \
	ft_memchr.c \
	ft_strdup.c \
	ft_calloc.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_putnbr_fd.c \
	ft_striteri.c \
	ft_strmapi.c \
	ft_itoa.c \
	ft_split.c 
	
OBJS = $(SRC:.c=.o)


%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^

all : $(NAME)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
