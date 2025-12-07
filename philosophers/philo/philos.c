/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:26:43 by feedback          #+#    #+#             */
/*   Updated: 2025/05/14 09:43:33 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"
#include <limits.h>

ssize_t	tol(char *string)
{
	int		i;
	ssize_t	res;

	i = 0;
	res = 0;
	if (string[i] == '-')
		return (write(2, "Error: Negative numbers are not allowed.\n", 41), -1);
	if (string[i] == '+')
		i++;
	while (string[i] >= '0' && string[i] <= '9')
	{
		if (res > (SSIZE_MAX - (string[i] - '0')) / 10)
			return (write(2, "Error: Overflow detected.\n", 26), -1);
		res = res * 10 + (string[i] - '0');
		i++;
	}
	if (string[i] != '\0')
	{
		write(2, "Error: Invalid parameter: ", 26);
		write(2, string, strlen(string));
		write(2, "\n", 1);
		return (-1);
	}
	return (res);
}

int	starting(t_data *data, char **av, int ac)
{
	data->nop = tol(av[1]);
	data->ttd = tol(av[2]);
	data->tte = tol(av[3]);
	data->tts = tol(av[4]);
	if (ac == 6)
	{
		if (tol(av[5]) == -1)
			return (-1);
		data->notme = tol(av[5]);
	}
	else
		data->notme = -1;
	if (data->nop == -1 || data->nop == 0 || data->tts == -1 || data->ttd == -1
		|| data->tte == -1)
	{
		return (1);
	}
	data->start_time = time_now_ms();
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
	{
		printf("ERROR: NOT ENOUGH.\n");
		return (1);
	}
	if (starting(&data, av, ac))
		return (1);
	ph_dining_solution(&data);
	return (0);
}
