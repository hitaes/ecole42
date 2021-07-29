/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:47:57 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/29 17:11:07 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pb(stack *s_a, stack *s_b)
{
	ft_append_node(s_b, s_a->head);
	ft_remove_node(s_a, s_a->head);
}

// void pb1(stack *s_a, stack *s_b)
// {
// 	// ft_append_node(s_b, s_a->head);
// 	// s_a->head = s_a->head->next;

// 	// ===========================s_a 5 s_b 0============================
// 	// 1.1 s_b
// 	s_b->tail = s_a->head;
// 	// 1.2 s_a
// 	s_a->head = s_a->head->next;
// 	s_a->head->prev = s_a->tail;
// 	s_a->tail->next = s_a->head;
// 	// 1.3 s_b
// 	s_b->tail->prev = 0;
// 	s_b->tail->next = 0;
// 	// 실행될때마다 반복되는 부분
// 	s_a->count--;
// 	s_b->count++;
// }

// void pb2(stack *s_a, stack *s_b)
// {
// 	// ft_append_node(s_b, s_a->head);
// 	// s_a->head = s_a->head->next;

// 	// ===========================s_a 4 s_b 1============================
// 	// 2.1 s_b
// 	s_b->head = s_a->head;
// 	// 2.2 s_a
// 	s_a->head = s_a->head->next;
// 	s_a->head->prev = s_a->tail;
// 	s_a->tail->next = s_a->head;
// 	// 2.3 s_b
// 	s_b->tail->prev = s_b->head;
// 	s_b->tail->next = s_b->head;
// 	s_b->head->prev = s_b->tail;
// 	s_b->head->next = s_b->tail;
// 	// 실행될때마다 반복되는 부분
// 	s_a->count--;
// 	s_b->count++;
// }

// void pb3(stack *s_a, stack *s_b)
// {
// 	// ft_append_node(s_b, s_a->head);
// 	// s_a->head = s_a->head->next;

// 	// ============================s_a 3 s_b 2===========================
// 	// 이부분이 계속 반복됨
// 	// 3.1 s_b
// 	s_a->head->next = s_b->head;
// 	s_b->head = s_a->head;
// 	// 3.2 s_a
// 	s_a->head = s_a->head->next;
// 	s_a->head->prev = s_a->tail;
// 	s_a->tail->next = s_a->head;
// 	// 3.3 s_b
// 	s_b->head->prev = s_b->tail;
// 	s_b->tail->next = s_b->head;
// 	// 실행될때마다 반복되는 부분
// 	s_a->count--;
// 	s_b->count++;
// }

// void pb4(stack *s_a, stack *s_b)
// {
// 	// ft_append_node(s_b, s_a->head);
// 	// s_a->head = s_a->head->next;

// 	// ============================s_a 2 s_b 3===========================
// 	// 3.1 s_b
// 	s_a->head->next = s_b->head;
// 	s_b->head = s_a->head;
// 	// 3.2 s_a
// 	s_a->head = s_a->head->next;
// 	s_a->head->prev = 0;
// 	s_a->tail->next = 0;
// 	// 3.3 s_b
// 	s_b->head->prev = s_b->tail;
// 	s_b->tail->next = s_b->head;
// 	// 실행될때마다 반복되는 부분
// 	s_a->count--;
// 	s_b->count++;
// }

// void pb5(stack *s_a, stack *s_b)
// {
// 	// ft_append_node(s_b, s_a->head);
// 	// s_a->head = s_a->head->next;

// 	// ============================s_a 1 s_b 4===========================
// 	// 3.1 s_b
// 	s_a->head->next = s_b->head;
// 	s_b->head = s_a->head;
// 	s_b->head->prev = s_b->tail;
// 	s_b->tail->next = s_b->head;
// 	// 3.2 s_a
// 	s_a->head = 0;
// 	s_a->tail = 0;
// 	// 실행될때마다 반복되는 부분
// 	s_a->count--;
// 	s_b->count++;
// 	// ft_remove_node(s_a);
// }
