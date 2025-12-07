/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:48:58 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/23 16:09:41 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_position(t_stack *stack, int pos, int size, char a)
{
	if (a == 'a')
		handle_rotate_a(stack, pos, size);
	else
		handle_rotate_b(stack, pos, size);
}

int	nichan(int best_top, int best_bot, int size)
{
	if (best_top == -1 && best_bot == -1)
		return (-1);
	if (best_top == -1)
		return (best_bot);
	if (best_bot == -1)
		return (best_top);
	if (best_top <= (size - best_bot))
		return (best_top);
	return (best_bot);
}

void	find_max(t_stack *stackb, t_max_vars *vars)
{
	int		pos;
	t_node	*tmp;

	pos = 0;
	tmp = stackb->head;
	vars->max = tmp->i;
	vars->max_pos = 0;
	while (tmp)
	{
		if (tmp->i > vars->max)
		{
			vars->max = tmp->i;
			vars->max_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
}

void	find_max_less(t_stack *stackb, t_max_vars *vars)
{
	int		pos;
	t_node	*tmp;

	pos = 0;
	tmp = stackb->head;
	vars->max_less = tmp->i;
	vars->max_less_pos = 0;
	while (tmp)
	{
		if (tmp->i < vars->max && tmp->i > vars->max_less)
		{
			vars->max_less = tmp->i;
			vars->max_less_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
}

void	update_costs(t_max_vars *vars, int size_b)
{
	if (vars->max_pos <= size_b / 2)
		vars->cost_max = vars->max_pos;
	else
		vars->cost_max = size_b - vars->max_pos;
	if (vars->max_less_pos <= size_b / 2)
		vars->cost_max_less = vars->max_less_pos;
	else
		vars->cost_max_less = size_b - vars->max_less_pos;
}
