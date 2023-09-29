/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:16:29 by gforns-s          #+#    #+#             */
/*   Updated: 2023/09/27 19:15:34 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*general_swap(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack->next;
	stack->next = tmp->next;
	tmp->next = stack;
	return (tmp);
}

t_stack	*swap_a(t_stack *a)
{
	a = general_swap(a);
	ft_printf("sa\n");
	return (a);
}

t_stack	*swap_b(t_stack *b)
{
	b = general_swap(b);
	ft_printf("sb\n");
	return (b);
}

// Call function with &

void	swap_ss(t_stack *a, t_stack *b)
{
	a = general_swap(a);
	b = general_swap(b);
	ft_printf("ss\n");
}
