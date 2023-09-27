/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:34:33 by gforns-s          #+#    #+#             */
/*   Updated: 2023/09/27 19:07:02 by gforns-s         ###   ########.fr       */
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
	t_stack	*a;
	t_stack	*b;
	char	**matrix;

	a = NULL;
	b = NULL;
	a = malloc(sizeof(t_stack));
	// maloc falla limpiar
	if (argc < 2)
		return (write(2, "Error\n", 6));
	else
	{
		matrix = ft_check_args(argc, argv);
		a = fill_stack(matrix);
		if (repited_value_check(a) == 1)
			return (write(2, "Error\n", 6));
		else if (check_if_sorted(a) == NOT_SORTED)
		{			
			push_b(&b, &a);
			push_b(&b, &a);
			gen_algor(&a, &b);
		}
		print_nodes(a);
		ft_printf("-------\n");
		print_nodes(b);
	}
	return (0);
}
