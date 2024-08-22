/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:32:59 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/08/22 10:02:40 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

void	push(t_stack **origin, t_stack **target)
{
	t_stack	*send;
	t_stack	*second_or;

	if (!(*origin))
		return ;
	send = (*origin);
	second_or = (*origin)->next;
	if (second_or)
		second_or->prev = NULL;
	if (!(*target))
		send->next = NULL;
	else
	{
		send->next = (*target);
		send->next->prev = send;
	}
	*origin = second_or;
	*target = send;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
