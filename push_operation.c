/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:09:53 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/10 00:16:07 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (stack_b->size == 0 || !stack_b->top)
		exit(1);
	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	stack_b->size--;
	tmp->next = stack_a->top;
	stack_a->top = tmp;
	stack_a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (stack_a->size == 0)
		exit(1);
	tmp = stack_a->top;
	stack_a->top = stack_a->top->next;
	stack_a->size--;
	tmp->next = stack_b->top;
	stack_b->top = tmp;
	stack_b->size++;
	write(1, "pb\n", 3);
}

void	rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*current;

	if (stack->size <= 2)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	current = stack->top;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack *stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}
