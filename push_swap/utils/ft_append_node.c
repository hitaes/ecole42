/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:03:17 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/18 11:48:44 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_append_node(stack *to, node *from)
{
	node *tmp;

	tmp = ft_export_node(from);
	if (!(to->head))
		to->head = tmp;
	else
	{
		if (!(to->tail))
		{
			to->tail = to->head;
			to->head = tmp;
			to->head->next = to->tail;
			to->tail->prev = to->head;
		}
		else
		{
			tmp->next = to->head;
			to->head->prev = tmp;
			to->head = tmp;
		}
		to->head->prev = to->tail;
		to->tail->next = to->head;
	}
	to->count++;
}
