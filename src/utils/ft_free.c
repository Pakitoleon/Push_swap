/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:52:45 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/07/17 11:49:51 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

void	ft_stack_free(t_stack **stack)
{
	t_stack	*node;
	t_stack	*swp;

	if (!stack)
		return ;
	node = *stack;
	while (node)
	{
		swp = node->next;
		node->content = 0;
		node->index = 0;
		node->cost = 0;
		node->is_upper = 0;
		if (node->target)
			node->target = NULL;
		free(node);
		node = swp;
	}
	*stack = NULL;
}

void	free_array(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free(arr);
}

void	stack_clear(t_stack **a)
{
	t_stack	*current;
	t_stack	*next;

	if (!a || !*a)
		return ;
	current = *a;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*a = NULL;
}

void	free_nbr(char ***nbr)
{
	int	i;

	i = 0;
	if (nbr == NULL || *nbr == NULL)
		return ;
	{
		while ((*nbr)[i] != NULL)
			i++;
		{
			free((*nbr)[i]);
			(*nbr)[i] = NULL;
		}
		free(*nbr);
		*nbr = NULL;
	}
}

void	free_split(char ***result)
{
	int	i;

	i = 0;
	while ((*result)[i])
	{
		free((*result)[i]);
		i++;
	}
	free(*result);
	*result = NULL;
}
