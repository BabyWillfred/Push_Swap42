/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:34:33 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/03 13:36:38 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gen_algor(t_stack **stack_a, t_stack **stack_b)
{
	t_moves mv;
	int		i;

	i = count_nodes(*stack_a);
	while (*stack_a)
	{
		mv = best_mv(*stack_a, *stack_b);
		apply_moves(stack_a, stack_b, mv);
		push_b(stack_b, stack_a);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**matrix;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		return (write(2, "Error\n", 6));
	}
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
		{
			if (count_nodes(stack_a) <= 3)
			{
				sort_3(&stack_a);

				finish_sort(&stack_a, &stack_b);
				return (0);
			}
			else if (count_nodes(stack_a) <= 5)
			{
				int	iter;
				while (count_nodes(stack_a) > 3)
					{
						iter = low_index(stack_a);
						if (iter == 3)
						{
							stack_a = reverse_rotate_a(stack_a);
							stack_a = reverse_rotate_a(stack_a);
						}
						else if (iter == 4)
						{
							stack_a = reverse_rotate_a(stack_a);
						}
						else
						{
							while (iter > 0)
							{
								stack_a = rotate_a(stack_a);
								iter--;
							}
							push_b(&stack_b, &stack_a);
						}
					}
				sort_3(&stack_a);
				finish_sort(&stack_a, &stack_b);
			}
			
			else
			{
				push_b(&stack_b, &stack_a);
				push_b(&stack_b, &stack_a);
				gen_algor(&stack_a, &stack_b);
				finish_sort(&stack_a, &stack_b);
			}
			free_malloc_stack(&stack_a);
		}
	}
	return (0);
}


//LISTA ERRORES ENCONTRDOS
// doble -- con numero sigue trabajando en vez de parar.