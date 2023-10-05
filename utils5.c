/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:47:03 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/05 12:41:23 by gforns-s         ###   ########.fr       */
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

/*si peta x lo que sea, el i =-1 y el ++i antes era un i++ al final*/
t_moves	best_mv(t_stack *a, t_stack *b, int stack_len, int indx_b)
{
	t_moves	aux;
	t_moves	mv;
	int		i;

	aux.total = INT_MAX;
	i = -1;
	stack_len = count_nodes(a);
	while (a)
	{
		mv = init_moves();
		if (++i > (stack_len / 2))
			mv.rra = stack_len - i;
		else
			mv.ra = i;
		indx_b = find_index(find_max_x_num(a->content, b), b);
		if (indx_b > (count_nodes(b) / 2))
			mv.rrb = count_nodes(b) - indx_b;
		else
			mv.rb = indx_b;
		mv = clac_total(mv);
		if (mv.total < aux.total)
			aux = mv;
		a = a->next;
	}
	return (aux = optim_moves(aux));
}
