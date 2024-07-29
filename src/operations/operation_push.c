/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:32:59 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/07/29 16:30:58 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

void	print_stack(t_stack *stack, const char *name)
{
	printf("Stack %s: ", name);
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

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
	printf("pa\n");
	print_stack(*a, "A before");
	print_stack(*b, "B before");
	push(b, a);
	print_stack(*a, "A after");
	print_stack(*b, "B after");
}

void	pb(t_stack **a, t_stack **b)
{
	printf("pb\n");
	print_stack(*a, "A before");
	print_stack(*b, "B before");
	push(a, b);
	print_stack(*a, "A after");
	print_stack(*b, "B after");
}