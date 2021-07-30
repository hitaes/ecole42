/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:03:17 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/30 11:21:15 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_append_node(stack *stk, node *new_node)
{
	node *tmp;

	tmp = ft_export_node(new_node);
	if (!(stk->head))
		stk->head = tmp;
	else
	{
		if (!(stk->tail))
		{
			stk->tail = stk->head;
			stk->head = tmp;
			stk->head->next = stk->tail;
			stk->tail->prev = stk->head;
		}
		else
		{
			tmp->next = stk->head;
			stk->head->prev = tmp;
			stk->head = tmp;
		}
		stk->head->prev = stk->tail;
		stk->tail->next = stk->head;
	}
	stk->count++;
}
