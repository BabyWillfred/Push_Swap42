/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:00:35 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/05 15:13:07 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack->next;
	while (tmp)
	{
		if (stack->content > tmp->content)
			return (NOT_SORTED);
		stack = stack->next;
		tmp = tmp->next;
	}
	return (SORTED);
}

void	free_malloc_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
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

static t_stack	*fix_my_line(t_stack *stack)
{
	stack->next = malloc(sizeof(t_stack));
	if (!stack->next)
	{
		free_malloc_stack(&stack);
		return (NULL);
	}
	stack = stack->next;
	return (stack);
}

t_stack	*fill_stack(char **matrix)
{
	int		i;
	t_stack	*stack;
	t_stack	*stack2;

	i = 0;
	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		free_malloc_stack(&stack);
		return (NULL);
	}
	stack2 = stack;
	while (matrix[i])
	{
		stack->content = ft_atoi(matrix[i]);
		if (matrix[i + 1] == NULL)
			stack->next = NULL;
		else
			stack = fix_my_line(stack);
		i++;
	}
	return (stack2);
}
