/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:27:37 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/07/29 16:34:52 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
typedef struct s_stack
{
    int				value;
    struct s_stack	*next;
    struct s_stack	*prev;
}	t_stack;

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>
# include "../get_next_line/get_next_line.h"
# include "../root/push_swap.h"

int			ft_strncmp_bonus(char *s1, char *s2, size_t n);
static void	checker(t_stack **a, t_stack **b, char *ext);
void		print_stack(t_stack *stack, const char *name);
# endif