CC = gcc
CFLAGS =
NAME = push_swap

SRCS = main.c utils_args.c utils_stack.c Handle_args.c Handle_errors.c Handle_stack.c \
       Handle_operations.c sort_cases.c sort.c
OBJS = $(SRCS:.c=.o)

LIB1 = libft/libft.a
LIB2 = ft_printf/libftprintf.a

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB1) $(LIB2) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
