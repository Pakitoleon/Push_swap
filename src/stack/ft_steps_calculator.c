/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_steps_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:05:40 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/08/22 09:54:24 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

void	stack_a_target(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	long	nearest;

	while (a)
	{
		nearest = LONG_MIN;
		tmp = b;
		while (tmp)
		{
			if (a->content > tmp->content && tmp->content > nearest)
			{
				nearest = tmp->content;
				a->target = tmp;
			}
			tmp = tmp->next;
		}
		if (nearest == LONG_MIN)
			a->target = ft_min(b);
		a = a->next;
	}
}

void	stack_b_target(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	long	nearest;

	while (b)
	{
		nearest = LONG_MAX;
		tmp = a;
		while (tmp)
		{
			if (b->content < tmp->content && tmp->content < nearest)
			{
				nearest = tmp->content;
				b->target = tmp;
			}
			tmp = tmp->next;
		}
		if (nearest == LONG_MAX)
			b->target = ft_min(a);
		b = b->next;
	}
}

void	cost_calculator(t_stack *a, t_stack *target, int c_len, int d_len)
{
	int	nba;
	int	nbt;

	nba = a->index;
	nbt = target->index;
	if (a->is_upper && (target->is_upper
			|| (nbt - nba < target->is_mid)))
		a->cost = mx(a->index, target->index);
	else if (!a->is_upper && (!target->is_upper
			|| (nbt + c_len - a->index) > target->is_mid))
		a->cost = mx(c_len - a->index + 1, d_len - target->index + 1);
	else if (a->is_upper)
		a->cost = a->index + (d_len - target->index + 1);
	else
		a->cost = (c_len - a->index + 1) + target->index;
}

t_stack	*stack_cost(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;
	t_stack	*target;
	int		low_cost;
	int		a_len;
	int		b_len;

	low_cost = INT_MAX;
	a_len = ft_stack_size (a);
	b_len = ft_stack_size (b);
	while (a)
	{
		target = a->target;
		cost_calculator(a, target, a_len, b_len);
		if (a->cost < low_cost)
		{
			low_cost = a->cost;
			cheapest = a;
		}
		a = a->next;
	}
	return (cheapest);
}
