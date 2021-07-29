/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:25:00 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/30 02:06:09 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_remove_node(stack *stk)
{
	if (stk->count > 2)
	{
		stk->head = stk->head->next;
		stk->head->prev = stk->tail;
		stk->tail->next = stk->head;
	}
	else if (stk->count == 2)
	{
		stk->head = stk->tail;
		stk->head->prev = 0;
		stk->head->next = 0;
		stk->tail = 0;
	}
	else if (stk->count == 1)
		stk->head = 0;
	stk->count--;
}
