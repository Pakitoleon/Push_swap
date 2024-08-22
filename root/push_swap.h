/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:16:30 by @fgonzal2         #+#    #+#             */
/*   Updated: 2024/08/22 09:53:41 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				nbr;
	int				content;
	int				index;
	int				cost;
	int				half;
	int				is_upper;
	int				is_down;
	int				is_mid;
	struct s_stack	*nbr_push;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*sort;
	struct s_stack	*target;

}	t_stack;

int			ft_strlen_ps(const char *s);
void		ft_putstr_fd(char *s, int fd);
long		ft_atol(char *str);
int			ft_find_index(t_stack *a, int nbr);
int			ft_find_place_b(t_stack *stack_b, int nbr_push);
int			ft_find_place_a(t_stack *stack_a, int nbr_push);
void		ft_stack_free(t_stack **stack);
void		free_array(char **arr);
void		stack_clear(t_stack **a);
void		ft_print_error(void);
int			mx(int x, int y);
char		*ft_strdup(char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
int			help_split(char const *s, char c);
void		leak_split(char **result, int j);
void		position_split( char const *s, int *start, int *end, char c);
int			ft_stack_size(t_stack *stack);
t_stack		*ft_min(t_stack *stack);
t_stack		*ft_max(t_stack *stack);
t_stack		*stack_last_node(t_stack *stack);
void		stack_a_target(t_stack *a, t_stack *b);
void		stack_b_target(t_stack *a, t_stack *b);
void		cost_calculator(t_stack *a, t_stack *target, int c_len, int d_len);
t_stack		*stack_cost(t_stack *a, t_stack *b);
void		push(t_stack **origin, t_stack **target);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		rrotate(t_stack **stack);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		rrr_bonus(t_stack **a, t_stack **b);
void		rotate(t_stack **stack);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rr_bonus(t_stack **a, t_stack **b);
void		swap(t_stack **stack);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		ss_bonus(t_stack **a, t_stack **b);
void		check_input(char **nbr);
void		process_in(int argc, char **argv, char ***nbr, t_stack **a);
int			main(int argc, char **argv);
void		complete_b( t_stack **a, t_stack **b, t_stack *move);
void		look_position(t_stack **a, t_stack *move);
void		sort_out_b(t_stack **a, t_stack **b);
void		biggest_sort(t_stack **a, t_stack **b);
void		stack_add(t_stack **a, int n);
void		stack_init(t_stack **a, char **nbr);
int			limits_stack(int *min, int *max, t_stack *stack);
void		sort_tree(t_stack **stack);
void		sort_stack(t_stack **a, t_stack **b);
int			stack_is_sorted(t_stack *stack);
void		top_node_a(t_stack *node, t_stack **stack);
void		top_node_b(t_stack *node, t_stack **stack);
void		stack_index_side(t_stack *stack);
t_stack		*stack_set_structure(t_stack *a, t_stack *b);
void		free_nbr(char ***nbr);
void		free_split(char ***result);
char		**ft_split(char const *s, char c);
int			stack_len(t_stack *stack);
char		*get_next_line(int fd);
void		order_cheker(char *next_line, t_stack **a, t_stack **b);
int			stack_len(t_stack *stack);
int			stack_sorted(t_stack **a);
void		ft_stack_free_bonus(t_stack **a, t_stack **b);
#endif