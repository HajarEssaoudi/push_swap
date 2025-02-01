/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:39:31 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/01 19:00:06 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(Stack *stack)
{
	int	tmp;

	tmp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = tmp;
}

void	sa(Stack *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(Stack *stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(Stack *stack_a, Stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

void	pa(Stack *stack_a, Stack *stack_b)
{
	Node	*tmp;

	if (stack_b->size == 0)
		exit(1);
	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	stack_b->size--;
	tmp->next = stack_a->top;
	stack_a->top = tmp;
	stack_a->size++;
	write(1, "pa\n", 3);
}

void	pb(Stack *stack_a, Stack *stack_b)
{
	Node	*tmp;

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

void	rotate(Stack *stack)
{
	Node	*tmp;
	Node	*current;

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

void	ra(Stack *stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(Stack *stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(Stack *stack_a, Stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

void	reverse_rotate(Stack *stack)
{
	Node	*tmp;
	Node	*current;

	tmp = stack->top;
	current = NULL;
	while(tmp->next != NULL)
	{
		current = tmp;
		tmp =tmp->next;
	}
	current->next = NULL;
	tmp->next = stack->top;
	stack->top = tmp;
}

void	rra(Stack *stack)
{
	reverse_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(Stack *stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(Stack *stack_a, Stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}