# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/14 15:30:59 by asyeo             #+#    #+#              #
#    Updated: 2026/07/14 15:30:59 by asyeo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibft
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
INCLUDEDIR = include
SRCSDIR = srcs
SRC = $(SRCSDIR)/arg.c $(SRCSDIR)/arr.c $(SRCSDIR)/ops.c $(SRCSDIR)/ops_a.c $(SRCSDIR)/ops_b.c $(SRCSDIR)/push_swap.c $(SRCSDIR)/turksort_cost.c $(SRCSDIR)/turksort_helpers.c $(SRCSDIR)/turksort.c
OBJS = $(SRC:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -I$(INCLUDEDIR) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re

