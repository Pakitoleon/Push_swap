/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:15:36 by @fgonzal2         #+#    #+#             */
/*   Updated: 2024/07/29 16:33:37 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}

void	sa(t_stack **a)
{
	print_stack(*a, "A before");
	printf("sa\n");
	swap(a);
}

void	sb(t_stack **b)
{
	print_stack(*b, "B before");
	printf("sb\n");
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	print_stack(*a, "A before");
	print_stack(*b, "B before");
	printf("ss\n");
	swap(a);
	swap(b);
}
