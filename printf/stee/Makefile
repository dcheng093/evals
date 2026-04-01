# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 16:24:28 by stee              #+#    #+#              #
#    Updated: 2025/11/07 14:15:30 by stee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTDIR = libft

SRC = ft_printf.c \
	ft_printf_utils.c \
	ft_printf_utils2.c

OBJS = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT = $(LIBFTDIR)/libft.a

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -I. -I${LIBFTDIR} -c $< -o $@

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}

${NAME}: ${LIBFT} ${OBJS} 
	cp ${LIBFT} ${NAME}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
