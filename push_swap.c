/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:34:33 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/03 15:56:36 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**matrix;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (write(2, "Error\n", 6));
	else
	{
		if (ft_check_args(argc, argv) == 0)
			return (write(2, "Error\n", 6));
		matrix = ft_check_args(argc, argv);
		if (matrix == NULL)
			return (write(2, "Error\n", 6));
		stack_a = fill_stack(matrix);
		if (repited_value_check(stack_a) == 1)
		{
			free_malloc_stack(&stack_a);
			return (write(2, "Error\n", 6));
		}
		else if (check_if_sorted(stack_a) == NOT_SORTED)
			order_func(&stack_a, &stack_b);
	}
	return (0);
}
