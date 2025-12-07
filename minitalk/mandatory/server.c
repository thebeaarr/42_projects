/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:34:57 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/02 18:57:57 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle(int sig)
{
	static char	s = 0;
	static int	i = 0;

	if (sig == SIGUSR2)
		s |= (1 << (i));
	i++;
	if (i == 8)
	{
		i = 0;
		write(1, &s, 1);
		s = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	mini_printf("PID SERVER IS: ", getpid());
	sa.sa_handler = handle;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
