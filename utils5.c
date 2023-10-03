/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:47:03 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/03 18:59:27 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	optim_moves(t_moves mv)
{
	if (mv.ra >= mv.rb)
	{
		mv.ra = mv.ra - mv.rb;
		mv.rr = mv.rb;
		mv.rb = 0;
	}
	else if (mv.rb > mv.ra)
	{
		mv.rb = mv.rb - mv.ra;
		mv.rr = mv.ra;
		mv.ra = 0;
	}
	if (mv.rra >= mv.rrb)
	{
		mv.rra = mv.rra - mv.rrb;
		mv.rrr = mv.rrb;
		mv.rrb = 0;
	}
	else if (mv.rrb > mv.rra)
	{
		mv.rrb = mv.rrb - mv.rra;
		mv.rrr = mv.rra;
		mv.rra = 0;
	}
	return (mv);
}

t_moves	clac_total(t_moves mv)
{
	mv.total = mv.ra + mv.rb + mv.rr + mv.rra + mv.rrb + mv.rrr;
	return (mv);
}

t_moves	best_mv(t_stack *stack_a, t_stack *stack_b, int stack_len)
{
	t_moves	aux;
	t_moves	mv;
	int		i;
	int		number_on_b;
	int		index_b;

	aux.total = INT_MAX;
	i = 0;
	stack_len = count_nodes(stack_a);
	while (stack_a)
	{
		mv = init_moves();
		if (i > (stack_len / 2))
			mv.rra = stack_len - i;
		else
			mv.ra = i;
		number_on_b = find_max_x_num(stack_a->content, stack_b);
		index_b = find_index(number_on_b, stack_b);
		if (index_b > (count_nodes(stack_b) / 2))
			mv.rrb = count_nodes(stack_b) - index_b;
		else
			mv.rb = index_b;
		mv = clac_total(mv);
		if (mv.total < aux.total)
			aux = mv;
		stack_a = stack_a->next;
		i++;
	}
	aux = optim_moves(aux);
	return (aux);
}
