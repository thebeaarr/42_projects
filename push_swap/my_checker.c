/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:21:28 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/23 18:45:19 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "push_swap.h"

int	compare(char *f, char *op)
{
	int	i;

	i = 0;
	while (f[i])
	{
		if (f[i] != op[i])
			return (0);
		i++;
	}
	return (f[i] == op[i]);
}

int	sorted_check(t_stack *a, t_stack *b)
{
	t_node	*t;

	if (b->head)
		return (0);
	t = a->head;
	while (t && t->next)
	{
		if (t->i > t->next->i)
			return (0);
		t = t->next;
	}
	return (1);
}

void	initialize_stacks(t_stack **stacka, t_stack **stackb, int *ar, int k)
{
	*stackb = initialize_stack();
	if (!*stackb)
		handle_error(ar, NULL, NULL);
	*stacka = fill_stack(ar, k);
	if (!*stacka)
		handle_error(ar, NULL, *stackb);
	free(ar);
}

void	read_and_execute(t_stack *stacka, t_stack *stackb)
{
	char	*f;

	while (1)
	{
		f = get_next_line(0);
		if (!f)
			break ;
		if (khdma(f, stacka, stackb) == 0)
			clean_exit(stacka, stackb, f);
		free(f);
	}
}

int	main(int ac, char **av)
{
	int		k;
	int		*ar;
	t_stack	*stacka;
	t_stack	*stackb;

	process_input(ac, av, &k, &ar);
	initialize_stacks(&stacka, &stackb, ar, k);
	read_and_execute(stacka, stackb);
	if (sorted_check(stacka, stackb))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stacka);
	free_stack(stackb);
	return (0);
}
