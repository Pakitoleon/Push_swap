/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:38:50 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/07/08 11:02:09 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

// return the size of the stack.
int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	i++;
	return (i);
}

// finds and return the smallest number in the stack
t_stack	*ft_min(t_stack *stack)
{
	int			value;
	t_stack		*stack_node;

	value = stack->content;
	stack_node = stack;
	while (stack->next)
	{
		stack = stack->next;
		if (value > stack->content)
		{
			value = stack->content;
			stack_node = stack;
		}
	}
	return (stack_node);
}

//finds and return the bigest number in the stack
t_stack	*ft_max(t_stack *stack)
{
	int			i;
	t_stack		*stack_node;
	int			max;

	i = 1;
	max = stack-> content;
	stack_node = stack;
	while (++i <= ft_stack_size(stack) + 1)
	{
		stack = stack->next;
		if (max < stack->content)
		{
			max = stack->content;
			stack_node = stack;
		}
	}
	return (stack_node);
}

t_stack	*stack_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
