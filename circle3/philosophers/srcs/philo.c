/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:39:22 by pacman            #+#    #+#             */
/*   Updated: 2021/11/09 18:24:07 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_op	op;
	int		r_v;

	if (argc != 5 && argc != 6)
		ft_error_disposal(WRONG_ARGS);
	r_v = ft_philo_init(&op, argc, argv);
	if (r_v == 1)
		ft_error_disposal(INIT_FAILURE);
	return (0);
}