/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:04:59 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/12 19:47:32 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/shared.h"

void	coordinate_setter(t_map *m, int type, int c)
{
	int		j;
	t_block	*tmp;

	j = -1;
	tmp = (t_block *)malloc(sizeof(t_block) * (m->count + 1));
	if (tmp == NULL)
		ft_error_disposal();
	while (++j < m->count)
	{
		tmp[j] = m->b_l[j];
		tmp[j].index = j;
	}
	if (m->b_l)
		ft_free(m->b_l);
	tmp[j].type = type;
	tmp[j].coord.x = 64 * m->size_x;
	tmp[j].coord.y = 64 * m->size_y;
	tmp[j].index = j;
	m->b_l = tmp;
	(void)c;
}

void	block_setter(t_map *m)
{
	m->size_x = -1;
	while ((m->l)[++(m->size_x)])
	{
		if ((m->l)[m->size_x] == 49)
			coordinate_setter(m, 49, 0);
		else if ((m->l)[m->size_x] == 80)
			coordinate_setter(m, 80, m->p++);
		else if ((m->l)[m->size_x] == 69)
			coordinate_setter(m, 69, m->e++);
		else if ((m->l)[m->size_x] == 67)
			coordinate_setter(m, 67, m->c++);
		else if ((m->l)[m->size_x] == 48)
			coordinate_setter(m, 48, 0);
		m->count++;
	}
	m->size_y++;
}

void	component_checker(t_map *m)
{
	int	j;

	j = -1;
	while (++j < m->count)
	{
		if (m->b_l[j].type != 49)
		{
			if (m->b_l[j].coord.y == 0)
				ft_error_disposal();
			else if (m->b_l[j].coord.y == m->size_y)
				ft_error_disposal();
			else if (m->b_l[j].coord.x == 0)
				ft_error_disposal();
			else if (m->b_l[j].coord.x == m->size_x)
				ft_error_disposal();
		}
		if (m->p == 0 || m->c == 0 || m->e == 0
			|| m->size_x * m->size_y != m->count)
			ft_error_disposal();
	}
}

void	map_validator(t_map *m)
{
	int		fd;

	map_init(m);
	fd = open(FILE_MAP, O_RDONLY);
	if (fd == -1)
		ft_error_disposal();
	while (m->g_l != 0)
	{
		m->g_l = ft_get_next_line(fd, &(m->l));
		if (m->g_l == -1)
			ft_error_disposal();
		block_setter(m);
	}
	component_checker(m);
}
