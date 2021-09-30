/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:47:57 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/29 23:51:56 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	pb(t_stack *from, t_stack *to, int fd)
{
	if (from->count)
	{
		ft_append_t_node(to, from->head);
		ft_remove_t_node(from);
		if (fd == 1)
			ft_putstr_fd("pb\n", fd);
	}
	return (1);
}

int	pa(t_stack *from, t_stack *to, int fd)
{
	if (from->count)
	{
		ft_append_t_node(to, from->head);
		ft_remove_t_node(from);
		if (fd == 1)
			ft_putstr_fd("pa\n", fd);
	}
	return (1);
}

int	pp(t_stack *from, t_stack *to, int fd)
{
	t_node	*tmp_from;
	t_node	*tmp_to;

	tmp_from = from->head;
	tmp_to = to->head;
	if (from->count && to->count)
	{
		ft_remove_t_node(from);
		ft_remove_t_node(to);
		ft_append_t_node(to, tmp_from);
		ft_append_t_node(from, tmp_to);
		if (fd == 1)
			ft_putstr_fd("pp\n", fd);
	}
	return (1);
}
