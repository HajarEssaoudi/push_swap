/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:39:31 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/10 00:10:23 by hes-saou         ###   ########.fr       */
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
