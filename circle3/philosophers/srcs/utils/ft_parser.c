/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:02:25 by pacman            #+#    #+#             */
/*   Updated: 2021/12/02 12:10:20 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_parser(t_op *op, int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (argc != 5 && argc != 6)
		return (1);
	while (++i < argc)
	{
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (1);
		j = -1;
	}
	i = -1;
	while (++i < argc - 1)
		op->d_settings[i] = ft_atoi(argv[i + 1]);
	if (op->d_settings[NB_PHILOS] < 1 || op->d_settings[TIME_DIE] < 0
		|| op->d_settings[TIME_EAT] < 0 || op->d_settings[TIME_NAP] < 0
		|| op->d_settings[NB_SERVINGS] < 0)
		return (1);
	if (argc == 6 && op->d_settings[NB_SERVINGS] == 0)
		return (1);
	op->st = ft_get_time();
	return (0);
}
