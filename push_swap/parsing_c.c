/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:24:45 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/24 11:36:07 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_numbers(char *input, int *arr)
{
	int		sign;
	int		i;
	int		a;
	long	c;

	i = 0;
	a = 0;
	sign = 1;
	while (input[i])
	{
		sign = 1;
		while (input[i] == ' ')
			i++;
		if (input[i] == '+' || input[i] == '-')
		{
			if (input[i] == '-')
				sign = -1;
			i++;
		}
		c = extract_number(input, &i, arr, sign);
		arr[a] = c;
		a++;
	}
}

long	extract_number(char *input, int *i, int *arr, int sign)
{
	long	c;
	short	digit;

	c = 0;
	while (input[*i] >= '0' && input[*i] <= '9')
	{
		digit = input[*i] - '0';
		if ((sign == 1 && (c > (INT_MAX / 10)
					|| (c == INT_MAX / 10 && digit > 7)))
			|| (sign == -1 && (c > (-(INT_MIN / 10))
					|| (c == -(INT_MIN / 10) && digit > 8))))
		{
			handle_overflow(arr, input);
		}
		c = c * 10 + digit;
		(*i)++;
	}
	return (sign * c);
}

void	check_for_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size - 1)
	{
		while (j < size)
		{
			if (array[i] == array[j])
			{
				free(array);
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}
