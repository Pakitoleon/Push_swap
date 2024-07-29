/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:00:48 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/07/22 11:14:17 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../root/push_swap.h"

int	ft_strlen_fd(const char *str)
{
	int		count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = ft_strlen_fd(s);
	write(fd, s, i);
}

long	ft_atol(char *str)
{
	long	i;
	long	negative;
	long	result;
	int		j;

	i = 0;
	negative = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	j = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] || j == i)
		ft_print_error();
	return (result * negative);
}
