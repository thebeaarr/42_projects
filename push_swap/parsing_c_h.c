/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsin_c_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:17:33 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/23 17:18:32 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace_by_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 9 && str[i] <= 13)
			str[i] = 32;
		i++;
	}
}

void	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && \
!(str[i - 1] >= '0' && str[i - 1] <= '9'))
			i++;
		if (str[i] != 32 && !(str[i] >= '0' && str[i] <= '9'))
		{
			message();
			exit(1);
		}
		i++;
	}
	while (*str == 32)
		str++;
	if (*str == '\0')
	{
		message();
		exit(1);
	}
}

void	handle_overflow(int *a, char *b)
{
	free(a);
	free(b);
	message();
	exit(1);
}

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
