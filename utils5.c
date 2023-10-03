/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:47:03 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/03 16:50:28 by gforns-s         ###   ########.fr       */
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
