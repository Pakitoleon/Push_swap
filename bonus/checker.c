/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:03:00 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/07/30 16:29:20 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp_bonus(char *s1, char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static char	*gnlrot(t_stack *a, t_stack *b, char *ext)
{
	if (!ft_strncmp_bonus(ext, "ra\n", 3))
		rotate(&a);
	else if (!ft_strncmp_bonus(ext, "rb\n", 3))
		rotate(&b);
	else if (!ft_strncmp_bonus(ext, "rr\n", 3))
	{
		rotate(&a);
		rotate(&b);
	}
	else if (!ft_strncmp_bonus(ext, "rra\n", 4))
		rrotate(&a);
	else if (!ft_strncmp_bonus(ext, "rrb\n", 4))
		rrotate(&b);
	else if (!ft_strncmp_bonus(ext, "rrr\n", 4))
	{
		rrotate(&a);
		rrotate(&b);
	}
	else
		free(ext);
	ft_print_error();
	return (get_next_line(0));
}

static char	*mov(t_stack **a, t_stack **b, char *ext)
{
	if (!ft_strncmp_bonus(ext, "pa\n", 3))
		push(b, a);
	else if (!ft_strncmp_bonus(ext, "pb\n", 3))
		push(a, b);
	else if (!ft_strncmp_bonus(ext, "sa\n", 3))
		swap(a);
	else if (!ft_strncmp_bonus(ext, "sb\n", 3))
		swap(b);
	else if	(!ft_strncmp_bonus(ext, "ss\n", 3))
	{
		swap(a);
		swap(b);
	}
	else if (!gnlrot(*a, *b, ext));
	else
		free(ext);
	return (get_next_line(0));
}

int	main(int argc, char **argv)
{
	char	**nbr;
	t_stack	*a;
	t_stack	*b;
	char	*ext;

	a = NULL;
	b = NULL;
	nbr = 0;
	if (argc > 1)
	{
		process_in(argc, argv, &nbr, &a);
		while ((ext = get_next_line(0)))
		{
			if (!mov(&a, &b, ext))
			free(ext);
    	}
    	if (stack_is_sorted_bonus(a))
			write(1, "ok\n", 3);
		else
			write(1, "ko\n", 3);
		free_array(nbr);
		ft_stack_free_bonus(&a, &b);
	}
	return (0);
}
