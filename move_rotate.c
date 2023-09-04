/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:16:56 by gforns-s          #+#    #+#             */
/*   Updated: 2023/08/28 16:07:40 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*general_rotate(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (stack->next != NULL)
		stack = stack->next;
	stack->next = tmp;
	stack = tmp->next;
	tmp->next = NULL;
	return (stack);
}

t_stack	*rotate_a(t_stack *a)
{
	a = general_rotate(a);
	ft_printf("ra\n");
	return (a);
}

t_stack	*rotate_b(t_stack *b)
{
	b = general_rotate(b);
	ft_printf("ra\n");
	return (b);
}

//Call function with &

void	rotate_rotate(t_stack **a, t_stack **b)
{
	*a = general_rotate(*a);
	*b = general_rotate(*b);
	ft_printf("rr\n");
}
