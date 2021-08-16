/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:14:25 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/16 17:42:01 by pac-man          ###   ########.fr       */
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
	while (++i < s_a->count - 2 && s_a->count >= 2)
	{
		tmp_n = tmp_n->next;
		if (mini > tmp_n->value)
			mini = tmp_n->value;
	}
	return (mini);
}

int ft_get_index(stack *stk, int v)
{
	int index;
	node *tmp_n;

	index = -1;
	tmp_n = stk->head;
	while (++index < stk->count)
	{
		if (tmp_n->value == v)
			break;
		tmp_n = tmp_n->next;
	}
	return (index);
}

int ft_get_place(stack *s_a, int v)
{
	int indicator;
	int start;
	node *tmp_n;

	indicator = 0;
	start = ft_get_the_smallest_num(s_a);
	tmp_n = s_a->head;
	if (s_a->count >= 2)
	{
		while (tmp_n->value != start)
			tmp_n = tmp_n->next;
		while (++indicator < s_a->count)
		{
			if (tmp_n->value > v)
				break;
			tmp_n = tmp_n->next;
		}
		indicator = ft_get_index(s_a, tmp_n->prev->value) + 1;
	}
	else
		indicator = 0;
	return (indicator);
}

void ft_insert_el(stack *s_a, stack *s_b, int place, int v)
{
	if (s_b->count / 2 <= ft_get_index(s_b, v))
		while (s_b->head->value != v)
			rra(s_b);
	else
		while (s_b->head->value != v)
			ra(s_b);
	if (s_a->count / 2 <= place)
	{
		while (s_a->count > place++)
			rra(s_a);
		pa(s_b, s_a);
	}
	else
	{
		while (place--)
			ra(s_a);
		pa(s_b, s_a);
	}
}

int ft_best_future(stack *s_a, stack *s_b, int place, int v)
{
	int cost;
	int b_place;

	b_place = ft_get_index(s_b, v);
	cost = s_b->count / 2 <= b_place ? s_b->count - b_place : b_place;
	if (s_a->count / 2 <= place)
	{
		while (s_a->count > place++)
			cost++;
		cost++;
	}
	else
	{
		while (place--)
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
	cur_cost = 0;
	tmp_cost = 0;
	cur_place = 0;
	tmp_place = 0;
	cur_result = s_b->head;
	tmp_result = 0;
	while (++i <= s_b->count)
	{
		cur_place = ft_get_place(s_a, cur_result->value);
		cur_cost = ft_best_future(s_a, s_b, cur_place, cur_result->value);
		if (!(tmp_cost) || tmp_cost > cur_cost)
		{
			tmp_place = cur_place;
			tmp_result = cur_result;
			tmp_cost = cur_cost;
		}
		cur_result = cur_result->next;
	}
	ft_insert_el(s_a, s_b, tmp_place, tmp_result->value);
}
