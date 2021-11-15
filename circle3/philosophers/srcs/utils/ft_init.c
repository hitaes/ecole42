/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:12:27 by pacman            #+#    #+#             */
/*   Updated: 2021/11/11 00:48:25 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_init(t_op *op, int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < argc - 1)
		op->d_settings[i] = ft_atoi(argv[i + 1]);
	if (op->d_settings[NB_PHILOS] < 2 || op->d_settings[TIME_DIE] < 0
		|| op->d_settings[TIME_EAT] < 0 || op->d_settings[TIME_NAP] < 0
		|| op->d_settings[NB_SERVINGS] < 0)
		return (1);
	op->states = (t_state *)malloc(sizeof(t_state) * op->d_settings[NB_PHILOS]);
	op->cond_vars = (pthread_cond_t *)malloc(sizeof(pthread_cond_t)
			* op->d_settings[NB_PHILOS]);
	if (!op->states || !op->cond_vars)
		return (1);
	i = -1;
	while (++i < op->d_settings[NB_PHILOS])
	{
		op->states[i] = _THINKING;
		pthread_cond_init(&(op->cond_vars[i]), NULL);
	}
	pthread_mutex_init(&(op->mutex_lock), NULL);
	return (0);
}
