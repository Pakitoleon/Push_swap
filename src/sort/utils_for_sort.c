/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:03:58 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/07/08 11:01:22 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

int	stack_is_sorted(t_stack *stack)
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

void	top_node_a(t_stack *node, t_stack **stack)
{
	while (*stack != node)
	{
		if (node->is_upper)
			ra(stack);
		else
			rra(stack);
		stack_index_side(*stack);
	}
}

void	top_node_b(t_stack *node, t_stack **stack)
{
	while (*stack != node)
	{
		if (node->is_upper)
			rb(stack);
		else
			rrb(stack);
		stack_index_side(*stack);
	}
}

void	stack_index_side(t_stack *stack)
{
	int	i;
	int	half;

	i = 0;
	half = (ft_stack_size(stack) + 1) / 2;
	while (stack)
	{
		stack->index = ++i;
		stack->is_mid = half;
		if (i <= half)
		{
			stack->is_upper = 1;
			stack->is_down = half - i;
		}
		else
		{
			stack->is_upper = 0;
			stack->is_down = i - half;
		}
		stack = stack->next;
	}
}

t_stack	*stack_set_structure(t_stack *a, t_stack *b)
{
	stack_index_side(a);
	stack_index_side(b);
	stack_a_target(a, b);
	return (&(*stack_cost(a, b)));
}
