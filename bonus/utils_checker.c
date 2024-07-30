/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:20:39 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/07/30 16:33:24 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
//look if the stack is sorted
int	stack_is_sorted_bonus(t_stack *stack)
{
	if (ft_stack_size(stack) < 2)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
//calcule the size of the stack
int ft_stack_size_bonus(t_stack *stack)
{
	int size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return size;
}
//free the stack
void ft_stack_free_bonus(t_stack **stack, t_stack **stack2)
{
	t_stack *current;
	t_stack *next_node;

	if (stack && *stack)
	{
		current = *stack;
		while (current)
		{
			next_node = current->next;
			free(current);
			current = next_node;
		}
		*stack = NULL;
	}
	if (stack2 && *stack2)
	{
		current = *stack2;
		while (current)
		{
			next_node = current->next;
			free(current);
			current = next_node;
		}
		*stack2 = NULL;
	}
}