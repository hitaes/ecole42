/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_finder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:39:01 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/15 01:13:31 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

void	map_finder(t_game *g, int argc, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		ft_error_disposal(g->m, OPENERROR);
	else
	{
		if (fd != -1 && !ft_strcmp(argv[1], "./resources/map/")
			&& ft_strcmp("./resources/map/", argv[1]))
			g->m->map_path = argv[1];
		else
			ft_error_disposal(g->m, NOTFOUNDERROR);
	}
}
