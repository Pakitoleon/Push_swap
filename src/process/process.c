/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:35:11 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/08/22 09:54:05 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

void	check_input(char **nbr)
{
	int		i;
	int		j;
	long	val_i;
	long	val_j;

	i = 0;
	while (nbr[i] != NULL)
	{
		val_i = ft_atol(nbr[i]);
		j = i + 1;
		while (nbr[j] != NULL)
		{
			val_j = ft_atol(nbr[j]);
			if (val_i == val_j)
			{
				ft_print_error();
			}
			j++;
		}
		i++;
	}
}

void	process_in(int argc, char **argv, char ***nbr, t_stack **a)
{
	char	**temp;

	temp = NULL;
	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		if (!temp || !*temp)
			ft_print_error();
		*nbr = temp;
	}
	else
	{
		*nbr = argv + 1;
	}
	check_input(*nbr);
	stack_init(a, *nbr);
	if (argc == 2)
	{
		while (*temp)
		{
			free(*temp);
			temp++;
		}
		free(*nbr);
	}
}
