/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:05:44 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/14 10:12:10 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shared.h"

void	map_finder(t_game *g, int argc, char **argv)
{
	if (argc != 2)
		ft_error_disposal();
	else
	{
		if (open(argv[1], O_RDONLY) != -1)
		{
			printf("✅\n");
			// g->m->map_path = ft_strdup(argv[1]);
			g->m->map_path = "./resources/map/map.bar";
		}
		else
			ft_error_disposal();
	}
}

int	main(int argc, char **argv)
{
	t_game	g;
	t_map	m;

	game_init(&g, &m);
	map_finder(&g, argc, argv);
	map_frame_setter(g.m);
	map_validator(g.m);
	map_maker(&g);
	mlx_hook(g.m->win, 2, 1L << 0, ft_keypress, &g);
	mlx_loop_hook(g.m->mlx, map_maker, &g);
	mlx_loop(g.m->mlx);
	return (0);
}
