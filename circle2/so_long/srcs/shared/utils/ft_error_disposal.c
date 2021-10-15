/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_disposal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:04:44 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/15 01:36:17 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

void	ft_error_disposal(int message)
{
	if (message == OTHER)
		ft_putstr_fd("Error\n[OTHER]\n", STDERR_FILENO);
	else if (message == NOWALL)
		ft_putstr_fd("Error\n[NOWALL]\n", STDERR_FILENO);
	else if (message == PLAYERERROR)
		ft_putstr_fd("Error\n[PLAYERERROR]\n", STDERR_FILENO);
	else if (message == COINERROR)
		ft_putstr_fd("Error\n[COINERROR]\n", STDERR_FILENO);
	else if (message == EXITERROR)
		ft_putstr_fd("Error\n[EXITERROR]\n", STDERR_FILENO);
	else if (message == RECERROR)
		ft_putstr_fd("Error\n[RECERROR]\n", STDERR_FILENO);
	else if (message == MALERROR)
		ft_putstr_fd("Error\n[MALERROR]\n", STDERR_FILENO);
	else if (message == GNLERROR)
		ft_putstr_fd("Error\n[GNLERROR]\n", STDERR_FILENO);
	else if (message == OPENERROR)
		ft_putstr_fd("Error\n[OPENERROR]\n", STDERR_FILENO);
	else if (message == NOTFOUNDERROR)
		ft_putstr_fd("Error\n[NOTFOUNDERROR]\n", STDERR_FILENO);
	exit(1);
}
