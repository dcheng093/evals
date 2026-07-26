# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/21 13:39:08 by mbiusing          #+#    #+#              #
#    Updated: 2026/07/21 09:57:03 by mbiusing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -rf

SRC_DIR		= srcs/
OBJ_DIR		= objs/
OPS_DIR		= $(SRC_DIR)operations/

LIBFT_DIR	= include/libft
LIBFT		= $(LIBFT_DIR)/libft.a

INC			= -I include -I $(LIBFT_DIR)

MAIN		= $(SRC_DIR)main.c

SOURCE		= $(SRC_DIR)parse.c \
			  $(SRC_DIR)validate.c \
			  $(SRC_DIR)stack.c \
			  $(SRC_DIR)index.c \
			  $(SRC_DIR)sort.c \
			  $(SRC_DIR)sort_utils.c \
			  $(SRC_DIR)free_error.c

OPS			= $(OPS_DIR)swap_ops.c \
			  $(OPS_DIR)push_ops.c \
			  $(OPS_DIR)r_otate_ops.c \
			  $(OPS_DIR)rr_otate_ops.c

SRCS		= $(MAIN) $(SOURCE) $(OPS)

OBJS		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re