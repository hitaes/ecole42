/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:39:22 by pacman            #+#    #+#             */
/*   Updated: 2021/11/11 00:56:33 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	left_of(t_op *op, int i)
{
	return ((i + op->d_settings[NB_PHILOS] - 1) % op->d_settings[NB_PHILOS]);
}

int	right_of(t_op *op, int i)
{
	return ((i + 1) % op->d_settings[NB_PHILOS]);
}

void	think(t_op *op, int id)
{
	printf("%d: Now, I'm thinking\n",  id);
	usleep(op->d_settings[TIME_NAP] * 10000);
}

void	eat(t_op *op, int id)
{
	printf("%d: Now, I'm eating\n",  id);
	usleep(op->d_settings[TIME_EAT] * 10000);
}

void	test(t_op *op, int i)
{
	if (op->states[i] == _SLEEPING && op->states[i] != _EATING && op->states[i] != _EATING)
	{
		op->states[i] = _EATING;
		pthread_cond_signal(&(op->cond_vars[i]));
	}
}

void	pickup(t_op *op, int i)
{
	pthread_mutex_lock(&(op->mutex_lock));
	op->states[i] = _SLEEPING;
	while (op->states[i] != _EATING)
	{
		pthread_cond_wait(&(op->cond_vars[i]), &(op->mutex_lock));
	}
	pthread_mutex_unlock(&(op->mutex_lock));
}

void	putdown(t_op *op, int i)
{
	pthread_mutex_lock(&(op->mutex_lock));

	op->states[i] = _THINKING;
	test(op, left_of(op, i));
	test(op, right_of(op, i));

	pthread_mutex_unlock(&(op->mutex_lock));
}

void	*philosopher(t_op *op, void *param)
{
	int	id;

	id = *((int *)param);
	while (1)
	{
		think(op, id);
		pickup(op, id);
		eat(op, id);
		putdown(op, id);
	}
}

int	main(int argc, char **argv)
{
	t_op		op;
	pthread_t	tid;
	int			i;

	i = -1;
	ft_memset(&op, 0, sizeof(t_op));
	if (ft_parser(argc, argv))
		ft_error_disposal(ERROR_PARSING);
	else if (argc != 5 && argc != 6)
		ft_error_disposal(ERROR_WRONG_ARGS);
	else if (ft_init(&op, argc, argv))
		ft_error_disposal(ERROR_INIT_FAILURE);
	while (++i < op.d_settings[NB_PHILOS])
		pthread_create(&tid, NULL, philosopher, (void *)&i);
	i = -1;
	while (++i < op.d_settings[NB_PHILOS])
		pthread_join(tid, NULL);
	return (0);
}
