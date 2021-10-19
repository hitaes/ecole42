/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:57:01 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/19 21:26:37 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

void	cnt_draw(t_map *m)
{
	char	*cnt_string;
	char	*temp_string;
	void	*img;

	img = mlx_xpm_file_to_image(m->mlx, IMAGE_WALL, &m->size_x, &m->size_y);
	cnt_string = ft_itoa(m->cnt_action);
	temp_string = ft_strdup("Action count : ");
	temp_string = ft_strjoin(temp_string, cnt_string);
	mlx_put_image_to_window(m->mlx, m->win, img, 0, 0);
	mlx_put_image_to_window(m->mlx, m->win, img, 64, 0);
	mlx_put_image_to_window(m->mlx, m->win, img, 128, 0);
	mlx_string_put(m->mlx, m->win, 25, 25, 0x00FFFFFF, temp_string);
	free(temp_string);
}

void	map_update(t_game *g, t_block *b)
{
	g->img = mlx_xpm_file_to_image(g->m->mlx, b->path,
			&g->m->size_x, &g->m->size_y);
	mlx_put_image_to_window(g->m->mlx, g->m->win, g->img,
		b->coord.x, b->coord.y);
	cnt_draw(g->m);
}

void	map_draw_first(t_game *g)
{
	t_block	b;

	while (++(g->i) < g->m->column)
	{
		while (++(g->j) < g->m->row)
		{
			b.coord = g->m->f[g->i][g->j].coord;
			b.path = IMAGE_EMPTY;
			map_update(g, &b);
			if (g->m->f[g->i][g->j].type == PLAYER)
			{
				g->m->p_x = g->j;
				g->m->p_y = g->i;
			}
			else if (g->m->f[g->i][g->j].type == MONSTER)
			{
				g->m->m_x = g->j;
				g->m->m_y = g->i;
			}
			map_update(g, &(g->m->f[g->i][g->j]));
		}
		g->j = -1;
	}
	g->i = -1;
}

int	map_maker(t_game *g)
{
	if (!g->m->map_init++)
	{
		g->m->mlx = mlx_init();
		g->m->win = mlx_new_window(g->m->mlx, g->m->size_x * PIXEL_X,
				g->m->size_y * PIXEL_Y, "so_long");
		map_draw_first(g);
	}
	else
	{
		interval(g, time(NULL) - g->start);
		if (g->m->f[g->m->p_y][g->m->p_x].type == WALL)
		{
			g->m->f[g->m->r_y][g->m->r_x].path = IMAGE_PLAYER;
			g->m->p_y = g->m->r_y;
			g->m->p_x = g->m->r_x;
		}
		else
			map_update(g, &(g->m->f[g->m->r_y][g->m->r_x]));
		map_update(g, &(g->m->f[g->m->p_y][g->m->p_x]));
		if ((g->m->c == 0 && g->m->f[g->m->p_y][g->m->p_x].type == EXIT)
			|| (g->m->p_x == g->m->m_x && g->m->p_y == g->m->m_y))
			game_end(g);
		draw_sprite(g);
	}
	return (0);
}
