/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:00:35 by gforns-s          #+#    #+#             */
/*   Updated: 2023/09/02 11:02:34 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//CAMBIAR TODO A NODES

void	print_nodes(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
}

int	count_nodes(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

//FILEAR X NODOS, CREAR UN NODO X CADA VALOR.
//LINKEAR CADA NODO A PREV y NEXT
//SI ES EL PRIMERO QUE SE GUARDE COMO FIRST Y SI ES EL ULTIMO QUE SE GUARDE COMO LAST

t_stack	*fill_stack(char **matrix)
{
	int		i;
	t_stack	*stack;
	t_stack	*stack2;

	i = 0;
	stack = malloc (sizeof(t_stack));
	//free malloc
	stack2 = stack;
	while (matrix[i])
	{
		stack->content = ft_atoi(matrix[i]);
		
		if (matrix[i + 1] == NULL)
			stack->next = NULL;
		else
		{
			stack->next = malloc (sizeof(t_stack));
			stack = stack->next;
		}
		i++;
	}
	return (stack2);
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
			{
				ft_printf("Repited value\n");
				return (1);
			}
		}
		stack = s_move->next;
		s_move = s_move->next;
	}
	return (0);
}

