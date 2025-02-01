/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:39:02 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/01 23:14:25 by root             ###   ########.fr       */
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

void	sort_a(t_stack *stack)
{
	// t_node	*node;
	if (!is_sorted(stack))
	{
		// node = stack->top;
		if (stack->size == 2)
			sort_two(stack);
		// else if (stack->size == 3)
		// 	sort_three(stack);
		// else if(stack->size <= 5)
		// 	sort_till_five(stack);
		// else if(stack->size > 5)
		// 	sort_more(stack);
	}
}
