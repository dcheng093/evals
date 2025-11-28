# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crowlord <crowlord@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 23:07:11 by mbiusing          #+#    #+#              #
#    Updated: 2025/11/19 19:29:40 by crowlord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

SRC =		ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

BONUSSRC =	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJ 		= $(SRC:.c=.o)
BONUSOBJ 	= $(BONUSSRC:.c=.o)

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
AR 			= ar -rcs
RM 			= rm -f

# r : inserts the files member into archive w replacement #
# c : create archive #
# s : write / update  object-file index into d archive #

# Compilation #

%.o: %.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@

# make - builds library ( objs + libft.a ) #

all: ${NAME}

$(NAME): $(OBJ)
	@echo "Compiling..."
	@$(AR) $(NAME) $(OBJ)
	@echo "$(NAME) has just been birthed into existence along with the fellow object files"

# make bonus #

bonus: $(OBJ) $(BONUSOBJ)
	@$(AR) $(NAME) $(OBJ) $(BONUSOBJ)
	@echo "bonus functions added to $(NAME)."

# make clean - remove all object files #

clean:
	@$(RM) $(OBJ) $(BONUSOBJ)
	@echo "$(OBJ) and $(BONUSOBJ) has just been wiped out"

# make fclean - clean + remove libft.a #

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) has also just been wiped out"

# make re - rebuild #

re: fclean all

.PHONY: clean fclean re all bonus
