/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:39:06 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/23 19:55:49 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sorting(int *a, int size)
{
	int	*sorted_arr;
	int	i;

	sorted_arr = malloc(size * sizeof(int));
	if (!sorted_arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sorted_arr[i] = a[i];
		i++;
	}
	bubble_sort(sorted_arr, size);
	return (sorted_arr);
}

void	free_resources(int *ar, int *sorted_ar,
	t_stack *stacka, t_stack *stackb)
{
	free_stack(stacka);
	free_stack(stackb);
	free(ar);
	free(sorted_ar);
}

int	*parse_and_check_input(int ac, char **av, int *k)
{
	int	*ar;

	if (ac < 2 || av[1] == NULL)
	{
		message();
		exit(1);
	}
	ar = parse_input(ac, av, k);
	is_here_dup(ar, *k);
	return (ar);
}

int	main(int ac, char **av)
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_data	data;

	if (ac == 1)
		return (0);
	data.k = 0;
	data.ar = parse_and_check_input(ac, av, &data.k);
	is_here_dup(data.ar, data.k);
	stackb = initialize_stack();
	stacka = fill_stack(data.ar, data.k);
	data.size = stack_size(stacka);
	data.sorted_ar = sorting(data.ar, data.k);
	if (data.size == 2)
		sort_2(stacka);
	else if (data.size == 3)
		sort_3(stacka);
	else if (data.size <= 5)
		sort_5(stacka, stackb);
	else
		big_sort(stacka, stackb, data.sorted_ar, data.k);
	free_resources(data.ar, data.sorted_ar, stacka, stackb);
	return (0);
}
