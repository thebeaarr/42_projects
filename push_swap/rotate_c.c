/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:09:33 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/23 18:17:00 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	first = stack->head;
	stack->head = first->next;
	stack->head->prev = NULL;
	stack->tail->next = first;
	first->prev = stack->tail;
	first->next = NULL;
	stack->tail = first;
}

void	ra(t_stack *a)
{
	rotate(a);
}

void	rb(t_stack *b)
{
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}
