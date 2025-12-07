/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:15:09 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/23 17:43:56 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(int *arr, int k)
{
	t_n	x;

	x.a = malloc(sizeof(t_node));
	x.s = malloc(sizeof(t_stack));
	x.s->head = x.a;
	x.i = -1;
	x.tmp = x.a;
	while (++x.i < k)
	{
		x.tmp->i = arr[x.i];
		if (x.i == k - 1)
		{
			x.tmp->next = NULL;
			x.s->tail = x.tmp;
		}
		else
		{
			x.tmp->next = malloc(sizeof(t_node));
			x.tmp->next->prev = x.tmp;
			x.tmp = x.tmp->next;
		}
	}
	return (x.s);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*a;

	if (!stack)
		return ;
	a = stack->head;
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	if (stack)
		free(stack);
}

t_stack	*initialize_stack(void)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	b->head = NULL;
	b->tail = NULL;
	return (b);
}
