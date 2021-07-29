/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 02:11:48 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/30 02:25:09 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rra(stack *stk)
{
	if (stk->count >= 2)
	{
		stk->head = stk->tail;
		stk->tail = stk->tail->prev;
		printf("rra");
	}
}

void rrb(stack *stk)
{
	if (stk->count >= 2)
	{
		stk->head = stk->tail;
		stk->tail = stk->tail->prev;
		printf("rrb");
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
		printf("rrr");
	}
}
