/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:37:56 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/11 20:51:57 by hes-saou         ###   ########.fr       */
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
	t_stack			*sorting_stack;
	t_stack			*copied_stack;
	int				chunk_count;
	t_chunk_sort	chunk_info;

	sorting_stack = create_stack();
	copied_stack = copy_stack(a);
	chunk_info.chunk_index = 0;
	sort_stack(copied_stack, sorting_stack);
	free_stack(copied_stack);
	if (a->size > 100)
		chunk_count = 8;
	else
		chunk_count = 4;
	chunk_info.chunk_size = a->size / chunk_count;
	if (a->size % chunk_count != 0)
		chunk_info.chunk_size++;
	while (chunk_info.chunk_index < chunk_count)
	{
		move_a_to_b(a, b, sorting_stack, chunk_info);
		chunk_info.chunk_index++;
	}
	free_stack(sorting_stack);
	move_b_to_a(a, b);
}
