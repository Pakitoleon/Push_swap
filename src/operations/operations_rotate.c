/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:52:38 by @fgonzal2         #+#    #+#             */
/*   Updated: 2024/07/30 11:32:11 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = (*stack);
	first->prev = stack_last_node(*stack);
	stack_last_node(*stack)->next = first;
	*stack = (*stack)->next;
	first->next = NULL;
	(*stack)->prev = NULL;
}

void	ra(t_stack **a)
{
	printf("ra\n");
	rotate(a);
}

void	rb(t_stack **b)
{
	printf("rb\n");
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	printf("rr\n");
	rotate(a);
	rotate(b);
}
