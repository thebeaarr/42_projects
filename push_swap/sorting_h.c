/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:55:39 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/24 09:42:20 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_index(t_stack *a)
{
	int		min;
	int		index;
	t_node	*current;

	min = get_min(a);
	index = 0;
	current = a->head;
	while (current)
	{
		if (current->i == min)
			break ;
		index++;
		current = current->next;
	}
	return (index);
}

static void	smart_rotate(t_stack *a, int target_index)
{
	int	size;

	size = stack_size(a);
	if (target_index <= size / 2)
	{
		while (target_index-- > 0)
			ra(a);
	}
	else
	{
		target_index = size - target_index;
		while (target_index-- > 0)
			rra(a);
	}
}

static void	move_min_to_b(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = get_min_index(a);
	smart_rotate(a, min_index);
	pb(a, b);
}

void	sort_4(t_stack *a, t_stack *b)
{
	move_min_to_b(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	if (stack_size(a) == 5)
	{
		move_min_to_b(a, b);
		sort_4(a, b);
		pa(a, b);
	}
	else
		sort_4(a, b);
}
