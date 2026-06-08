NAME = push_swap
LIB = libft/libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror -g -Ilibft

SRCS = main.c \
	parser.c \
	parser_2.c \
	stack.c \
	adaptive.c \
	insertion_sort.c \
	bucket_sort.c \
	bucket_sort_2.c \
	merge_sort.c 

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(OBJ) -L libft -lft -lm -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIB):
	make -C libft

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re 