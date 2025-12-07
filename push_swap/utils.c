/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:29:41 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/24 10:16:08 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	message(void)
{
	write(2, "Error\n", 6);
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*sorted(int *a, int size)
{
	int	*sorted_arr;
	int	i;

	sorted_arr = (int *)malloc(size * sizeof(int));
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

size_t	ft_strlen(const char *s)
{
	const char	*ptr = s;

	if (s[0] == '\0')
	{
		message();
		exit(1);
	}
	while (*ptr)
		ptr++;
	return ((size_t)(ptr - s));
}

int	is_sorted(int *a, int k)
{
	int	i;

	i = -1;
	while (++i < k - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
	}
	return (1);
}
