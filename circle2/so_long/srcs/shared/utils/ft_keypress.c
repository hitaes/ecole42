/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:43:50 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/14 00:48:52 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

int	ft_keypress(int keycode, t_game *g)
{
	ft_trace_setter(g);
	if (keycode == END)
		game_end(g);
	if (keycode == R)
		g->m->f[g->m->p_y][++g->m->p_x].path = IMAGE_PLAYER;
	else if (keycode == L)
		g->m->f[g->m->p_y][--g->m->p_x].path = IMAGE_PLAYER;
	else if (keycode == D)
		g->m->f[++g->m->p_y][g->m->p_x].path = IMAGE_PLAYER;
	else if (keycode == U)
		g->m->f[--g->m->p_y][g->m->p_x].path = IMAGE_PLAYER;
	else
		g->m->f[g->m->p_y][g->m->p_x].path = IMAGE_PLAYER;
	return (0);
}
