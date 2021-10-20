/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_disposal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:19:08 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/20 17:18:46 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

void	error_disposal(t_arg *t, int message)
{
	if (message == MALERROR)
		ft_putstr_fd("Error : [Malloc Error]\n", STDERR_FILENO);
	else if (message == ENVPATHERROR)
		ft_putstr_fd("Error : [Env Path Error]\n", STDERR_FILENO);
	(void)t;
	exit(1);
}
