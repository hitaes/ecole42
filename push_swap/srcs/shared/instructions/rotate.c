/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 02:11:48 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/27 17:28:20 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	ra(t_stack *stk)
{
	if (stk->count >= 2)
	{
		stk->tail = stk->head;
		stk->head = stk->head->next;
		ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_stack *stk)
{
	if (stk->count >= 2)
	{
		stk->tail = stk->head;
		stk->head = stk->head->next;
		ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_stack *l_stk, t_stack *r_stk)
{
	if (l_stk->count >= 2 && r_stk->count >= 2)
	{
		l_stk->tail = l_stk->head;
		l_stk->head = l_stk->head->next;
		r_stk->tail = r_stk->head;
		r_stk->head = r_stk->head->next;
		ft_putstr_fd("rr\n", 1);
	}
}
