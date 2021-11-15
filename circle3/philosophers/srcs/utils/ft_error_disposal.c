/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_disposal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:48:07 by pacman            #+#    #+#             */
/*   Updated: 2021/11/10 14:08:44 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_error_disposal(int err_num)
{
	if (err_num == ERROR_WRONG_ARGS)
		ft_putstr_fd("Error : WRONG ARGS\n", STDERR_FILENO);
	else if (err_num == ERROR_INIT_FAILURE)
		ft_putstr_fd("Error : INIT FAILURE\n", STDERR_FILENO);
	else if (err_num == ERROR_PARSING)
		ft_putstr_fd("Error : PARSING ERROR\n", STDERR_FILENO);
}
