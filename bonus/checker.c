/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:21:31 by saroca-f          #+#    #+#             */
/*   Updated: 2024/08/22 09:57:04 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../root/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*current;
	int		len;

	current = stack;
	len = 0;
	while (current != NULL)
	{
		printf("Valor: %d ", current->content);
		printf("Índice: %d\n", current->index);
		len++;
		current = current->next;
	}
	printf("Tamaño del stack: %d\n", len);
}

bool	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2
		&& *str_1)
	{
		++str_1;
		++str_2;
	}
	if (*str_1 || *str_2)
		return (false);
	return (true);
}

void	find_error(t_stack *a, t_stack *b)
{
	free_stack(&a);
	free_stack(&b);
	write(2, "Error\n", 6);
	exit (1);
}

void	order_cheker(char *next_line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(next_line, "pa\n"))
		push(b, a);
	else if (ft_strcmp(next_line, "pb\n"))
		push(a, b);
	else if (ft_strcmp(next_line, "sa\n"))
		swap(a);
	else if (ft_strcmp(next_line, "sb\n"))
		swap(b);
	else if (ft_strcmp(next_line, "ss\n"))
		ss_bonus(a, b);
	else if (ft_strcmp(next_line, "ra\n"))
		rotate(a);
	else if (ft_strcmp(next_line, "rb\n"))
		rotate(b);
	else if (ft_strcmp(next_line, "rr\n"))
		rr_bonus(a, b);
	else if (ft_strcmp(next_line, "rra\n"))
		rrotate(a);
	else if (ft_strcmp(next_line, "rrb\n"))
		rrotate(b);
	else if (ft_strcmp(next_line, "rrr\n"))
		rrr_bonus(a, b);
	else
		find_error(*a, *b);
	free(next_line);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*next_line;
	int			len;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1);
	len = stack_len(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		order_cheker(next_line, &a, &b);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (stack_is_sorted(a) && stack_len(a) == len)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	ft_stack_free_bonus (&a, &b);
	return (0);
}
