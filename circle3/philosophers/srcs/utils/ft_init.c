/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:12:27 by pacman            #+#    #+#             */
/*   Updated: 2021/12/01 00:45:09 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	mutex_init(t_op *op)
{
	int	i;

	i = -1;
	while (++i < op->d_settings[NB_PHILOS])
	{
		if (pthread_mutex_init(&(op->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&op->print, NULL)
		|| pthread_mutex_init(&op->death_checker, NULL)
		|| pthread_mutex_init(&op->nb_aia, NULL))
		return (1);
	pthread_mutex_lock(&(op->death_checker));
	return (0);
}

int	philo_init(t_op *op, t_philo **philos)
{
	int	i;

	i = -1;
	*philos = (t_philo *)malloc
		(op->d_settings[NB_PHILOS] * sizeof(t_philo));
	if (!philos)
		return (1);
	while (++i < op->d_settings[NB_PHILOS])
	{
		(*philos)[i].id = i;
		(*philos)[i].eat_count = 0;
		(*philos)[i].state = _THINKING;
		(*philos)[i].left_fork_id = i;
		(*philos)[i].right_fork_id = (i + 1) % op->d_settings[NB_PHILOS];
		(*philos)[i].last_meal = op->st;
		(*philos)[i].op = op;
	}
	return (0);
}

int	fork_init(t_op *op)
{
	op->forks = (pthread_mutex_t *)malloc
		(op->d_settings[NB_PHILOS] * sizeof(pthread_mutex_t));
	if (!(op->forks))
		return (1);
	return (0);
}

int	ft_init(t_op *op, t_philo **philos)
{
	if (fork_init(op) || philo_init(op, philos) || mutex_init(op))
		return (1);
	return (0);
}
