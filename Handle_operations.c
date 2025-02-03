/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:39:31 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/02 10:55:51 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = tmp;
}

void	sa(t_stack *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

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

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*before_last;

	last = stack->top;
	before_last = NULL;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL; /*to make the before last a "last"*/
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
