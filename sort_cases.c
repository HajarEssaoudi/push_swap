/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:39:02 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/10 00:07:02 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (1);
	node = stack->top;
	if (stack->size <= 1)
		return (1);
	while (node && node->next)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

int	smallest(t_stack *stack)
{
	int		smallest;
	t_node	*current;

	smallest = stack->top->data;
	current = stack->top;
	while (current != NULL)
	{
		if (current->data < smallest)
			smallest = current->data;
		current = current->next;
	}
	return (smallest);
}

int	biggest(t_stack *stack)
{
	int		biggest;
	t_node	*current;

	biggest = stack->top->data;
	current = stack->top;
	while (current != NULL)
	{
		if (current->data > biggest)
			biggest = current->data;
		current = current->next;
	}
	return (biggest);
}

void	sort_a(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_sorted(stack_a))
	{
		if (stack_a->size == 2)
			sort_two(stack_a);
		else if (stack_a->size == 3)
			sort_three(stack_a);
		else if (stack_a->size == 4)
			sort_four(stack_a, stack_b);
		else if (stack_a->size == 5)
			sort_five(stack_a, stack_b);
		else if (stack_a->size > 5)
			sort_more(stack_a, stack_b);
	}
}
