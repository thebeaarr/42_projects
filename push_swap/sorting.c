/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:25:40 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/23 15:41:21 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *a)
{
	if (a->head->i > a->head->next->i)
		sa(a);
}

void	sort_3(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->head->i;
	mid = a->head->next->i;
	bot = a->tail->i;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		rra(a);
		sa(a);
	}
	else if (top < mid && mid > bot)
		rra(a);
}
