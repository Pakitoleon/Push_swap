/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:27:37 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/08/22 11:00:01 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>
# include "../get_next_line/get_next_line_bonus.h"
# include "../root/push_swap.h"

void		order_cheker(char *next_line, t_stack **a, t_stack **b);
void		print_stack_bonus(t_stack *stack, const char *name);
int			ft_strncmp_bonus(char *s1, char *s2, size_t n);
void		print_stack_bonus(t_stack *stack, const char *name);
void		process_input(int argc, char **argv, char ***nbr, t_stack **a);
void		ft_stack_free_bonus(t_stack **stack, t_stack **stack2);
void		push(t_stack **origin, t_stack **target);
void		rotate(t_stack **stack);
void		rrotate(t_stack **stack);
void		swap(t_stack **stack);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
#endif