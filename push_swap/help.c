/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:03:21 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/24 10:14:43 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(int *ar, t_stack *stacka, t_stack *stackb)
{
	if (ar)
		free(ar);
	if (stacka)
		free(stacka);
	if (stackb)
		free(stackb);
	write(2, "Error\n", 6);
	exit(1);
}

void	process_input(int ac, char **av, int *k, int **ar)
{
	if (ac < 2)
		exit(0);
	if (av[1][0] == '\0')
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	*ar = parse_input(ac, av, k);
	check_for_duplicates(*ar,*k);
}

void	clean_exit(t_stack *stacka, t_stack *stackb, char *f)
{
	if (stacka)
		free_stack(stacka);
	if (stackb)
		free_stack(stackb);
	if (f)
		free(f);
	write(1, "Error\n", 6);
	exit(1);
}

int	khdma(char *f, t_stack *a, t_stack *b)
{
	if (compare(f, "ra\n"))
		ra(a);
	else if (compare(f, "rra\n"))
		rra(a);
	else if (compare(f, "rb\n"))
		rb(b);
	else if (compare(f, "rrb\n"))
		rrb(b);
	else if (compare(f, "rr\n"))
		rr(a, b);
	else if (compare(f, "rrr\n"))
		rrr(a, b);
	else if (compare(f, "pa\n"))
		pa(a, b);
	else if (compare(f, "pb\n"))
		pb(a, b);
	else if (compare(f, "sa\n"))
		sa(a);
	else if (compare(f, "sb\n"))
		sb(b);
	else if (compare(f, "ss\n"))
		ss(a, b);
	else
		return (0);
	return (1);
}
