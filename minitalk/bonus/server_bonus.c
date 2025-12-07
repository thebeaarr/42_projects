/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:34:57 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/02/02 19:09:03 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle(int sig, siginfo_t *info, void *context)
{
	static char		s = 0;
	static int		i = 0;
	static pid_t	client_pid = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (sig == SIGUSR2)
		s |= (1 << i);
	i++;
	if (i == 8)
	{
		if (s == '\0')
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
		}
		else
			write(1, &s, 1);
		i = 0;
		s = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	mini_printf("PID SERVER IS: ", getpid());
	sa.sa_sigaction = handle;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
