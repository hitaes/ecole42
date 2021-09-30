/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 02:11:48 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/29 23:52:57 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	ra(t_stack *stk, int fd)
{
	if (stk->count >= 2)
	{
		stk->tail = stk->head;
		stk->head = stk->head->next;
		if (fd == 1)
			ft_putstr_fd("ra\n", fd);
	}
	return (1);
}

int	rb(t_stack *stk, int fd)
{
	if (stk->count >= 2)
	{
		stk->tail = stk->head;
		stk->head = stk->head->next;
		if (fd == 1)
			ft_putstr_fd("rb\n", fd);
	}
	return (1);
}

int	rr(t_stack *l_stk, t_stack *r_stk, int fd)
{
	if (l_stk->count >= 2 && r_stk->count >= 2)
	{
		l_stk->tail = l_stk->head;
		l_stk->head = l_stk->head->next;
		r_stk->tail = r_stk->head;
		r_stk->head = r_stk->head->next;
		if (fd == 1)
			ft_putstr_fd("rr\n", fd);
	}
	return (1);
}
