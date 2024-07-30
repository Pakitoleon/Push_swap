/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:27:37 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/07/30 16:09:58 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>
# include "../get_next_line/get_next_line.h"
# include "../root/push_swap.h"

void		print_stack_bonus(t_stack *stack, const char *name);
int			ft_strncmp_bonus(char *s1, char *s2, size_t n);
void		print_stack_bonus(t_stack *stack, const char *name);
int			stack_is_sorted_bonus(t_stack *stack);
void ft_stack_free_bonus(t_stack **stack, t_stack **stack2);
//int 		ft_stack_size_bonus(t_stack *stack);
# endif