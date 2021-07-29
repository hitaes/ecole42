/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:25:00 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/29 17:11:36 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_remove_node(stack *s_a, node *n)
{
	if (s_a->head == n)
	{
		s_a->head = n->next;
		if (s_a->head != NULL)
			s_a->head->prev = NULL;
		n->next = NULL;
		n->prev = NULL;
	}
	else
	{
		node *temp = n;
		n->prev->next = temp->next;
		if (n->next != NULL)
			n->next->prev = temp->prev;
		n->next = NULL;
		n->prev = NULL;
	}
	s_a->count--;
	// // printf("✅%d\n", s_a->count);
	// // printf("✅%d\n", s_b->count);
	// node *tmp_node;

	// tmp_node = s_a->head;
	// s_a->head = s_a->head->next;
	// s_a->head->prev = s_a->tail;
	// s_a->tail->next = s_a->head;
	// if (s_b->count == 1)
	// {
	// 	tmp_node->next = 0;
	// 	tmp_node->prev = 0;
	// }
	// // else if (s_a->count == 2)
	// // {
	// // 	s_a->head->prev = 0;
	// // 	s_a->tail->next = 0;
	// // 	s_a->tail = 0;
	// // }
	// // else if (s_a->count == 1)
	// // {
	// // 	s_a->head->prev = 0;
	// // 	s_a->head->next = 0;
	// // 	s_a->head = 0;
	// // }
	// s_a->count--;
}
