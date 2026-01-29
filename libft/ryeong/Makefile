NAME = libft.a
sourcefiles := $(addprefix ft_, \
	isalpha \
	isdigit \
	isalnum \
	isascii \
	isprint \
	strlen \
	memset \
	bzero \
	memcpy \
	memmove \
	strlcpy \
	strlcat \
	toupper \
	tolower \
	strchr \
	strrchr \
	strncmp \
	memchr \
	memcmp \
	strnstr \
	atoi \
	calloc \
	strdup \
	substr \
	strjoin \
	strtrim \
	split \
	itoa \
	strmapi \
	striteri \
	putchar_fd \
	putstr_fd \
	putendl_fd \
	putnbr_fd \
)

bonus_sourcefiles := $(addprefix ft_, \
	lstnew \
	lstadd_front \
	lstsize \
	lstlast \
	lstadd_back \
	lstdelone \
	lstclear \
	lstiter \
	lstmap \
)

all: $(NAME)

$(NAME):
	@cc -I . -c -Wall -Wextra -Werror $(addsuffix .c ,$(sourcefiles))
	@ar rcs $(NAME) $(addsuffix .o ,$(sourcefiles))
	@echo "Archive file $(NAME) created"

bonus:
	@cc -I . -c -Wall -Wextra -Werror $(addsuffix .c ,$(sourcefiles)) $(addsuffix .c ,$(bonus_sourcefiles))
	@ar rcs $(NAME) $(addsuffix .o ,$(sourcefiles)) $(addsuffix .o ,$(bonus_sourcefiles))
	@echo "Archive file $(NAME) created with bonus files"

clean:
	@rm -f $(addsuffix .o ,$(sourcefiles)) $(addsuffix .o ,$(bonus_sourcefiles))
	@echo "Object files deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "Archive file $(NAME) deleted"

re: fclean all
	@echo "========RECREATED========"

.PHONY: all clean fclean re bonus

# test: all
# 	@cc -I . run/*.c libft.a
# 	@./a.out

# run: all
# 	@cc -I . -g -Wall -Wextra -Werror run/*.c libft.a
# 	@./a.out

# bsd: all
# 	@cc -I . -g -Wall -Wextra -Werror -lbsd run/*.c libft.a
# 	@./a.out

# .PHONY: all clean fclean re run test bsd bonus