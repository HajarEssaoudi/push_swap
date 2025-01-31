/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:55:18 by hes-saou          #+#    #+#             */
/*   Updated: 2025/01/25 18:43:33 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(Stack *stack, int value)
{
	Node	*node;

	node = (Node *)malloc(sizeof(Node));
	if (!node)
		exit(1);
	node->data = value;
	node->next = stack->top;
	stack->top = node;
}

Stack	*create_stack(void)
{
	Stack	*stack;

	stack = (Stack *)malloc(sizeof(Stack));
	if (!stack)
		exit(1);
	stack->top = NULL;
	return (stack);
}

Stack	*init_a(int ac, char **av)
{
	int		i;
	int		n;
	Stack	*stack;

	n = 0;
	i = ac - 1;
	stack = create_stack();
	if (!stack)
		return (NULL);
	while (i >= 0)
	{
		n = ft_atoi(av[i]);
		push(stack, n);
		i--;
	}
	return (stack);
}

void	print_a(Stack *stack)
{
	Node	*current;

	current = stack->top;
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}
