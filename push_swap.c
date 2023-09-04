/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:34:33 by gforns-s          #+#    #+#             */
/*   Updated: 2023/09/04 13:52:18 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_algorithm(t_stack **a, t_stack **b)
{


	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**matrix;

	a = NULL;
	b = NULL;
	a = malloc(sizeof (t_stack));
		//maloc falla limpiar
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
			sort_algorithm(&a, &b)
		}

	}
	return (0);
}
