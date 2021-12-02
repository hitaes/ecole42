/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:39:22 by pacman            #+#    #+#             */
/*   Updated: 2021/12/03 00:00:52 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clear(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->op->d_settings[NB_PHILOS])
		pthread_mutex_destroy(&(philos->op->forks[i]));
	pthread_mutex_destroy(&(philos->op->nb_aia));
	pthread_mutex_destroy(&(philos->op->death_checker));
	pthread_mutex_destroy(&(philos->op->print));
	if (philos->op->forks)
	{
		free(philos->op->forks);
		philos->op->forks = 0;
	}
	if (philos)
	{
		free(philos);
		philos = 0;
	}
}

void	*philosopher(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (!(p->id % 2))
	{
		if (p->op->d_settings[NB_PHILOS] <= 4)
			usleep(100);
		else 
			usleep(p->op->d_settings[NB_PHILOS] * 10);
	}
	while (p->state <= _SLEEPING)
	{
		pick_up(p);
		eating(p);
		put_down(p);
		sleeping(p);
		thinking(p);
	}
	return (NULL);
}

void	*monitor(void *philo)
{
	t_philo		*p;
	int			i;

	usleep(1000);
	p = (t_philo *)philo;
	i = -1;
	while (++i < p->op->d_settings[NB_PHILOS])
	{
		if (p[i].state <= _SLEEPING && !p[i].op->is_dead)
		{
			if (ft_get_time() - p->last_meal > p[i].op->d_settings[TIME_DIE])
			{
				p[i].state = _DIED;
				print_state(&(p[i]), "died");
				pthread_mutex_unlock(&(p[i].op->death_checker));
				return (&(p[i]));
			}
			i++;
		}
	}
	if (p->op->f_philo == p->op->d_settings[NB_PHILOS])
		return (&(p[i]));
	return (NULL);
}

int	thread_start(t_philo *philos)
{
	int			i;
	pthread_t	tid;

	i = -1;
	while (++i < philos->op->d_settings[NB_PHILOS])
		if (pthread_create(&(tid), NULL, philosopher, &(philos[i]))
			|| pthread_detach(tid))
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_op		op;
	t_philo		*philos;

	ft_memset(&op, 0, sizeof(t_op));
	philos = 0;
	if (ft_parser(&op, argc, argv))
		ft_error_disposal(ERROR_PARSING, philos);
	else if (ft_init(&op, &philos))
		ft_error_disposal(ERROR_INIT_FAILURE, philos);
	else if (thread_start(philos))
		ft_error_disposal(ERROR_THREAD, philos);
	else
	{
		while (!monitor(philos))
			;
		pthread_mutex_lock(&(op.death_checker));
		pthread_mutex_unlock(&(op.death_checker));
		clear(philos);
	}
	return (0);
}
