/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:19:40 by @fgonzal2         #+#    #+#             */
/*   Updated: 2024/08/22 09:54:42 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

int	ft_find_index(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

int	ft_find_place_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < stack_last_node(stack_b)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_b)->nbr || nbr_push < ft_min(stack_b)->nbr)
		i = ft_find_index(stack_b, ft_max(stack_b)->nbr);
	else
	{
		tmp = stack_b->next;
		while (stack_b->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_place_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > stack_last_node(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_a)->nbr || nbr_push < ft_min(stack_a)->nbr)
		i = ft_find_index(stack_a, ft_max(stack_a)->nbr);
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
