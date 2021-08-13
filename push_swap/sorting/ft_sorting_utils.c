/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:14:25 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/13 16:08:06 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int ft_get_place(stack *s_a, int v)
{
	int place;
	int indicator;
	int start;
	node *tmp_n;

	place = 0;
	indicator = 0;
	start = 0;
	tmp_n = s_a->head;
	if (s_a->count > 1)
	{
		start = ft_get_the_smallest_num(s_a);
		while (tmp_n->value != start)
			tmp_n = tmp_n->next;
		while (++place < s_a->count + 1)
		{
			if (tmp_n->value > v)
				break;
			tmp_n = tmp_n->next;
		}
		indicator = tmp_n->prev->value;
		place = 0;
		tmp_n = s_a->head;
		while (tmp_n->value != indicator)
		{
			place++;
			tmp_n = tmp_n->next;
		}
		place = place + 2;
	}
	else
		place = 1;
	return (place);
}

void ft_insert_el(stack *s_a, stack *s_b, int place, int v)
{
	int i;
	node *node;

	i = -1;
	node = s_b->head;
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

void ft_agamotto_eye(stack *s_a, stack *s_b)
{
	int i;
	int cur_place;
	int tmp_cost;
	int cur_cost;
	int tmp_place;
	node *cur_result;
	node *tmp_result;

	i = 0;
	cur_place = 0;
	tmp_cost = 0;
	cur_cost = 0;
	tmp_place = 0;
	cur_result = s_b->head;
	tmp_result = 0;
	while (++i <= s_b->count)
	{
		cur_place = ft_get_place(s_a, cur_result->value);
		cur_cost = ft_best_future(s_a, s_b, cur_place, cur_result->value);
		if (!(tmp_cost) || tmp_cost > cur_cost)
		{
			tmp_cost = cur_cost;
			tmp_result = cur_result;
			tmp_place = cur_place;
		}
		cur_result = cur_result->next;
	}
	ft_insert_el(s_a, s_b, tmp_place, tmp_result->value);
}
