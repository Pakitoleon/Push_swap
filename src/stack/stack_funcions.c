/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:13:16 by @fgonzal2         #+#    #+#             */
/*   Updated: 2024/08/22 09:54:28 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

void	stack_add(t_stack **a, int n)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->content = n;
	new_node->next = NULL;
	new_node->target = NULL;
	if (!(*a))
	{
		new_node->prev = NULL;
		*a = new_node;
	}
	else
	{
		stack_last_node(*a)->next = new_node;
		new_node->prev = stack_last_node(*a);
	}
}

void	stack_init(t_stack **a, char **nbr)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while (nbr[i] != NULL)
	{
		n = ft_atol(nbr[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_stack_free(a);
			free_nbr(&nbr);
			ft_print_error();
		}
		stack_add(a, (int)n);
		i++;
	}
}
