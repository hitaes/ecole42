/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:47:57 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/27 17:27:06 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	pb(t_stack *from, t_stack *to)
{
	if (from->count)
	{
		ft_append_t_node(to, from->head);
		ft_remove_t_node(from);
		ft_putstr_fd("pb\n", 1);
	}
}

void	pa(t_stack *from, t_stack *to)
{
	if (from->count)
	{
		ft_append_t_node(to, from->head);
		ft_remove_t_node(from);
		ft_putstr_fd("pa\n", 1);
	}
}

void	pp(t_stack *from, t_stack *to)
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
		ft_putstr_fd("pp\n", 1);
	}
}
