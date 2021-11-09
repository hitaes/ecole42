/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_disposal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:48:07 by pacman            #+#    #+#             */
/*   Updated: 2021/11/09 17:23:28 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_error_disposal(int err_num)
{
	if (err_num == WRONG_ARGS)
		ft_putstr_fd("Error : WRONG ARGS\n", STDERR_FILENO);
	else if (err_num == INIT_FAILURE)
		ft_putstr_fd("Error : INIT FAILURE\n", STDERR_FILENO);
}
