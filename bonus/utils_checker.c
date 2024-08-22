/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:20:39 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/08/22 09:57:18 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//calcule the size of the stack
int	ft_stack_size_bonus(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

//free the stack
void	ft_stack_free_bonus(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	while (*b)
	{
		temp = (*b)->next;
		free(*b);
		*b = temp;
	}
	*a = NULL;
	*b = NULL;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
