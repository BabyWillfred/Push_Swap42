/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:34:33 by gforns-s          #+#    #+#             */
/*   Updated: 2023/09/04 12:11:39 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**matrix;
	int		z;

	a = NULL;
	b = NULL;

	a = malloc(sizeof (t_stack));
		//maloc falla limpiar
	if (argc < 2) 
		return (write(2, "ERROR\n", 6));
	else
	{
		matrix = ft_check_args(argc, argv);
		a = fill_stack(matrix);
		b = fill_stack(matrix);
		z = repited_value_check(a);
		ft_printf("---Print A---\n");
		print_nodes(a);
		ft_printf("---Print B----\n");
		print_nodes(b);
		ft_printf("\n");
		ft_printf("\n");
		// /*next 2 lines are test*/
		// ft_printf("--PB--\n");
		// push_b(&b, &a);
		// ft_printf("----A----\n");
		// print_nodes(a);
		// ft_printf("----B-----\n");
		// print_nodes(b);
		// ft_printf("\n");
		// ft_printf("\n");
		// /*next 2 lines are test*/
		// ft_printf("--SA--\n");
		// a = swap_a(a);
		// ft_printf("----A----\n");
		// print_nodes(a);
		// ft_printf("----B-----\n");
		// print_nodes(b);
		// ft_printf("\n");
		// ft_printf("\n");
		// 		/*next 2 lines are test*/
		// ft_printf("--RA--\n");
		// a = rotate_a(a);
		// ft_printf("----A----\n");
		// print_nodes(a);
		// ft_printf("----B-----\n");
		// print_nodes(b);
		// ft_printf("\n");
		// ft_printf("\n");
		// 				/*next 2 lines are test*/
		// ft_printf("--RR--\n");
		// rotate_rotate(&a, &b);
		// ft_printf("----A----\n");
		// print_nodes(a);
		// ft_printf("----B-----\n");
		// print_nodes(b);
		// ft_printf("\n");
		// ft_printf("\n");
								/*next 2 lines are test*/
		ft_printf("--RRA--\n");
		a = reverse_rotate_a(a);
		ft_printf("----A----\n");
		print_nodes(a);
		ft_printf("----B-----\n");
		print_nodes(b);
		ft_printf("\n");
		ft_printf("\n");
								/*next 2 lines are test*/
		ft_printf("--RRR--\n");
		reverse_rotate_rotate(&a, &b);
		ft_printf("----A----\n");
		print_nodes(a);
		ft_printf("----B-----\n");
		print_nodes(b);
		ft_printf("\n");
		ft_printf("\n");
	}
	return (0);
}
