/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:03:17 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/29 17:40:53 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_append_node(stack *stk, node *new_node)
{
	if (!(stk->tail))
		stk->tail = new_node;
	else
	{
		if (!(stk->head))
		{
			stk->head = new_node;
			new_node->next = stk->tail;
			stk->tail->prev = new_node;
		}
		else
		{
			new_node->next = stk->head;
			stk->head->prev = new_node;
			stk->head = new_node;
		}
	}
	stk->count++;
}
