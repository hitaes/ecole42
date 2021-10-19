/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_disposal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:04:44 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/18 20:09:23 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

void	ft_error_disposal(t_map *m, int message)
{
	if (message == OTHER)
		ft_putstr_fd("Error : [OTHER]\n", STDERR_FILENO);
	else if (message == NOWALL)
		ft_putstr_fd("Error : [NO_WALL]\n", STDERR_FILENO);
	else if (message == PLAYERERROR)
		ft_putstr_fd("Error : [PLAYER_ERROR]\n", STDERR_FILENO);
	else if (message == COINERROR)
		ft_putstr_fd("Error : [COIN_ERROR]\n", STDERR_FILENO);
	else if (message == EXITERROR)
		ft_putstr_fd("Error : [EXIT_ERROR]\n", STDERR_FILENO);
	else if (message == RECERROR)
		ft_putstr_fd("Error : [REC_ERROR]\n", STDERR_FILENO);
	else if (message == MALERROR)
		ft_putstr_fd("Error : [MAL_ERROR]\n", STDERR_FILENO);
	else if (message == GNLERROR)
		ft_putstr_fd("Error : [GNL_ERROR]\n", STDERR_FILENO);
	else if (message == OPENERROR)
		ft_putstr_fd("Error : [OPEN_ERROR]\n", STDERR_FILENO);
	else if (message == NOTFOUNDERROR)
		ft_putstr_fd("Error : [NOT_FOUND_ERROR]\n", STDERR_FILENO);
	ft_free_map(m);
	exit(1);
}
