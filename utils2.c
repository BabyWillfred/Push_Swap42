/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:07:31 by gforns-s          #+#    #+#             */
/*   Updated: 2023/09/05 19:57:27 by gforns-s         ###   ########.fr       */
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

void	adri_de_los_cojones(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		ft_printf("NODE: %i\n", i);
		ft_printf("CONTENT: %i\n", stack->content);
		ft_printf("QTTRA: %i\n", i);
		ft_printf("\n");
		stack = stack->next;
		i++;
	}
}


//Esto busca encima de que numero
int	find_max_x_num(int num, t_stack *stack)
{
	int		i;

	i = INT_MIN;
	if (num < find_min_content(stack))
		return (find_max_content(stack));
	while (stack)
	{
		//menor al numero pero el mayor de todo B
		if (stack->content < num && stack->content > i)
			i = stack->content;
		stack = stack->next;
	}
	return (i);
}


int find_index(int num, t_stack *stack)  //encontrar un numero y devolver su posicion en el stack
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





/*
algorithm for 3

if (a->content > a->next->content && a->next->content != max)
	RA

algorithm for 5

algorithm general






int	find_min_content(t_stack *stack)
{
	int	holder;

	holder = INT_MAX;
	while (stack->next != NULL)
	{
		if (stack->content < holder)
			holder = stack->content;
		stack = stack->next;
	}
	return (holder);
}






counters x all movement
2 push to b
check the amount of movements per position on A to send them to B
being the closes to the B-content from bottom ( 8 being smaller than 9 etc)

saving in 2 variables the best one posible, if the actual number of movements
is worse than the movements we have on the new number, replace it.







i = 0;

while (stack)
{
	ft_printf("NODE: %i\n", i);
	ft_printf("CONTENT: %i\n", stack->content);
	ft_printf("QTTRA: %i\n", i);

	stack = stack->next;
	i++;
}

*/