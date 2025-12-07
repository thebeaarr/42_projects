/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:27:58 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/05/13 17:11:43 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

unsigned long	time_now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	msleep(unsigned long msec)
{
	size_t	start;
	size_t	target;

	start = time_now_ms();
	target = start + msec;
	while (time_now_ms() < target)
		usleep(100);
}

void	print_status(t_ph *ph, char *status)
{
	unsigned long	time;

	time = time_now_ms() - ph->data->start_time;
	pthread_mutex_lock(ph->mutex.stop_mutex);
	if (!ph->data->stop)
	{
		pthread_mutex_lock(ph->mutex.print_mutex);
		printf("%lu %d %s\n", time, ph->id, status);
		pthread_mutex_unlock(ph->mutex.print_mutex);
	}
	pthread_mutex_unlock(ph->mutex.stop_mutex);
}
