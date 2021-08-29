/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 02:11:48 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/29 23:53:16 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	rra(t_stack *stk, int fd)
{
	if (stk->count >= 2)
	{
		stk->head = stk->tail;
		stk->tail = stk->tail->prev;
		if (fd == 1)
			ft_putstr_fd("rra\n", fd);
	}
	return (1);
}

int	rrb(t_stack *stk, int fd)
{
	if (stk->count >= 2)
	{
		stk->head = stk->tail;
		stk->tail = stk->tail->prev;
		if (fd == 1)
			ft_putstr_fd("rrb\n", fd);
	}
	return (1);
}

int	rrr(t_stack *l_stk, t_stack *r_stk, int fd)
{
	if (l_stk->count >= 2 && r_stk->count >= 2)
	{
		l_stk->head = l_stk->tail;
		l_stk->tail = l_stk->tail->prev;
		r_stk->head = r_stk->tail;
		r_stk->tail = r_stk->tail->prev;
		if (fd == 1)
			ft_putstr_fd("rrr\n", fd);
	}
	return (1);
}
