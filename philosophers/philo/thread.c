/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:05:57 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/05/13 17:11:37 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

bool	check_stop(t_ph *ph, int i)
{
	pthread_mutex_lock(ph->mutex.stop_mutex);
	if (ph[i].data->stop)
	{
		pthread_mutex_unlock(ph->mutex.stop_mutex);
		return (true);
	}
	pthread_mutex_unlock(ph->mutex.stop_mutex);
	return (false);
}

bool	check_death(t_ph *ph, int i)
{
	pthread_mutex_lock(ph[i].mutex.mutex_last_meal);
	if (time_now_ms() - ph[i].last_meal > ph[i].data->ttd)
	{
		pthread_mutex_unlock(ph[i].mutex.mutex_last_meal);
		die(&ph[i]);
		pthread_mutex_lock(ph[i].mutex.stop_mutex);
		ph[i].data->stop = true;
		pthread_mutex_unlock(ph[i].mutex.stop_mutex);
		return (true);
	}
	pthread_mutex_unlock(ph[i].mutex.mutex_last_meal);
	return (false);
}

void	*monitor_routine(void *arg)
{
	t_ph	*ph;
	int		size;
	int		i;

	ph = (t_ph *)arg;
	size = ph->data->nop;
	while (1)
	{
		i = 0;
		while (i < size)
		{
			if (check_stop(ph, i))
				return (NULL);
			if (check_death(ph, i))
				return (NULL);
		}
		usleep(600);
		i++;
	}
	return (NULL);
}
