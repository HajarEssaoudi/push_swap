/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:37:56 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/02 00:41:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->top->data > stack->top->next->data)
		sa(stack);
}

void sort_three(t_stack	*stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->top->data;
	second = stack->top->next->data;
	third = stack->top->next->next->data;
	if(!is_sorted(stack))
	{
		if(first < second && second > third && third > first)
		{
			sa(stack);
			ra(stack);
		}
		else if(first > second && second < third && third < first)
			ra(stack);
		else if (first < second && second > third && third < first)
			rra(stack);
		else if(first > second && second > third && third < first)
		{
			sa(stack);
			rra(stack);
		}
		else if(first > second && second < third && third > first)
			sa(stack);
	}	
}
