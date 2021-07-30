/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 02:11:48 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/30 16:55:13 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ra(stack *stk)
{
	if (stk->count >= 2)
	{
		stk->tail = stk->head;
		stk->head = stk->head->next;
		printf("ra\n");
	}
}

void rb(stack *stk)
{
	if (stk->count >= 2)
	{
		stk->tail = stk->head;
		stk->head = stk->head->next;
		printf("rb\n");
	}
}

void rr(stack *l_stk, stack *r_stk)
{
	if (l_stk->count >= 2 && r_stk->count >= 2)
	{
		l_stk->tail = l_stk->head;
		l_stk->head = l_stk->head->next;
		r_stk->tail = r_stk->head;
		r_stk->head = r_stk->head->next;
		printf("rr\n");
	}
}
