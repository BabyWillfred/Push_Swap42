/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:32:50 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/05 12:28:04 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	low_index(t_stack *stack)
{
	int	holder;

	holder = find_min_content(stack);
	holder = find_index(holder, stack);
	return (holder);
}

void	order_func(t_stack **stack_a, t_stack **stack_b)
{
	if (count_nodes(*stack_a) <= 3)
		algor_3(stack_a, stack_b);
	else if (count_nodes(*stack_a) <= 5)
		algor_5(stack_a, stack_b);
	else
		gen_algor(stack_a, stack_b);
	free_malloc_stack(stack_a);
}

void	algor_3(t_stack **stack_a, t_stack **stack_b)
{
	sort_3(stack_a);
	finish_sort(stack_a, stack_b);
}

void	algor_5(t_stack **stack_a, t_stack **stack_b)
{
	int	iter;

	while (count_nodes(*stack_a) > 3)
	{
		iter = low_index(*stack_a);
		if (iter == 3)
		{
			*stack_a = reverse_rotate_a(*stack_a);
			*stack_a = reverse_rotate_a(*stack_a);
		}
		else if (iter == 4)
			*stack_a = reverse_rotate_a(*stack_a);
		else
		{
			while (iter > 0)
			{
				*stack_a = rotate_a(*stack_a);
				iter--;
			}
			push_b(stack_b, stack_a);
		}
	}
	sort_3(stack_a);
	finish_sort(stack_a, stack_b);
}

void	gen_algor(t_stack **stack_a, t_stack **stack_b)
{
	t_moves	mv;
	int		i;
	int		stack_len;
	int		index_b;

	index_b = 0;
	stack_len = 0;
	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
	i = count_nodes(*stack_a);
	while (*stack_a)
	{
		mv = best_mv(*stack_a, *stack_b, stack_len, index_b);
		apply_moves(stack_a, stack_b, mv);
		push_b(stack_b, stack_a);
	}
	finish_sort(stack_a, stack_b);
}
