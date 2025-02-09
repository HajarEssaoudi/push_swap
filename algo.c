/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:52:03 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/10 00:07:34 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_stack *a, t_stack *b, t_stack *sorting_stack,
		t_chunk_sort chunk_info)
{
	int		i;
	int		value;
	int		target;
	t_node	*current;

	i = 0;
	target = (chunk_info.chunk_size * (chunk_info.chunk_index + 1)) - 1;
	current = sorting_stack->top;
	while (i < target)
	{
		if (current)
			current = current->next;
		i++;
	}
	if (current)
		value = current->data;
	else
		value = biggest(sorting_stack);
	search_in_a(a, b, value);
}

void	move_b_to_a(t_stack *a, t_stack *b)
{
	t_node	*current_b;
	int		max;

	current_b = b->top;
	while (b->size > 0)
	{
		max = biggest(b);
		while (b->top->data != max)
		{
			if (index_node(b, max) <= b->size / 2)
			{
				rb(b);
			}
			else
				rrb(b);
		}
		pa(a, b);
	}
}

void	search_in_a(t_stack *a, t_stack *b, int value)
{
	int	size;

	size = a->size;
	while (size)
	{
		if (a->top->data <= value)
		{
			pb(a, b);
		}
		else
			ra(a);
		size--;
	}
}
