/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:00:25 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/30 02:21:48 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sa(stack *stk)
{
	node *n;

	n = ft_export_node(stk->head);
	if (stk->count >= 2)
	{
		stk->head = stk->head->next;
		stk->head->next = n;
		stk->head->prev = stk->tail;
		n->next = stk->tail;
		n->prev = stk->head;
		stk->tail->prev = stk->head;
		printf("sa\n");
	}
}

void sb(stack *stk)
{
	node *n;

	n = ft_export_node(stk->head);
	if (stk->count >= 2)
	{
		stk->head = stk->head->next;
		stk->head->next = n;
		stk->head->prev = stk->tail;
		n->next = stk->tail;
		n->prev = stk->head;
		stk->tail->prev = stk->head;
		printf("sb\n");
	}
}

void ss(stack *l_stk, stack *r_stk)
{
	node *l_n;
	node *r_n;

	l_n = ft_export_node(l_stk->head);
	r_n = ft_export_node(r_stk->head);
	if (l_stk->count >= 2 && r_stk->count >= 2)
	{
		l_stk->head = l_stk->head->next;
		l_stk->head->next = l_n;
		l_stk->head->prev = l_stk->tail;
		l_n->next = l_stk->tail;
		l_n->prev = l_stk->head;
		l_stk->tail->prev = l_stk->head;
		r_stk->head = r_stk->head->next;
		r_stk->head->next = r_n;
		r_stk->head->prev = r_stk->tail;
		r_n->next = r_stk->tail;
		r_n->prev = r_stk->head;
		r_stk->tail->prev = r_stk->head;
		printf("ss\n");
	}
}
