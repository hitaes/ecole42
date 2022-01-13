/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_disposal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:48:07 by pacman            #+#    #+#             */
/*   Updated: 2021/11/30 18:56:17 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_error_disposal(int error, t_philo *philos)
{
	if (error == 100)
		ft_putstr_fd("ERROR_PARSING", STDERR_FILENO);
	else
	{
		if (error == 99)
			ft_putstr_fd("ERROR_INIT_FAILURE", STDERR_FILENO);
		else
			ft_putstr_fd("ERROR_THREAD", STDERR_FILENO);
		clear(philos);
	}
}
