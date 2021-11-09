/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:12:27 by pacman            #+#    #+#             */
/*   Updated: 2021/11/09 18:14:38 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_philo_init(t_op *op, int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < argc - 1)
		op->d_settings[i] = ft_atoi(argv[i + 1]);
	if (op->d_settings[NB_PHILOS] < 2 || op->d_settings[TIME_DIE] < 0
		|| op->d_settings[TIME_EAT] < 0 || op->d_settings[TIME_NAP] < 0
		|| op->d_settings[NB_MEALS] <= 0)
		return (1);
	return (0);
}
