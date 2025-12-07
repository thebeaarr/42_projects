/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:16:32 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/24 09:28:38 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join(int ac, char **av, size_t size)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
	{
		write(2, "Memory allocation failed\n", 24);
		exit(1);
	}
	while (i < ac)
	{
		k = 0;
		while (av[i][k])
			str[j++] = av[i][k++];
		if (i < ac - 1)
			str[j++] = 32;
		i++;
	}
	str[j] = '\0';
	return (str);
}

void	da7k(char *string, int *i)
{
	int	j;

	j = 0;
	*i = 0;
	while (string[j])
	{
		while (string[j] == 32)
			j++;
		if (string[j] >= '0' && string[j] <= '9')
		{
			(*i)++;
			while (string[j] >= '0' && string[j] <= '9')
				j++;
		}
		else
			j++;
	}
}
