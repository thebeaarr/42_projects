/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:35:23 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/02 18:54:23 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sent_signal(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i++;
	}
}

int	parse_input(int ac, char **av)
{
	if (ac != 3)
		error_input(0);
	return (ft_atoi1(av[1]));
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	pid = parse_input(ac, av);
	if (pid <= 0)
		error_input(1);
	while (av[2][i])
	{
		sent_signal(av[2][i], pid);
		i++;
	}
	sent_signal('\n', pid);
	return (0);
}
