/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_frame_setter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:11:25 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/15 01:12:25 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

void	map_frame_setter(t_map *m)
{
	int	i;

	i = -1;
	map_row_column(m);
	m->f = (t_block **)malloc(sizeof(t_block *) * m->column);
	if (m->f == NULL)
		ft_error_disposal(MALERROR);
	while (++i < m->column)
	{
		m->f[i] = (t_block *)malloc(sizeof(t_block) * m->row);
		if (m->f[i] == NULL)
			ft_error_disposal(MALERROR);
	}
}
