/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:04:59 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/18 21:38:03 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

void	block_setter(t_map *m, int type, int c, char *path)
{
	m->f[m->size_y][m->size_x].coord.x = PIXEL_X * m->size_x;
	m->f[m->size_y][m->size_x].coord.y = PIXEL_Y * m->size_y;
	m->f[m->size_y][m->size_x].type = type;
	m->f[m->size_y][m->size_x].path = path;
	(void)c;
}

void	block_spliter(t_map *m)
{
	m->size_x = -1;
	while ((m->l)[++m->size_x])
	{
		if ((m->l)[m->size_x] == WALL)
			block_setter(m, WALL, 0, IMAGE_WALL);
		else if ((m->l)[m->size_x] == PLAYER)
			block_setter(m, PLAYER, m->p++, IMAGE_PLAYER);
		else if ((m->l)[m->size_x] == EXIT)
			block_setter(m, EXIT, m->e++, IMAGE_EXIT);
		else if ((m->l)[m->size_x] == COIN)
			block_setter(m, COIN, m->c++, IMAGE_COIN);
		else if ((m->l)[m->size_x] == EMPTY)
			block_setter(m, EMPTY, 0, IMAGE_EMPTY);
		else if ((m->l)[m->size_x] == MONSTER)
			block_setter(m, MONSTER, 0, IMAGE_MONSTER);
		else
			ft_error_disposal(m, OTHER);
		m->count++;
	}
	m->size_y++;
}

void	component_checker(t_map *m)
{
	int	c;
	int	r;

	c = -1;
	r = -1;
	while (++c < m->column)
	{
		while (++r < m->row)
		{
			if (m->f[c][r].type != 49)
				if (m->f[c][r].coord.y == 0 || m->f[c][r].coord.y == m->column
					|| m->f[c][r].coord.x == 0 || m->f[c][r].coord.x == m->row)
					ft_error_disposal(m, NOWALL);
			if (m->p == 0 || m->p > 1)
				ft_error_disposal(m, PLAYERERROR);
			else if (m->c == 0)
				ft_error_disposal(m, COINERROR);
			else if (m->e == 0)
				ft_error_disposal(m, EXITERROR);
			else if (m->row * m->column != m->count)
				ft_error_disposal(m, RECERROR);
		}
		r = -1;
	}
}

void	map_validator(t_map *m)
{
	int		fd;

	fd = open(m->map_path, O_RDONLY);
	if (fd == -1)
		ft_error_disposal(m, MALERROR);
	while (m->g_l != 0)
	{
		m->g_l = ft_get_next_line(fd, &(m->l));
		if (m->g_l == -1)
			ft_error_disposal(m, GNLERROR);
		block_spliter(m);
		ft_free(m->l);
	}
	close(fd);
	component_checker(m);
}
