/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:37:56 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/07 11:30:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->top->data > stack->top->next->data)
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->top->data;
	second = stack->top->next->data;
	third = stack->top->next->next->data;
	if (is_sorted(stack))
		return ;
	if (first < second && second > third && third > first)
	{
		sa(stack);
		ra(stack);
	}
	else if (first > second && second < third && third < first)
		ra(stack);
	else if (first < second && second > third && third < first)
		rra(stack);
	else if (first > second && second > third && third < first)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && third > first)
		sa(stack);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = smallest(stack_a);
	while (stack_a->top->data != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = smallest(stack_a);
	while (stack_a->top->data != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	min = smallest(stack_a);
	while (stack_a->top->data != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_more(t_stack *a, t_stack *b)
{
	if(a->size > 3 && !is_sorted(a))
		pb(a, b);
	if(a->size > 3 && !is_sorted(a))
		pb(a, b);
	while(a->size > 3 && !is_sorted(a))
	{
		implement_a_nodes(a, b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while(b)
	{
		implement_b_nodes(a, b);
		move_b_to_a(a, b);
	}
	current_index(a);
	min_on_top(a);
}