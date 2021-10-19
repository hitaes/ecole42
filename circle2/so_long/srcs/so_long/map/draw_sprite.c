/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:26:11 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/19 21:30:57 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

void	draw_mon(t_game *g, int state)
{
	if (state == 0)
	{
		g->m->m_x -= 1;
		g->img = mlx_xpm_file_to_image(g->m->mlx, IMAGE_MONSTER,
				&g->m->size_x, &g->m->size_y);
		mlx_put_image_to_window(g->m->mlx, g->m->win, g->img,
			g->m->m_x * PIXEL_X, g->m->m_y * PIXEL_Y);
		g->img = mlx_xpm_file_to_image(g->m->mlx, IMAGE_EMPTY,
				&g->m->size_x, &g->m->size_y);
		mlx_put_image_to_window(g->m->mlx, g->m->win, g->img,
			(g->m->m_x + 1) * PIXEL_X, g->m->m_y * PIXEL_Y);
	}
	else if (state == 1)
	{
		g->m->m_x += 1;
		g->img = mlx_xpm_file_to_image(g->m->mlx, IMAGE_MONSTER,
				&g->m->size_x, &g->m->size_y);
		mlx_put_image_to_window(g->m->mlx, g->m->win, g->img,
			g->m->m_x * PIXEL_X, g->m->m_y * PIXEL_Y);
		g->img = mlx_xpm_file_to_image(g->m->mlx, IMAGE_EMPTY,
				&g->m->size_x, &g->m->size_y);
		mlx_put_image_to_window(g->m->mlx, g->m->win, g->img,
			(g->m->m_x - 1) * PIXEL_X, g->m->m_y * PIXEL_Y);
	}
}

void	draw_coin(t_game *g, int state)
{
	while (++(g->i) < g->m->column)
	{
		while (++(g->j) < g->m->row)
		{
			if (g->m->f[g->i][g->j].type == COIN)
			{
				if (state)
					g->m->f[g->i][g->j].path = IMAGE_COIN;
				else
					g->m->f[g->i][g->j].path = IMAGE_COIN2;
				map_update(g, &(g->m->f[g->i][g->j]));
			}
		}
		g->j = -1;
	}
	g->i = -1;
}

void	interval(t_game *g, time_t gap)
{
	if (gap % 2 == 0)
	{
		g->one = 0;
		g->zero++;
	}
	else if (gap % 2 == 1)
	{
		g->one++;
		g->zero = 0;
	}
}

void	draw_sprite(t_game *g)
{
	if (g->one == 0 && g->zero == 1)
	{
		draw_coin(g, 1);
		draw_mon(g, 1);
	}
	else if (g->zero == 0 && g->one == 1)
	{
		draw_coin(g, 0);
		draw_mon(g, 0);
	}
}
