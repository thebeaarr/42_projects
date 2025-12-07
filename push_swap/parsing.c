/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:24:45 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/24 11:36:14 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_input(int ac, char **av, int *k)
{
	size_t	sum;
	int		i;
	char	*all_of_them_here;
	int		*arr;

	sum = 0;
	i = 0;
	while (++i < ac)
	{
		sum += ft_strlen(av[i]) + 1;
		replace_by_space(av[i]);
		check(av[i]);
	}
	all_of_them_here = join(ac, av, sum);
	da7k(all_of_them_here, k);
	arr = malloc(sizeof(int) * (*k));
	if (!arr)
	{
		free(all_of_them_here);
		write(2, "Memory allocation failed\n", 24);
		exit(1);
	}
	parse_numbers(all_of_them_here, arr);
	free(all_of_them_here);
	return (arr);
}

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
