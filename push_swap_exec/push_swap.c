/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:32:21 by @fgonzal2         #+#    #+#             */
/*   Updated: 2024/08/22 09:53:32 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../root/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**nbr;

	a = NULL;
	b = NULL;
	nbr = NULL;
	if (a == NULL && b == NULL)
	{
		if (argc > 1)
		{
			process_in(argc, argv, &nbr, &a);
			if (!stack_is_sorted(a))
			{
				sort_stack(&a, &b);
			}
		}
		if (!stack_sorted(&a))
		{
			sort_stack(&a, &b);
		}
		ft_stack_free(&a);
	}
	return (0);
}

int	stack_sorted(t_stack **a)
{
	t_stack	*tmp;

	if (!a)
		return (1);
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
