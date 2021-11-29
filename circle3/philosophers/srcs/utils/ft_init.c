/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:12:27 by pacman            #+#    #+#             */
/*   Updated: 2021/11/29 20:08:40 by pacman           ###   ########.fr       */
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

void	philo_init(t_op *op)
{
	int	i;

	i = -1;
	while (++i < op->d_settings[NB_PHILOS])
	{
		op->philos[i].id = i;
		op->philos[i].eat_count = 0;
		op->philos[i].state = _THINKING;
		op->philos[i].left_fork_id = i;
		op->philos[i].right_fork_id = (i + 1) % op->d_settings[NB_PHILOS];
		op->philos[i].last_meal = op->st;
		op->philos[i].op = op;
	}
}

int	ft_init(t_op *op)
{
	int	i;

	i = -1;
	op->philos = (t_philo *)malloc
		(op->d_settings[NB_PHILOS] * sizeof(*(op->philos)));
	op->forks = (pthread_mutex_t *)malloc
		(op->d_settings[NB_PHILOS] * sizeof(pthread_mutex_t));
	if (!op->philos || !op->forks || mutex_init(op))
		return (1);
	philo_init(op);
	return (0);
}
