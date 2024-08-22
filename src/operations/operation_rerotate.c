/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rerotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:31:24 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/08/22 10:01:57 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

void	rrotate(t_stack **stack)
{
	t_stack	*find_last;
	t_stack	*to_first;

	if (!(*stack) || !(*stack)->next)
		return ;
	find_last = (*stack);
	to_first = stack_last_node(*stack);
	while (find_last->next->next != NULL)
		find_last = find_last->next;
	find_last->next = NULL;
	to_first->prev = NULL;
	to_first->next = (*stack);
	(*stack)->prev = to_first;
	(*stack) = to_first;
}

void	rra(t_stack **a)
{
	rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}

void	rrr_bonus(t_stack **a, t_stack **b)
{
	rrotate(a);
	rrotate(b);
}
