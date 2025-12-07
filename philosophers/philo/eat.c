/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:08:55 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/05/13 17:12:28 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	update_last_meal(t_ph *ph)
{
	pthread_mutex_lock(ph->mutex.mutex_last_meal);
	ph->last_meal = time_now_ms();
	pthread_mutex_unlock(ph->mutex.mutex_last_meal);
}

void	lock_forks(t_ph *ph)
{
	pthread_mutex_lock(ph->mutex.lfork);
	pthread_mutex_lock(ph->mutex.rfork);
}

void	unlock_forks(t_ph *ph)
{
	pthread_mutex_unlock(ph->mutex.rfork);
	pthread_mutex_unlock(ph->mutex.lfork);
}

void	eat(t_ph *ph)
{
	if (ph->id % 2 != 0)
		usleep(600);
	if (ph->data->notme != -1 && ph->count == ph->data->notme)
		return ;
	if (ph->data->notme != -1)
		ph->count++;
	lock_forks(ph);
	print_status(ph, FORK);
	print_status(ph, FORK);
	update_last_meal(ph);
	print_status(ph, EAT);
	msleep(ph->data->tte);
	unlock_forks(ph);
}
