/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 02:11:48 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/08 20:21:01 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rra(stack *stk)
{
	if (stk->count >= 2)
	{
		stk->head = stk->tail;
		stk->tail = stk->tail->prev;
		ft_putstr("rra");
		ft_putchar('\n');
	}
}

void rrb(stack *stk)
{
	if (stk->count >= 2)
	{
		stk->head = stk->tail;
		stk->tail = stk->tail->prev;
		ft_putstr("rrb");
		ft_putchar('\n');
	}
}

void rrr(stack *l_stk, stack *r_stk)
{
	if (l_stk->count >= 2 && r_stk->count >= 2)
	{
		l_stk->head = l_stk->tail;
		l_stk->tail = l_stk->tail->prev;
		r_stk->head = r_stk->tail;
		r_stk->tail = r_stk->tail->prev;
		ft_putstr("rrr");
		ft_putchar('\n');
	}
}
