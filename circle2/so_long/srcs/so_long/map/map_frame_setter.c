/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_frame_setter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:11:25 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/14 02:03:50 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

void	map_frame_setter(t_map *m)
{
	int	i;

	i = -1;
	printf("✅%s\n", m->map_path);
	get_row_column(m);
	m->f = (t_block **)malloc(sizeof(t_block *) * m->column);
	if (m->f == NULL)
		ft_error_disposal();
	while (++i < m->column)
	{
		m->f[i] = (t_block *)malloc(sizeof(t_block) * m->row);
		if (m->f[i] == NULL)
			ft_error_disposal();
	}
}
