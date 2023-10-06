/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:07:31 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/06 12:40:22 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_content(t_stack *stack)
{
	int	holder;

	holder = INT_MAX;
	while (stack)
	{
		if (stack->content < holder)
			holder = stack->content;
		stack = stack->next;
	}
	return (holder);
}

int	find_max_content(t_stack *stack)
{
	int	holder;

	holder = INT_MIN;
	while (stack)
	{
		if (stack->content > holder)
			holder = stack->content;
		stack = stack->next;
	}
	return (holder);
}

/* Serch correct position for number at stack, if new min,
return max as a index
Else, if stack->content is smaller than num & stack->content > than i 
(i being old stack->content) replace i with new content bigger than last 
but smaller that num we are searching.
Then returns the number so when we apply find_index we will get its index.
*/

int	find_max_x_num(int num, t_stack *stack)
{
	int	i;

	i = INT_MIN;
	if (num < find_min_content(stack))
		return (find_max_content(stack));
	while (stack)
	{
		if (stack->content < num && stack->content > i)
			i = stack->content;
		stack = stack->next;
	}
	return (i);
}

/* find num and return stack position*/
int	find_index(int num, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content == num)
			return (i);
		stack = stack->next;
		i++;
	}
	return (0);
}

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1. The first element becomes 
the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1. The last 
element becomes the first one.

rrr : rra and rrb at the same time.
*/

t_moves	init_moves(void)
{
	t_moves	moves;

	moves.ra = 0;
	moves.rb = 0;
	moves.rr = 0;
	moves.rra = 0;
	moves.rrb = 0;
	moves.rrr = 0;
	moves.total = INT_MAX;
	return (moves);
}
