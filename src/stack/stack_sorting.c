/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:44:32 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/07/08 11:01:02 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

void	sort_tree(t_stack **stack)
{
	t_stack		*tmp;
	int			max;
	int			min;
	int			i;

	i = 0;
	tmp = (*stack);
	limits_stack(&min, &max, *stack);
	if (max == 1)
		ra(stack);
	else if ((min == 1) || (max == 3))
		sa(stack);
	else if (min == 3)
		rra(stack);
}

int	limits_stack(int *min, int *max, t_stack *stack)
{
	int	i;
	int	max_a;
	int	min_b;

	i = 1;
	*max = 1;
	*min = 1;
	min_b = stack->content;
	max_a = stack->content;
	while (++i <= (ft_stack_size(stack)+1))
	{
		stack = stack->next;
		if (min_b > stack->content)
		{
			min_b = stack->content;
			*min = i;
		}
		if (max_a < stack->content)
		{
			max_a = stack->content;
			*max = i;
		}
	}
	return (*min);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (stack_is_sorted (*a) && !b)
		return ;
	if (ft_stack_size(*a) == 2)
		sa(a);
	else if (ft_stack_size(*a) == 3)
	{
		while (!(stack_is_sorted(*a)))
			sort_tree(a);
	}
	else if (!stack_is_sorted (*a))
		biggest_sort(a, b);
}
