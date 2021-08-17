/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:46:03 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/17 17:52:10 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_best_future(stack *to, stack *from, int place, int v)
{
	int cost;
	int b_place;

	b_place = ft_get_index(from, v);
	cost = (from->count + 1) / 2 <= b_place ? from->count - b_place : b_place;
	if ((to->count + 1) / 2 <= place)
	{
		while (to->count > place++)
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

void ft_candidate_init(candidate *c)
{
	c->cost = 0;
	c->place = 0;
	c->result = 0;
}

void ft_insert_el(stack *to, stack *from, int place, int v)
{
	if ((from->count + 1) <= ft_get_index(from, v))
		while (from->head->value != v)
			rrb(from);
	else
		while (from->head->value != v)
			rb(from);
	if ((to->count + 1) / 2 <= place)
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
	if ((from->count + 1) / 2 <= ft_get_index(from, v))
		while (from->head->value != v)
			rra(from);
	else
		while (from->head->value != v)
			ra(from);
	if ((to->count + 1) / 2 <= place)
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

void ft_agamotto_eye(stack *to, stack *from, char direction)
{
	int i;
	candidate tmp;
	candidate cur;

	i = 0;
	ft_candidate_init(&tmp);
	ft_candidate_init(&cur);
	cur.result = from->head;
	while (++i <= from->count)
	{
		cur.place = ft_get_place(to, cur.result->value, direction);
		cur.cost = ft_best_future(to, from, cur.place, cur.result->value);
		if (!(tmp.cost) || tmp.cost > cur.cost)
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
