/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_row_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:46:06 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/15 01:12:50 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

void	map_row_column(t_map *m)
{
	int		i;
	int		l;
	char	*line;
	int		fd;

	i = -1;
	l = 1;
	line = 0;
	fd = open(m->map_path, O_RDONLY);
	if (fd == -1)
		ft_error_disposal(OPENERROR);
	while (l != 0)
	{
		l = ft_get_next_line(fd, &line);
		if (l == -1)
			ft_error_disposal(GNLERROR);
		m->row = 0;
		while (line[++i])
			m->row++;
		m->column++;
		i = -1;
		ft_free(line);
	}
	close(fd);
}
