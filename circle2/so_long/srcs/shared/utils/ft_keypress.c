/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:43:50 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/18 23:53:07 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

int	collision_check(t_game *g)
{
	while (++g->i < g->m->column)
	{
		while (++g->j < g->m->row)
		{
			if (g->m->f[g->i][g->j].type == WALL)
				if (g->i == g->m->p_x && g->j == g->m->p_y)
					return (0);
		}	
		g->j = -1;
	}
	g->i = -1;
	return (1);
}

void	keypress_sup(t_block *b, int cnt)
{
	b->path = IMAGE_PLAYER;
	(void)cnt;
}

int	ft_keypress(int keycode, t_game *g)
{
	ft_trace_setter(g);
	if (keycode == END)
		game_end(g);
	if (keycode == R && g->m->f[g->m->p_y][g->m->p_x + 1].type != WALL)
		keypress_sup(&(g->m->f[g->m->p_y][++g->m->p_x]), g->m->cnt_action++);
	else if (keycode == L && g->m->f[g->m->p_y][g->m->p_x - 1].type != WALL)
		keypress_sup(&(g->m->f[g->m->p_y][--g->m->p_x]), g->m->cnt_action++);
	else if (keycode == D && g->m->f[g->m->p_y + 1][g->m->p_x].type != WALL)
		keypress_sup(&(g->m->f[++g->m->p_y][g->m->p_x]), g->m->cnt_action++);
	else if (keycode == U && g->m->f[g->m->p_y - 1][g->m->p_x].type != WALL)
		keypress_sup(&(g->m->f[--g->m->p_y][g->m->p_x]), g->m->cnt_action++);
	else
		g->m->f[g->m->p_y][g->m->p_x].path = IMAGE_PLAYER;
	return (0);
}
