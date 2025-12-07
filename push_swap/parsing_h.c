/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:52:51 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/24 10:15:32 by mlakhdar         ###   ########.fr       */
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

void	is_here_dup(int *a, int k)
{
	int	i;
	int	j;

	i = 0;
	while (i < k - 1)
	{
		j = i + 1;
		while (j < k)
		{
			if (a[i] == a[j])
			{
				free(a);
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
	if (is_sorted(a, k))
	{
		free(a);
		exit(0);
	}
}
