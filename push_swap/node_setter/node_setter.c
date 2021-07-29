/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_setter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 00:56:14 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/29 15:34:20 by pac-man          ###   ########.fr       */
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

void node_setter(stack *s_a, int the_number_of_els, int *v_nums)
{
	int i;

	i = -1;
	while (++i < the_number_of_els)
		ft_append_node(s_a, create_node(*(v_nums + i)));
	s_a->head->prev = s_a->tail;
	s_a->tail->next = s_a->head;
}
