/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:55:18 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/11 20:47:56 by hes-saou         ###   ########.fr       */
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

int	pop(t_stack *stack)
{
	t_node	*tmp;
	int		value;

	tmp = stack->top;
	value = tmp->data;
	stack->top = stack->top->next;
	free(tmp);
	stack->size--;
	return (value);
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
		ft_printf("%d ", current->data);
		current = current->next;
	}
	ft_printf("\n");
}
