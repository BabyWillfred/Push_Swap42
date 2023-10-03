/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:07:31 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/03 16:50:56 by gforns-s         ###   ########.fr       */
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

/* Esto busca encima de que numero*/
int	find_max_x_num(int num, t_stack *stack)
{
	int	i;

	i = INT_MIN;
	if (num < find_min_content(stack))
		return (find_max_content(stack));
	while (stack)
	{
		/* menor al numero pero el mayor de todo B*/
		if (stack->content < num && stack->content > i)
			i = stack->content;
		stack = stack->next;
	}
	/* devuelve el numero que aplicando el find_index nos dira
	 cuantos ra o rb o rr ha de hacer*/
	return (i);
}

/*// encontrar un numero y devolver su posicion en el stack*/
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
inicializa mv

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

/*
// in b it has to be like 9876 so when pushed to a is 6789

// if new min, push to b on top of max and rotate b to place it down

// we will sort all by the new max, new min or under its bigger number i think

sabiendo en que indice esta cada elemento,
	al aplicar find_max_x_num tendremos la posicion del indice correcto en b
y calcularemos cuantos movimientos hacen falta para mover el numero al lugar correcto.
*/