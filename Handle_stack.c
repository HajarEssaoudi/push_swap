/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:55:18 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/07 14:37:20 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit(1);
	node->data = value;
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(1);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_stack	*init_a(int ac, char **av)
{
	int		i;
	int		n;
	t_stack	*stack;

	n = 0;
	i = ac - 1;
	stack = create_stack();
	stack->size = 0;
	if (!stack)
		return (NULL);
	while (i >= 0)
	{
		n = ft_atoi(av[i]);
		push(stack, n);
		i--;
	}
	return (stack);
}

void	print_a(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		ft_printf("the index = %d, data = %d, is_above median ? %d  \n", current->index, current->data, current->above_median);
		current = current->next;
	}
}
// printf("%d\n", stack->size);

void	free_stack(t_stack *stack)
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = stack->top;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	free(stack);
}

int	stack_len(t_stack *stack)
{
	int count;
	t_node *c;

	count = 0;
	c = stack->top;
	while(c != NULL)
	{
		count++;
		c = c->next;
	}
	return(count);
}

void	stack_index(t_stack *stack)
{
	int	i;
	int median;
	t_node *node;

	i = 0;
	node = stack->top;
	median = stack_len(stack) / 2;
	while(node)
	{
		node->index = i;
		if(i <= median)
			node->above_median = 1;
		else
			node->above_median = 0;
		node = node->next;
		i++;
	}
}
