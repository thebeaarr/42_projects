/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:10:58 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/23 18:17:21 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	t_node	*top;

	if (!from || !from->head)
		return ;
	top = from->head;
	from->head = top->next;
	if (from->head)
		from->head->prev = NULL;
	else
		from->tail = NULL;
	top->next = to->head;
	if (to->head)
		to->head->prev = top;
	else
		to->tail = top;
	to->head = top;
	top->prev = NULL;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
}
