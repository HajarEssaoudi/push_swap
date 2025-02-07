/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.42.fr>                  +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:53:08 by hes-saou              #+#    #+#             */
/*   Updated: 2025/02/05 22:53:11 by hes-saou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	implement_a_nodes(t_stack *a, t_stack *b)
{
	stack_index(a);
	stack_index(b);
	set_target(a, b);
	cost_calculation_a(a, b);
	find_cheapest(a);
}

void	set_target(t_stack *a, t_stack *b)
{
	t_node	*current_b;
	t_node	*current_a;
	t_node	*target_node;
	int		best_match;

	current_a = a->top;
	while(current_a)
	{
		best_match = INT_MIN;
		current_b = b->top;
		while(current_b)
		{
			if(current_b->data < current_a->data && current_b->data > best_match)
			{
				best_match = current_b->data;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if(best_match == INT_MIN)
			current_a->target_node = find_max(b);
		else
			current_a->target_node = target_node;
		current_a = current_a->next;
	}
}

void	cost_calculation_a(t_stack *a, t_stack *b)
{
	t_node	*current_a;

	current_a = a->top;
	while(current_a)
	{
		current_a->push_cost = current_a->index;
		if(!(current_a->above_median))
			current_a->push_cost = a->size - (current_a->index);
		if(current_a->above_median)
			current_a->push_cost += current_a->target_node->index;
		else
			current_a->push_cost += b->size - (current_a->target_node->index);
		current_a = current_a->next;
	}
}

void	find_cheapest(t_stack *stack)
{
	int		cheapest_value;
	t_node	*cheapest_node;
	t_node	*current;

	cheapest_value = INT_MAX;
	current = stack->top;
	while(current)
	{
		if(current->push_cost < cheapest_value)
		{
			cheapest_value = current->push_cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	cheapest_node->cheapest = 1;
}

void	move_a_to_be(t_stack *a, t_stack *b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(a);
	if(cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if(!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	
}