CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRCS = main.c utils.c Handle_args.c Handle_errors.c
OBJS = $(SRCS:.c=.o)

# Paths to Static Libraries
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
