/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:07:31 by gforns-s          #+#    #+#             */
/*   Updated: 2023/09/29 15:47:58 by gforns-s         ###   ########.fr       */
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
	//devuelve el numero, que aplicando el find_index nos dira cuantos ra o rb o rr ha de hacer 
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
/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

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

t_moves	clac_total(t_moves mv)
{
	mv.total = mv.ra + mv.rb + mv.rr + mv.rra + mv.rrb + mv.rrr;
	return (mv);
}


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
	return (mv);
}


// in b it has to be like 9876 so when pushed to a is 6789

//if new min, push to b on top of max and rotate b to place it down

//we will sort all by the new max, new min or under its bigger number i think


/*sabiendo en que indice esta cada elemento, al aplicar find_max_x_num tendremos la posicion del indice correcto en b
y calcularemos cuantos movimientos hacen falta para mover el numero al lugar correcto.
*/

t_moves	best_mv(t_stack *stack_a, t_stack *stack_b)
{

	t_moves	aux;
	t_moves	mv;
	int i;
	int	number_on_b;
	
	aux.total = INT_MAX;
	i = 0;
	mv = init_moves();
	while (stack_a)
	{
		mv.ra = i;
		number_on_b = find_max_x_num(stack_a->content, stack_b);
		mv.rb = find_index(number_on_b, stack_b);
		mv = clac_total(mv);
		if (mv.total < aux.total)
			aux = mv;
		stack_a = stack_a->next;
		i++;
	}
	aux = optim_moves(aux);
	return (aux);
}

void	apply_moves(t_stack **stack_a, t_stack **stack_b, t_moves mv)
{
	while (mv.ra > 0)
	{
		*stack_a = rotate_a(*stack_a);
		mv.ra--;
	}
	while (mv.rb > 0)
	{
		*stack_b = rotate_b(*stack_b);
		mv.rb--;
	}
	while (mv.rr > 0)
	{
		rotate_rotate(stack_a, stack_b);
		mv.rr--;
	}
}


