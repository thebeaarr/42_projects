/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:07:10 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/05/13 17:17:22 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

t_housekeeped	cleaner_init(t_ph *ph, pthread_t *thread,
	pthread_mutex_t *forks)
{
	static t_housekeeped	clean;

	clean.forks = forks;
	clean.mutex_last_meal = ph[0].mutex.mutex_last_meal;
	clean.ph = ph;
	clean.print_mutex = ph[0].mutex.print_mutex;
	clean.stop = ph[0].mutex.stop_mutex;
	clean.thread = thread;
	return (clean);
}

void	ph_dining_solution(t_data *data)
{
	int				size;
	t_housekeeped	clean;
	pthread_mutex_t	*forks;
	pthread_t		*thread;
	t_ph			*ph;

	size = data->nop;
	forks = malloc(sizeof(pthread_mutex_t) * size);
	thread = malloc(sizeof(pthread_t) * size);
	ph = malloc(sizeof(t_ph) * size);
	init_used_data(ph, data, thread, forks);
	clean = cleaner_init(ph, thread, forks);
	data->start_time = time_now_ms();
	creater_joiner(ph, thread);
	housekeeping(clean);
}
