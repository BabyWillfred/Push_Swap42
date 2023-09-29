/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:36:09 by gforns-s          #+#    #+#             */
/*   Updated: 2023/09/29 20:58:44 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

# define SORTED 0
# define NOT_SORTED 1

typedef struct s_stack
{
	int				content;
	// int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_moves
{
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_moves;

char				**ft_check_args(int argc, char **argv);
int					count_nodes(t_stack *stack);
t_stack				*swap_a(t_stack *a);
t_stack				*swap_b(t_stack *b);
void				swap_ss(t_stack *a, t_stack *b);
void				push_a(t_stack **b, t_stack **a);
void				push_b(t_stack **b, t_stack **a);
t_stack				*rotate_a(t_stack *a);
t_stack				*rotate_b(t_stack *b);
void				rotate_rotate(t_stack **a, t_stack **b);
t_stack				*fill_stack(char **matrix);
void				print_nodes(t_stack *stack);
int					repited_value_check(t_stack *stack);
t_stack				*general_reverse_rotate(t_stack *stack);
t_stack				*reverse_rotate_a(t_stack *a);
t_stack				*reverse_rotate_b(t_stack *b);
void				reverse_rotate_rotate(t_stack **a, t_stack **b);
int					check_if_sorted(t_stack *stack);
int					sort_algorithm(t_stack **a, t_stack **b);
void				free_malloc_stack(t_stack **stack);
t_moves				best_mv(t_stack *stack_a, t_stack *stack_b);
t_moves				init_moves(void);
void				apply_moves(t_stack **stack_a, t_stack **stack_b, t_moves mv);
int					sort_3(t_stack **stack_a);

int					find_max_x_num(int num, t_stack *b);
int					find_min_content(t_stack *stack);
int					find_index(int num, t_stack *stack);


#endif