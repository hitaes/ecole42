/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:57:01 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/14 00:51:18 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

void	map_update(t_game *g, t_block *b)
{
	int	width;
	int	height;

	width = PIXEL_Y;
	height = PIXEL_X;
	g->img = mlx_xpm_file_to_image(g->m->mlx, b->path,
			&width, &height);
	mlx_put_image_to_window(g->m->mlx, g->m->win, g->img,
		b->coord.x, b->coord.y);
}

void	map_draw_first(t_game *g)
{
	g->m->mlx = mlx_init();
	g->m->win = mlx_new_window(g->m->mlx, g->m->size_x * PIXEL_X,
			g->m->size_y * PIXEL_Y, "so_long");
	while (++(g->i) < g->m->column)
	{
		while (++(g->j) < g->m->row)
		{
			if (g->m->f[g->i][g->j].type == PLAYER)
			{
				g->m->f[g->i][g->j].path = IMAGE_PLAYER;
				g->m->p_x = g->j;
				g->m->p_y = g->i;
			}
			else if (g->m->f[g->i][g->j].type == WALL)
				g->m->f[g->i][g->j].path = IMAGE_WALL;
			else if (g->m->f[g->i][g->j].type == EMPTY)
				g->m->f[g->i][g->j].path = IMAGE_EMPTY;
			else if (g->m->f[g->i][g->j].type == COIN)
				g->m->f[g->i][g->j].path = IMAGE_COIN;
			else if (g->m->f[g->i][g->j].type == EXIT)
				g->m->f[g->i][g->j].path = IMAGE_EXIT;
			map_update(g, &(g->m->f[g->i][g->j]));
		}
		g->j = -1;
	}
}

int	map_maker(t_game *g)
{
	if (!g->m->map_init++)
		map_draw_first(g);
	else
	{
		if (g->m->f[g->m->p_y][g->m->p_x].type == WALL)
		{
			g->m->f[g->m->r_y][g->m->r_x].path = IMAGE_PLAYER;
			g->m->p_y = g->m->r_y;
			g->m->p_x = g->m->r_x;
		}
		else
			map_update(g, &(g->m->f[g->m->r_y][g->m->r_x]));
		map_update(g, &(g->m->f[g->m->p_y][g->m->p_x]));
		if (g->m->c == 0 && g->m->f[g->m->p_y][g->m->p_x].type == EXIT)
			game_end(g);
	}
	return (0);
}
