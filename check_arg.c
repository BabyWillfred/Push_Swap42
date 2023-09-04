/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:47:48 by gforns-s          #+#    #+#             */
/*   Updated: 2023/08/21 16:12:57 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (argv[0] == '-' || argv[0] == '+'
		|| (argv[0] >= '0' && argv[0] <= '9'))
	{
		while (argv[i] != '\0')
		{
			z = ft_isdigit(argv[i]);
			if (z == 0)
				return (write(2, "ERROR FT_ISDIGIT REURNED FALSE\n", 32));
			i++;
		}
	}
	else
		return (0);
	if (ft_check_max_min(argv) == 0)
		return (0);
	return (1);
}



/* &argv[1] = to memory directon of arguments */

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
	}
	else if (argc > 2)
		matrix = &argv[1];
	while (matrix[x])
	{
		z = ft_check_arg_is_num(matrix[x]);
		if (z == 1)
			ft_printf("all ok on arg is num matrix: %d\n", x);
		else
		{
			ft_printf("ERROR on arg is num matrix: %d\n", x);
			return (0);
		}
		x++;
	}
	return (matrix);
}


