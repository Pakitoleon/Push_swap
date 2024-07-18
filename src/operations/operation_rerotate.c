/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rerotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:31:24 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/07/08 11:01:52 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

void	rrotate(t_stack **stack)
{
	t_stack	*find_last;
	t_stack	*to_first;
	int		i;

	if (!(*stack) || !(*stack)->next)
		return ;
	find_last = (*stack);
	to_first = stack_last_node(*stack);
	i = ft_stack_size(*stack) - 1;
	while (--i > 0)
		find_last = find_last->next;
	find_last->next = NULL;
	to_first->prev = NULL;
	to_first->next = (*stack);
	(*stack) = to_first;
}

void	rra(t_stack **a)
{
	printf("rra\n");
	rrotate(a);
}

void	rrb(t_stack **b)
{
	printf("rrb\n");
	rrotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	printf("rrr\n");
	rrotate(a);
	rrotate(b);
}
