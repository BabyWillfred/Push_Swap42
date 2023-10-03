/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:33:40 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/03 16:46:37 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
		push_a(stack_b, stack_a);
	while (find_index(find_min_content(*stack_a), *stack_a) > 0)
		*stack_a = rotate_a(*stack_a);
}

void	sort_3(t_stack **stack_a)
{
	while (check_if_sorted(*stack_a) == NOT_SORTED)
	{
		if ((*stack_a)->content != find_max_content(*stack_a)
			&& (*stack_a)->next->content < (*stack_a)->content)
			*stack_a = swap_a(*stack_a);
		else
			*stack_a = rotate_a(*stack_a);
	}
}

int	repited_value_check(t_stack *stack)
{
	int		content_cpy;
	t_stack	*top;
	t_stack	*s_move;

	top = stack;
	s_move = stack;
	while (s_move->next != NULL)
	{
		content_cpy = s_move->content;
		while (stack->next != NULL)
		{
			stack = stack->next;
			if (stack->content == content_cpy)
				return (1);
		}
		stack = s_move->next;
		s_move = s_move->next;
	}
	return (0);
}

void	apply_moves(t_stack **a, t_stack **b, t_moves mv)
{
	while (mv.ra > 0)
	{
		*a = rotate_a(*a);
		mv.ra--;
	}
	while (mv.rb > 0)
	{
		*b = rotate_b(*b);
		mv.rb--;
	}
	while (mv.rr > 0)
	{
		rotate_rotate(a, b);
		mv.rr--;
	}
	while (mv.rra > 0)
	{
		*a = reverse_rotate_a(*a);
		mv.rra--;
	}
	while (mv.rrb > 0)
	{
		*b = reverse_rotate_b(*b);
		mv.rrb--;
	}
	while (mv.rrr > 0)
	{
		reverse_rotate_rotate(a, b);
		mv.rrr--;
	}
}

t_moves	best_mv(t_stack *stack_a, t_stack *stack_b)
{
	t_moves	aux;
	t_moves	mv;
	int		i;
	int		number_on_b;
	int		index_b;
	int		stack_len;

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
