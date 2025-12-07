/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:24:54 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/24 10:14:02 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_best_top(t_stack *s, int low_val, int high_val)
{
	t_node	*tmp;
	int		pos_top;
	int		best_top;

	tmp = s->head;
	best_top = -1;
	pos_top = 0;
	while (tmp)
	{
		if (tmp->i >= low_val && tmp->i <= high_val)
		{
			best_top = pos_top;
			break ;
		}
		pos_top++;
		tmp = tmp->next;
	}
	return (best_top);
}

int	find_best_bot(t_stack *s, int low_val, int high_val, int size)
{
	t_node	*tmp;
	int		pos_bot;
	int		best_bot;

	pos_bot = size - 1;
	best_bot = -1;
	tmp = s->tail;
	while (tmp)
	{
		if (tmp->i >= low_val && tmp->i <= high_val)
		{
			best_bot = pos_bot;
			break ;
		}
		pos_bot--;
		tmp = tmp->prev;
	}
	return (best_bot);
}

void	handle_push_and_rotate(t_stack *stacka, t_stack *stackb,
		t_max_vars *vars, int *flag)
{
	int	size_b;

	size_b = stack_size(stackb);
	if (!*flag && vars->cost_max_less < vars->cost_max)
	{
		rotate_to_position(stackb, vars->max_less_pos, size_b, 'b');
		pa(stacka, stackb);
		*flag = 1;
	}
	else
	{
		rotate_to_position(stackb, vars->max_pos, size_b, 'b');
		pa(stacka, stackb);
		if (*flag)
			*flag = 0;
	}
}

void	push_max_to_stacka(t_stack *stacka, t_stack *stackb)
{
	t_max_vars	vars;
	static int	flag = 0;

	find_max(stackb, &vars);
	find_max_less(stackb, &vars);
	update_costs(&vars, stack_size(stackb));
	handle_push_and_rotate(stacka, stackb, &vars, &flag);
	check_and_swap(stacka);
}

void	big_sort(t_stack *stacka, t_stack *stackb, int *sorted_arr, int size)
{
	push_range_to_stackb(stacka, stackb, sorted_arr, size);
	while (stack_size(stackb) > 0)
		push_max_to_stacka(stacka, stackb);
}
