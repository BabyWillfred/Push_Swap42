/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:07:31 by gforns-s          #+#    #+#             */
/*   Updated: 2023/09/04 17:18:49 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


algorithm for 3

if (a->content > a->next->content && a->next->content != max)
	RA

algorithm for 5

algorithm general




int	find_max_content(t_stack *stack)
{
	int	holder;

	holder = INT_MIN;
	while (stack->next != NULL)
	{
		if (stack->content > holder)
			holder = stack->content;
		stack = stack->next;
	}
	return (holder);
}

int	find_min_content(t_stack *stack)
{
	int	holder;

	holder = INT_MAX;
	while (stack->next != NULL)
	{
		if (stack->content < holder)
			holder = stack->content;
		stack = stack->next;
	}
	return (holder);
}
