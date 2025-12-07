/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   housekeepers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:31:32 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/05/13 17:11:16 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	housekeeping(t_housekeeped clean_it)
{
	int	size;
	int	i;

	i = 0;
	size = clean_it.ph[0].data->nop;
	while (i < size)
	{
		pthread_mutex_destroy(&clean_it.forks[i]);
		i++;
	}
	pthread_mutex_destroy(clean_it.mutex_last_meal);
	pthread_mutex_destroy(clean_it.stop);
	free(clean_it.ph);
	free(clean_it.thread);
	free(clean_it.mutex_last_meal);
	free(clean_it.forks);
	free(clean_it.print_mutex);
	free(clean_it.stop);
}
