/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:29:09 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/05/13 17:11:07 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	issleep(t_ph *ph)
{
	msleep(ph->data->tts);
	print_status(ph, SLEEP);
}

void	think(t_ph *ph)
{
	print_status(ph, THINK);
}

void	die(t_ph *ph)
{
	msleep(ph->data->ttd);
	print_status(ph, DEATH);
}
