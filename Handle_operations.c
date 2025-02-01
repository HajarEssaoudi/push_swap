/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:39:31 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/01 01:06:02 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(Stack *stack)
{
	int	tmp;
	tmp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = tmp;
}

void	sa(Stack *stack)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(Stack *stack)
{
	swap(a);
	write(1, "sb\n", 3);
}

void	ss(Stack *stack_a, Stack *stack_b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	pa(Stack *stack_a, Stack *stack_b)
{
	Node *tmp;
	if(stack_b->size == 0)
		exit(1);
	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	b->size--;
	tmp->next = a->top;
	a->top = tmp;
	a->size++;
	write(1, "pa\n", 3);
}

void	pa(Stack *stack_a, Stack *stack_b)
{
	Node *tmp;
	if(stack_a->size == 0)
		exit(1);
	tmp = stack_a->top;
	stack_a->top = stack_a->top->next;
	a->size--;
	tmp->next = b->top;
	b->top = tmp;
	b->size++;
	write(1, "pb\n", 3);
}