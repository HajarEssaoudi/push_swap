/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saou <hes-saou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:12:11 by hes-saou          #+#    #+#             */
/*   Updated: 2025/02/11 20:50:50 by hes-saou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current_node;
	t_node	*next_node;

	if (!stack)
		return ;
	current_node = stack->top;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	free(stack);
}

t_stack	*copy_stack(t_stack *stack)
{
	t_stack	*copied;
	t_node	*current;

	copied = create_stack();
	current = stack->top;
	while (current)
	{
		push(copied, current->data);
		current = current->next;
	}
	return (copied);
}

void	sort_stack(t_stack *source, t_stack *sorted)
{
	t_stack	*temp;
	int		value;

	temp = create_stack();
	while (source->size > 0)
	{
		value = pop(source);
		while ((sorted->size > 0) && value > sorted->top->data)
		{
			push(temp, sorted->top->data);
			pop(sorted);
		}
		push(sorted, value);
		while (temp->size > 0)
		{
			push(sorted, temp->top->data);
			pop(temp);
		}
	}
	free_stack(temp);
}

int	index_node(t_stack *stack, int num)
{
	t_node	*current;
	int		index;

	current = stack->top;
	index = 0;
	while (current)
	{
		if (current->data == num)
			break ;
		current = current->next;
		index++;
	}
	return (index);
}
