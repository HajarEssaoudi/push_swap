CC = gcc
CFLAGS = -Werror -Wextra -Wall
NAME = push_swap

SRCS = main.c utils_args.c Handle_args.c Handle_errors.c Handle_stack.c \
		Handle_operations.c sort_cases.c sort.c
OBJS = $(SRCS:.c=.o)

LIB1 = libft/libft.a
LIB2 = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(LIB1) $(LIB2) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB1) $(LIB2) -o $(NAME)

$(LIB1):
	make -C libft

$(LIB2):
	make -C ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C ft_printf fclean

do: all clean

re: fclean all

.PHONY: all clean fclean re
