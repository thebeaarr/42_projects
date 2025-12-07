/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_help1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:02:13 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/23 16:02:40 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_range_bounds(t_range_vars *r, int size)
{
	r->start = r->start - r->offset;
	if (r->start < 0)
		r->start = 0;
	r->end = r->end + r->offset;
	if (r->end >= size)
		r->end = size - 1;
}

void	push_to_stackb(t_stack *stacka, t_stack *stackb,
		int *sorted_arr, t_range_vars *r)
{
	int	pos;
	int	size_a;

	pos = get_best_pos_in_range(stacka, sorted_arr[r->start],
			sorted_arr[r->end]);
	size_a = stack_size(stacka);
	if (pos == -1)
		return ;
	rotate_to_position(stacka, pos, size_a, 'a');
	pb(stacka, stackb);
	if (stackb->head && stackb->head->i <= sorted_arr[r->mid])
		rb(stackb);
}

void	push_range_to_stackb(t_stack *stacka, t_stack *stackb,
		int *sorted_arr, int size)
{
	t_range_vars	r;
	int				check;

	init_range_vars(&r, size);
	while (stack_size(stacka) > 0)
	{
		push_to_stackb(stacka, stackb, sorted_arr, &r);
		check = get_best_pos_in_range(stacka,
				sorted_arr[r.start], sorted_arr[r.end]);
		if (check == -1)
			update_range_bounds(&r, size);
	}
}

int	get_best_pos_in_range(t_stack *s, int low_val, int high_val)
{
	int	size;
	int	best_top;
	int	best_bot;

	size = stack_size(s);
	best_top = find_best_top(s, low_val, high_val);
	best_bot = find_best_bot(s, low_val, high_val, size);
	return (nichan(best_top, best_bot, size));
}

void	init_range_vars(t_range_vars *r, int size)
{
	r->mid = size / 2 - 1;
	if (size <= 16)
		r->div = size / 2;
	else if (size <= 100)
		r->div = size / 8;
	else if (size < 500)
		r->div = size / 12;
	else
		r->div = size / 28;
	r->offset = size / r->div;
	r->start = r->mid - r->offset;
	if (r->start < 0)
		r->start = 0;
	r->end = r->mid + r->offset;
	if (r->end >= size)
		r->end = size - 1;
}
