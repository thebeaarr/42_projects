/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:55:07 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/23 15:40:06 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_rotate_a(t_stack *stack, int pos, int size)
{
	int	rotations;

	if (pos <= size / 2)
	{
		while (pos--)
			ra(stack);
	}
	else
	{
		rotations = size - pos;
		while (rotations--)
			rra(stack);
	}
}

void	handle_rotate_b(t_stack *stack, int pos, int size)
{
	int	rotations;

	if (pos <= size / 2)
	{
		while (pos--)
			rb(stack);
	}
	else
	{
		rotations = size - pos;
		while (rotations--)
			rrb(stack);
	}
}

void	check_and_swap(t_stack *stacka)
{
	if (stacka->head && stacka->head->next
		&& stacka->head->i > stacka->head->next->i)
		sa(stacka);
}
