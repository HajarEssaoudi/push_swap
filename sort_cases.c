/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:39:02 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/01 22:09:25 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(Stack *stack)
{
	Node	*node;

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

void	sort_a(Stack *stack)
{
	// Node	*node;
	if (!is_sorted(stack))
	{
		// node = stack->top;
		if (stack->size == 2)
			sort_two(stack);
		else if (stack->size == 3)
			sort_three(stack);
		// else if(stack->size <= 5)
		// 	sort_till_five(stack);
		// else if(stack->size > 5)
		// 	sort_more(stack);
	}
}
