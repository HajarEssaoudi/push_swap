/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:29:11 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/01 00:44:24 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct Node
{
	int			data;
	struct Node	*next;
}				Node;

typedef struct my_stack
{
	Node		*top;
	int			size;
}				Stack;

// Util functions to handle the args
long			convert(char *str);
int				ft_strcmp(const char *s1, const char *s2);

// Handle args
void			free_args(char **argv);
int				count_args(int argc, char **argv);
char			**alloc_args(int count_args, int argc, char **argv);
int				check_errors(char **str);

// Handle operations
void			sa(Stack *stack);

// Handle stack
Stack			*create_stack(void);
void			push(Stack *stack, int value);
Stack			*init_a(int ac, char **av);
void			print_a(Stack *stack);

// sort functions
int				is_sorted(Stack *stack);
void			sort_a(Stack *stack);
void			sort_two(Stack *stack);

#endif