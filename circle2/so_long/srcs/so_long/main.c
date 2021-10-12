/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:05:44 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/12 19:38:14 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shared.h"

int	main(void)
{
	// t_game	g;
	t_map	m;
	int		i;
	// void	*mlx;
	// void	*mlx_win;

	i = -1;
	map_validator(&m);

	while (++i < m.count)
	{
		printf("✅index: %d, type: %d, x: %d, y: %d\n", m.b_l[i].index, m.b_l[i].type, m.b_l[i].coord.x, m.b_l[i].coord.y);
	}

	// printf("✅%d\n", m.b_l[0].index);
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, m.size_x * 64, m.size_y * 64, "so_long");

	// printf("✅%d\n", m.b_l[0][0].index);

	// printf("✅index: %d, type: %s, path: %s, x: %d, y: %d\n", m.b_l[0][0].index, m.b_l[0][0].type, m.b_l[0][0].path, m.b_l[0][0].coord.x, m.b_l[0][0].coord.y);

	// printf("✅%d\n", m.b_l[0]->index);
	// while (++i < m.b_l->index)
	// {
	// 	printf("✅index: %d, type: %s, path: %s, x: %d, y: %d\n", m.b_l[i].index, m.b_l[i].type, m.b_l[i].path, m.b_l[i].coord.x, m.b_l[i].coord.y);
	// }


	// mlx_loop(mlx);

	// while (/* condition */)
	// {
	// 	g.img = mlx_xpm_file_to_image(mlx, m.b->path, &(m.w->coord.x), &(m.w->coord.y));
	// }


	// mlx_put_image_to_window(mlx, mlx_win, g.img, 0, 0);
	// mlx_loop(mlx);
	// (void)g;
	return (0);
}
