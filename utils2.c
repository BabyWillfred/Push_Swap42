/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:07:31 by gforns-s          #+#    #+#             */
/*   Updated: 2023/09/06 12:05:43 by gforns-s         ###   ########.fr       */
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


// Esto busca encima de que numero
int	find_max_x_num(int num, t_stack *stack)
{
	int	i;

	i = INT_MIN;
	if (num < find_min_content(stack))
		return (find_max_content(stack));
	while (stack)
	{
		// menor al numero pero el mayor de todo B
		if (stack->content < num && stack->content > i)
			i = stack->content;
		stack = stack->next;
	}
	return (i);
}

int	find_index(int num, t_stack *stack)
// encontrar un numero y devolver su posicion en el stack
{
	int i;

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

//inicializa mv
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

t_moves	clac_total(t_moves mv)
{
	mv.total = mv.ra + mv.rb + mv.rr + mv.rra + mv.rrb + mv.rrr;
	return (mv);
}


// in b it has to be like 9876 so when pushed to a is 6789

//if new min, push to b on top of max and rotate b to place it down

//we will sort all by the new max, new min or under max number i think
calc lowest move
{
	store moves int

	while a stack exist
	{
		find correct position in b
		find amount of moves needed
		store the amount and position of number index a stack
	}
	return (index with less moves)
}