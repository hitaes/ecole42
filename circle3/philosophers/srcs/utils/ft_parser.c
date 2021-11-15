/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:02:25 by pacman            #+#    #+#             */
/*   Updated: 2021/11/10 14:13:39 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_parser(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++i < argc)
	{
		while (!ft_isdigit(argv[i][++j]))
			return (1);
		j = -1;
	}
	return (0);
}
