/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:29:11 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/07 21:07:35 by hes-saou         ###   ########.fr       */
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
	int			index;
	int			above_median;
	int			push_cost;
	int			cheapest;
	struct Node	*target_node;
	struct Node	*next;
}				t_node;

typedef struct my_stack
{
	t_node		*top;
	int			size;
}				t_stack;

// Util functions to handle the args
long			convert(char *str);
int				ft_strcmp(const char *s1, const char *s2);

// Handle args
void			free_args(char **argv);
int				count_args(int argc, char **argv);
char			**alloc_args(int count_args, int argc, char **argv);
int				check_errors(char **str);

// Handle operations
void			sa(t_stack *stack);
void			sb(t_stack *stack);
void			ss(t_stack *stack_a, t_stack *stack_b);
void			pa(t_stack *stack_a, t_stack *stack_b);
void			pb(t_stack *stack_a, t_stack *stack_b);
void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rr(t_stack *stack_a, t_stack *stack_b);
void			rra(t_stack *stack);
void			rrb(t_stack *stack);
void			rrr(t_stack *stack_a, t_stack *stack_b);

// Handle stack
t_stack			*create_stack(void);
void			push(t_stack *stack, int value);
t_stack			*init_a(int ac, char **av);
void			print_a(t_stack *stack);
void			free_stack(t_stack *stack);
int				stack_len(t_stack *stack);
void			stack_index(t_stack *stack);
// sort functions
int				is_sorted(t_stack *stack);
int				smallest(t_stack *stack);
void			sort_a(t_stack *stack_a, t_stack *stack_b);
void			sort_two(t_stack *stack);
void			sort_three(t_stack *stack);
void			sort_four(t_stack *stack_a, t_stack	*stack_b);
void			sort_five(t_stack *stack_a, t_stack	*stack_b);
void			sort_more(t_stack *stack_a, t_stack	*stack_b);

// turk implementation
void	implement_a_nodes(t_stack *a, t_stack *b);
#endif