/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:47:48 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/03 18:36:43 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_matrix_size(char **matrix)
{
	int	size;

	size = 0;
	while (matrix[size] != NULL)
		size++;
	return (size);
}

static void	free_char(char **s2, int k)
{
	while (k >= 0)
	{
		free(s2[k]);
		k--;
	}
	free(s2);
}

long	ft_check_max_min(char *argv)
{
	long	result;
	long	sign;
	int		i;

	result = 0;
	i = 0;
	sign = 1;
	if (argv[0] == '-' || argv[0] == '+')
	{
		if (argv[0] == '-')
			sign = -1;
		i++;
	}
	if (argv[i] == '\0')
		return (0);
	while (argv[i])
	{
		result = result * 10 + argv[i] - '0';
		i++;
	}
	result = sign * result;
	if (result > INT_MAX || result < INT_MIN)
		return (0);
	return (1);
}

int	ft_check_arg_is_num(char *argv)
{
	int	z;
	int	i;

	z = 0;
	i = 1;
	if (argv[0] == '-' || argv[0] == '+' || (argv[0] >= '0' && argv[0] <= '9'))
	{
		while (argv[i] != '\0')
		{
			z = ft_isdigit(argv[i]);
			if (z == 0)
				return (0);
			i++;
		}
	}
	else
		return (0);
	if (ft_check_max_min(argv) == 0)
		return (0);
	return (1);
}

/* &argv[1] = to memory directon of arguments | 
also needed to free only for argc 2 because
 was trying to free argv itself */

char	**ft_check_args(int argc, char **argv)
{
	int		x;
	char	**matrix;
	int		z;

	matrix = NULL;
	x = 0;
	if (argc == 2)
	{
		matrix = ft_split(argv[1], ' ');
		 if (matrix[x] == 0)
		 	return (NULL);
	}
	else if (argc > 2)
		matrix = &argv[1];
	while (matrix[x])
	{
		z = ft_check_arg_is_num(matrix[x]);
		if (z == 0)
		{
			if (argc == 2)
				free_char(matrix, calc_matrix_size(matrix) - 1);
			return (NULL);
		}
		x++;
	}
	return (matrix);
}
