/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:52:03 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/15 23:26:44 by hes-saou         ###   ########.fr       */
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
	current = sorting_stack->top;
	target = (chunk_info.chunk_index + 1) * chunk_info.chunk_size - 1;
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
	int		max;

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
	int i;
	int	size;

	i = 0;
	size = a->size;
	while (i < size && a->size > 3)
	{
		if (a->top->data <= value)
		{
			pb(a, b);
		}
		else
			ra(a);
		i++;
	}
	if(a->size == 3)
	{
		sort_three(a);
	}
}
