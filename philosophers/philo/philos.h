/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:18:32 by feedback          #+#    #+#             */
/*   Updated: 2025/05/13 17:14:23 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define DEATH "died"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"

typedef struct s_data
{
	int				nop;
	unsigned long	ttd;
	unsigned long	tts;
	unsigned long	tte;
	bool			stop;
	unsigned long	notme;
	unsigned long	start_time;
}					t_data;

typedef struct s_mutex
{
	pthread_mutex_t	*stop_mutex;
	pthread_mutex_t	*mutex_last_meal;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*forks;
}					t_mutex;

typedef struct s_ph
{
	t_mutex			mutex;
	t_data			*data;
	int				id;
	int				count;
	unsigned long	last_meal;
}					t_ph;

typedef struct s_housekeeped
{
	t_ph			*ph;
	pthread_t		*monitor;
	pthread_mutex_t	*mutex_last_meal;
	pthread_mutex_t	*stop;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*forks;
	pthread_t		*thread;
}					t_housekeeped;

typedef struct s_help
{
	t_ph			*ph;
	t_data			*data;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*mutex_last_meal;
	pthread_mutex_t	*stop;
}					t_help;

void				ph_dining_solution(t_data *data);
void				print_status(t_ph *ph, char *status);
void				msleep(unsigned long msec);
unsigned long		time_now_ms(void);
void				eat(t_ph *ph);
t_housekeeped		cleaner_init(t_ph *ph, pthread_t *thread,
						pthread_mutex_t *forks);
void				init_used_data(t_ph *ph, t_data *data, pthread_t *thread,
						pthread_mutex_t *forks);
void				creater_joiner(t_ph *ph, pthread_t *thread);
void				housekeeping(t_housekeeped clean);
void				*monitor_routine(void *arg);
void				*routine(void *arg);
void				die(t_ph *ph);
void				issleep(t_ph *ph);
void				think(t_ph *ph);
#endif
