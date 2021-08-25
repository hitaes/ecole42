/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:46:03 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/25 02:34:31 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_to_base(stack *stk, char direction)
{
	int start;

	start = 0;
	if (direction == 'a')
	{
		start = ft_get_the_smallest_num(stk);
		if (stk->count / 2 <= ft_get_index(stk, start))
			while (stk->head->value != start)
				rra(stk);
		else
			while (stk->head->value != start)
				ra(stk);
	}
	else
	{
		start = ft_get_the_biggest_num(stk);
		if (stk->count / 2 <= ft_get_index(stk, start))
			while (stk->head->value != start)
				rrb(stk);
		else
			while (stk->head->value != start)
				rb(stk);
	}
}

void ft_candidate_init(candidate *c)
{
	c->cost = 0;
	c->place = 0;
	c->result = 0;
}
void ft_head_setter(stack *to, stack *from, int place, int v)
{
	int indicator;
	int from_index;

	indicator = from->count / 2;
	from_index = ft_get_index(from, v);
	if (indicator <= place && indicator <= from_index)
	{
		if (from_index <= place)
		{
			while (from->head->value != v)
				rrr(from, to);
		}
		else
			while (to->count > place++)
				rrr(from, to);

	}
	else if (indicator > place && indicator > from_index)
	{
		while (from->head->value != v)
			rr(from, to);
	}
}

void ft_insert_el(stack *to, stack *from, int place, int v)
{
	int from_index;

	// ft_head_setter(to, from, place, v);
	from_index = ft_get_index(from, v);
	if (from->count / 2 <= from_index)
		while (from->head->value != v)
			rrb(from);
	else
		while (from->head->value != v)
			rb(from);
	place = ft_get_place(to, v, 'a');
	if (to->count / 2 <= place)
	{
		while (to->count > place++)
			rra(to);
		pa(from, to);
	}
	else
	{
		while (place--)
			ra(to);
		pa(from, to);
	}
}

void ft_insert_el_r(stack *to, stack *from, int place, int v)
{
	int from_index;

	// ft_head_setter(to, from, place, v);
	from_index = ft_get_index(from, v);
	if (from->count / 2 <= from_index)
	{
		while (from->head->value != v)
			rra(from);
	}
	else
		while (from->head->value != v)
			ra(from);
	place = ft_get_place(to, v, 'd');
	if (to->count / 2 <= place)
	{
		while (to->count > place++)
			rrb(to);
		pb(from, to);
	}
	else
	{
		while (place--)
			rb(to);
		pb(from, to);
	}
}

int ft_sequence_checker(stack *stk, int v)
{
	int check;
	int i;

	check = 1;
	i = -1;
	while (++i < stk->s_list_count)
		if (v == stk->s_list[i])
			return (0);
	return (check);
}

void ft_agamotto_eye(stack *to, stack *from, char direction, int range)
{
	int i;
	candidate tmp;
	candidate cur;

	i = 0;
	ft_candidate_init(&tmp);
	ft_candidate_init(&cur);
	cur.result = from->head;
	while (++i <= range)
	{
		cur.place = ft_get_place(to, cur.result->value, direction);
		cur.cost = ft_best_future(to, from, cur.place, cur.result->value);
		if ((!(tmp.cost) || tmp.cost > cur.cost))
		{
			tmp.place = cur.place;
			tmp.result = cur.result;
			tmp.cost = cur.cost;
		}
		cur.result = cur.result->next;
	}
	if (direction == 'a')
		ft_insert_el(to, from, tmp.place, tmp.result->value);
	else
		ft_insert_el_r(to, from, tmp.place, tmp.result->value);
}
