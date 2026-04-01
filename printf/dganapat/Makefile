# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 14:32:04 by dganapat          #+#    #+#              #
#    Updated: 2025/11/22 18:08:34 by dganapat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

AR = ar rcs

SRC = ft_printf.c \
	ft_printf_c.c \
	ft_printf_i_d.c \
	ft_printf_lowx.c \
	ft_printf_p.c \
	ft_printf_s.c \
	ft_printf_u.c \
	ft_printf_uppx.c \
	ft_putchar_fd.c \
	ft_putnbr_base.c \
	ft_putstr.c \
	ft_putnbr.c 
	
		
	
OBJS = $(SRC:.c=.o)

%.o : %.c	ft_printf.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^
	
all : $(NAME)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean
