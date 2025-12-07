/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:27:06 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/23 16:10:47 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		size;
	t_node	*current;

	size = 0;
	current = stack->head;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	get_min(t_stack *stack)
{
	int		min;
	t_node	*current;

	min = INT_MAX;
	current = stack->head;
	while (current)
	{
		if (current->i < min)
			min = current->i;
		current = current->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int		max;
	t_node	*current;

	max = INT_MIN;
	current = stack->head;
	while (current)
	{
		if (current->i > max)
			max = current->i;
		current = current->next;
	}
	return (max);
}
