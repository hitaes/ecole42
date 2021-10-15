/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:35:25 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/14 22:15:46 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

void	game_init(t_game *g, t_map *m)
{
	g->i = -1;
	g->j = -1;
	g->bits_per_pixel = 0;
	g->m = m;
	m->p = 0;
	m->p_x = 0;
	m->p_y = 0;
	m->r_x = 0;
	m->r_y = 0;
	m->c = 0;
	m->e = 0;
	m->row = 0;
	m->column = 0;
	m->size_x = 0;
	m->size_y = 0;
	m->g_l = 1;
	m->count = 0;
	m->map_init = 0;
	m->map_path = 0;
	m->l = 0;
	m->mlx = 0;
	m->win = 0;
}
