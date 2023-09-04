/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:17:21 by gforns-s          #+#    #+#             */
/*   Updated: 2023/09/04 12:29:09 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	general_push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*tmp;

	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	tmp->next = *stack_to;
	*stack_to = tmp; 
}

void	push_a(t_stack **b, t_stack **a)
{
	general_push(a, b);
	ft_printf("pa\n");
}

void	push_b(t_stack **b, t_stack **a)
{
	general_push(b, a);
	ft_printf("pb\n");
}
