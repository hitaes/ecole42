/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:11:15 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/12 17:57:23 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int ft_get_place(stack *s_a, int v)
// {
// 	int place;
// 	node *tmp_n;

// 	place = 0;
// 	tmp_n = s_a->head;
// 	while (++place < s_a->count + 1)
// 	{
// 		if (tmp_n->value > v)
// 			break;
// 		tmp_n = tmp_n->next;
// 	}
// 	printf("✅v: %d, place: %d\n", v, place);
// 	return (place);
// }

int ft_get_place(stack *s_a, node *head, int v, int start)
{
	int place;
	int indicator;
	node *tmp_n;

	place = 0;
	tmp_n = head;
	indicator = 0;
	if (s_a->count > 2)
	{
		while (tmp_n->value != start)
			tmp_n = tmp_n->next;
		while (++place < s_a->count + 1)
		{
			if (tmp_n->value > v)
				break;
			tmp_n = tmp_n->next;
		}
		place = 0;
		indicator = tmp_n->prev->value;
		tmp_n = head;
		while (tmp_n->value != indicator)
		{
			place++;
			tmp_n = tmp_n->next;
		}
	}
	else
		place = 1;
	printf("✅v: %d, place: %d\n", v, place);
	return (place);
}

int ft_get_the_smallest_num(stack *s_a)
{
	int i;
	int mini;
	node *tmp_n;

	i = -1;
	tmp_n = s_a->head;
	mini = tmp_n->value;
	while (++i < s_a->count)
	{
		tmp_n = tmp_n->next;
		if (mini > tmp_n->value)
			mini = tmp_n->value;
	}
	return (mini);
}

// void ft_insert_el(stack *s_a, stack *s_b, int place, int v)
// {
// 	int rotate_count;
// 	node *node;
// 	int i;

// 	rotate_count = 0;
// 	node = s_b->head;
// 	i = -1;
// 	while (node->value != v && s_b->count >= 2)
// 	{
// 		rb(s_b);
// 		node = node->next;
// 	}
// 	if (s_a->count / 2 < place)
// 	{
// 		rotate_count = 1;
// 		while (s_a->count + 1 > place + ++i)
// 		{
// 			rra(s_a);
// 			rotate_count++;
// 		}
// 		pa(s_b, s_a);
// 		while (s_a->count > 1 && --rotate_count >= 0)
// 			ra(s_a);
// 	}
// 	else
// 	{
// 		while (--place)
// 		{
// 			ra(s_a);
// 			rotate_count++;
// 		}
// 		pa(s_b, s_a);
// 		while (s_a->count > 1 && rotate_count--)
// 			rra(s_a);
// 	}
// }
// int ft_best_future(stack *s_a, stack *s_b, int place, int v)
// {
// 	int rotate_count;
// 	node *node;
// 	int i;
// 	int cost;

// 	rotate_count = 0;
// 	node = s_b->head;
// 	i = -1;
// 	cost = 0;
// 	while (node->value != v && s_b->count >= 2)
// 	{
// 		cost++;
// 		node = node->next;
// 	}
// 	if (s_a->count / 2 < place)
// 	{
// 		rotate_count = 1;
// 		while (s_a->count + 1 > place + ++i)
// 		{
// 			cost++;
// 			rotate_count++;
// 		}
// 		cost++;
// 		while (s_a->count > 1 && --rotate_count >= 0)
// 			cost++;
// 	}
// 	else
// 	{
// 		while (--place)
// 		{
// 			cost++;
// 			rotate_count++;
// 		}
// 		cost++;
// 		while (s_a->count > 1 && rotate_count--)
// 			cost++;
// 	}
// 	return (cost);
// }
void ft_insert_el(stack *s_a, stack *s_b, int place, int v)
{
	node *node;
	int i;

	node = s_b->head;
	i = -1;
	while (node->value != v && s_b->count >= 2)
	{
		rb(s_b);
		node = node->next;
	}
	if (s_a->count / 2 < place)
	{
		while (s_a->count + 1 > place + ++i)
			rra(s_a);
		pa(s_b, s_a);
	}
	else
	{
		while (--place)
			ra(s_a);
		pa(s_b, s_a);
	}
}
int ft_best_future(stack *s_a, stack *s_b, int place, int v)
{
	int i;
	int cost;
	node *node;

	i = -1;
	cost = 0;
	node = s_b->head;
	while (node->value != v && s_b->count >= 2)
	{
		cost++;
		node = node->next;
	}
	if (s_a->count / 2 < place)
	{
		while (s_a->count + 1 > place + ++i)
			cost++;
		cost++;
	}
	else
	{
		while (--place)
			cost++;
		cost++;
	}
	return (cost);
}

void ft_agamotto_eye(stack *s_a, stack *s_b, int start)
{
	int i;
	int place;
	int tmp_cost;
	int cur_cost;
	int result_place;
	node *tmp_result;
	node *tmp_future;

	i = 0;
	place = 0;
	tmp_cost = 100000;
	cur_cost = 0;
	result_place = 0;
	tmp_result = s_b->head;
	tmp_future = 0;
	while (++i <= s_b->count)
	{
		place = ft_get_place(s_a, s_a->head, tmp_result->value, start);
		// printf("✅place: %d, tmp_result: %d\n", place, tmp_result->value);
		cur_cost = ft_best_future(s_a, s_b, place, tmp_result->value);
		if (tmp_cost > cur_cost)
		{
			tmp_cost = cur_cost;
			tmp_future = tmp_result;
			// printf("✅cost: %d\n", tmp_cost);
			result_place = ft_get_place(s_a, s_a->head, tmp_future->value, start);
		}
		tmp_result = tmp_result->next;
	}
	ft_insert_el(s_a, s_b, result_place, tmp_future->value);
}

void ft_sorting_five(stack *s_a, stack *s_b)
{
	int start;

	start = ft_get_the_smallest_num(s_a);
	while (s_a->count)
		pb(s_a, s_b);
	while (s_b->count)
		ft_agamotto_eye(s_a, s_b, start);
	while (s_a->head->value != start)
		ra(s_a);
}
