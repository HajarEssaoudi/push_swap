/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:55:18 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/01 18:18:32 by hes-saou         ###   ########.fr       */
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
	stack->size++;
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
	stack->size = 0;
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
		ft_printf("%d ", current->data);
		current = current->next;
	}
	ft_printf("\n");
	// printf("%d\n", stack->size);
}

void	free_stack(Stack *stack)
{
	Node	*current_node;
	Node	*next_node;

	current_node = stack->top;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	free(stack);
}
