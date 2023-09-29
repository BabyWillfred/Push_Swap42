/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:34:33 by gforns-s          #+#    #+#             */
/*   Updated: 2023/09/29 16:56:26 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	sort_algorithm(t_stack **a, t_stack **b)
{
	int	i;

	i = count_nodes(a);
	if (i <= 3)
		if ()
		if
	return (0);
}
*/
void	gen_algor(t_stack **stack_a, t_stack **stack_b)
{
	t_moves mv;

	while (*stack_a)
	{
		mv = best_mv(*stack_a, *stack_b);
		apply_moves(stack_a, stack_b, mv);
		push_b(stack_b, stack_a);
	}
	mv = init_moves();
	
	while (*stack_b)
		push_a(stack_b, stack_a);
	while(find_index(find_min_content(*stack_a),*stack_a) > 0)
		*stack_a = rotate_a(*stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**matrix;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
	{
		free_malloc_stack(&stack_a);
		return (write(2, "Error\n", 6));
	}
	if (argc < 2)
		return (write(2, "Error\n", 6));
	else
	{
		matrix = ft_check_args(argc, argv);
		stack_a = fill_stack(matrix);
		if (repited_value_check(stack_a) == 1)
			return (write(2, "Error\n", 6));
		else if (check_if_sorted(stack_a) == NOT_SORTED)
		{			
			push_b(&stack_b, &stack_a);
			push_b(&stack_b, &stack_a);
			gen_algor(&stack_a, &stack_b);
			free_malloc_stack(&stack_a);
			free_malloc_stack(&stack_b);
		}
		// print_nodes(stack_a);
		// ft_printf("----------/n");
		// print_nodes(stack_b);
	}
		free_malloc_stack(&stack_a);
		free_malloc_stack(&stack_b);
	return (0);
}
