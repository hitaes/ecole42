/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:39:22 by pacman            #+#    #+#             */
/*   Updated: 2021/11/30 00:12:38 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	clear_op(t_op *op)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < op->d_settings[NB_PHILOS])
// 	{
// 		pthread_mutex_destroy(&(op->forks[i]));
// 	}
// 	if (op->philos)
// 	{
// 		free(op->philos);
// 		op->philos = 0;
// 	}
// 	if (op->forks)
// 	{
// 		free(op->forks);
// 		op->forks = 0;
// 	}
// }

void	*philosopher(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (!(p->id % 2))
		take_your_time(p, TIME_EAT);
	while (p->state <= _SLEEPING)
	{
		pick_up(p);
		eating(p);
		put_down(p);
		sleeping_then_thinking(p);
	}
	return (NULL);
}

void	*monitor(void *philo)
{
	t_philo		*p;
	long long	ct;

	p = (t_philo *)philo;
	while (p->state <= _SLEEPING && !p->op->is_dead)
	{
		ct = ft_get_time() - p->last_meal;
		if (ct > p->op->d_settings[TIME_DIE])
		{
			p->state = _DIED;
			print_state(p, "died");
			pthread_mutex_unlock(&p->op->death_checker);
			break ;
		}
	}
	return (NULL);
}

int	thread_start(t_philo *philos)
{
	int			i;
	pthread_t	tid;

	i = -1;
	while (++i < philos->op->d_settings[NB_PHILOS])
	{
		if (pthread_create(&(tid), NULL, philosopher, &(philos[i]))
			|| pthread_detach(tid))
			return (1);
		if (pthread_create(&(tid), NULL, monitor, &(philos[i]))
			|| pthread_detach(tid))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_op		op;
	t_philo		*philos;

	ft_memset(&op, 0, sizeof(t_op));
	philos = 0;
	if (ft_parser(&op, argc, argv))
		ft_error_disposal("ERROR_PARSING");
	else if (ft_init(&op, &philos))
		ft_error_disposal("ERROR_INIT_FAILURE");
	else if (thread_start(philos))
		ft_error_disposal("ERROR_THREAD");
	pthread_mutex_lock(&(op.death_checker));
	pthread_mutex_unlock(&(op.death_checker));
	// clear_op(&op);
	return (0);
}
