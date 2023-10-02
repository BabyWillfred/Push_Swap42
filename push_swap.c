/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:34:33 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/02 19:41:41 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	finish_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	while (*stack_b)
// 		push_a(stack_b, stack_a);
// 	while(find_index(find_min_content(*stack_a),*stack_a) > 0)
// 		*stack_a = rotate_a(*stack_a);
// }
// void 	sort_3(t_stack **stack_a)
// {
// 	while (check_if_sorted(*stack_a) == NOT_SORTED)
// 	{
// 		if ((*stack_a)->content != find_max_content(*stack_a) &&
// 			(*stack_a)->next->content < (*stack_a)->content)
// 				*stack_a = swap_a(*stack_a);
// 		else
// 			*stack_a = rotate_a(*stack_a);
// 	}
// }

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
	// stack_a = malloc(sizeof(t_stack));
	// if (!stack_a)
	// {
	// 	free_malloc_stack(&stack_a);
	// 	return (write(2, "Error\n", 6));
	// }
	if (argc < 2)
	{
		return (write(2, "Error\n", 6));
	}
	else
	{
		if (ft_check_args(argc, argv) == 0)
			return (write(2, "Error\n", 6));
		matrix = ft_check_args(argc, argv);
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
				//print_nodes(stack_a);
				return (0);
			}
			else if (count_nodes(stack_a) == 4)
			{
			
			}

			else if (count_nodes(stack_a) == 5)
			{
			
			}
			
			else
			{
				push_b(&stack_b, &stack_a);
				push_b(&stack_b, &stack_a);
				gen_algor(&stack_a, &stack_b);
				finish_sort(&stack_a, &stack_b);
			//print_nodes(stack_a);
			//ft_printf("----------/n");
				//free_malloc_stack(&stack_a);
			///////////free_malloc_stack(&stack_b);
			}
			free_malloc_stack(&stack_a);
		}
		// print_nodes(stack_b);
	}
	return (0);
}
