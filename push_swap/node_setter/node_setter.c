/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_setter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 00:56:14 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/24 00:17:25 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

node *create_node(int v_num)
{
	node *n;

	n = (node *)malloc(sizeof(node));
	if (!(n))
		return NULL;
	n->value = v_num;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}

void append_node(stack *s_a, node *new_node)
{
	if (!(s_a->tail))
		s_a->tail = new_node;
	else
	{
		if (!(s_a->head))
		{
			s_a->head = new_node;
			new_node->next = s_a->tail;
			s_a->tail->prev = new_node;
		}
		else
		{
			new_node->next = s_a->head;
			s_a->head->prev = new_node;
			s_a->head = new_node;
		}
	}
}

stack *node_setter(stack *s_a, int count, int *v_nums)
{
	int i;
	node *n;

	i = -1;
	while (count - ++i)
	{
		n = create_node(*(v_nums + i));
		append_node(s_a, n);
	}
	return(s_a);
}
