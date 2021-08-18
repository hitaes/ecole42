/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_setter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 00:56:14 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/18 10:46:13 by pac-man          ###   ########.fr       */
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

void stack_init(stack *stk, node *new_node)
{
	if (!(stk->head))
		stk->head = new_node;
	else
	{
		if (!(stk->tail))
		{
			stk->tail = new_node;
			stk->head->next = stk->tail;
			stk->tail->prev = stk->head;
		}
		else
		{
			new_node->prev = stk->tail;
			stk->tail->next = new_node;
			stk->tail = new_node;
		}
		stk->head->prev = stk->tail;
		stk->tail->next = stk->head;
	}
	stk->count++;
}

void node_setter(stack *s_a, int the_number_of_els, int *v_nums)
{
	int i;

	i = -1;
	while (++i < the_number_of_els)
		stack_init(s_a, create_node(*(v_nums + i)));
}
