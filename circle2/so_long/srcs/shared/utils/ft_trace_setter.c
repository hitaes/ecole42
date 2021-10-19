/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_setter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:43:07 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/14 00:45:10 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

void	ft_trace_setter(t_game *g)
{
	if (g->m->f[g->m->p_y][g->m->p_x].type == EXIT)
		g->m->f[g->m->p_y][g->m->p_x].path = IMAGE_EXIT;
	else
		g->m->f[g->m->p_y][g->m->p_x].path = IMAGE_EMPTY;
	if (g->m->f[g->m->p_y][g->m->p_x].type == COIN)
	{
		g->m->f[g->m->p_y][g->m->p_x].type = EMPTY;
		g->m->c--;
	}
	g->m->r_y = g->m->p_y;
	g->m->r_x = g->m->p_x;
}
