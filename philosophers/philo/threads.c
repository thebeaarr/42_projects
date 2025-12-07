/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:30:09 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/05/13 17:11:40 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

bool	handle_single_philosopher(t_ph *ph)
{
	if (ph->data->nop == 1)
	{
		print_status(ph, FORK);
		die(ph);
		return (true);
	}
	return (false);
}

bool	check_stop_condition(t_ph *ph)
{
	pthread_mutex_lock(ph->mutex.stop_mutex);
	if (ph->data->stop || (ph->data->notme != -1
			&& ph->count == ph->data->notme))
	{
		ph->data->stop = true;
		pthread_mutex_unlock(ph->mutex.stop_mutex);
		return (true);
	}
	pthread_mutex_unlock(ph->mutex.stop_mutex);
	return (false);
}

void	*routine(void *arg)
{
	t_ph	*ph;

	ph = (t_ph *)arg;
	while (1)
	{
		if (handle_single_philosopher(ph))
			return (NULL);
		if (check_stop_condition(ph))
			return (NULL);
		eat(ph);
		issleep(ph);
		think(ph);
	}
	return (NULL);
}
