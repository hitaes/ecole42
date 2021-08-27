/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:46:03 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/27 13:06:15 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_t_candidate_init(t_candidate *c)
{
	c->cost = 0;
	c->place = 0;
	c->result = 0;
}

void	ft_top_setter(t_stack *to, t_stack *from, int place, int from_index)
{
	if ((from->count / 2) + 1 <= from_index && (to->count / 2) + 1 <= place)
	{
		if (place < from_index)
		{
			while (to->count > place++)
				rrr(from, to);
		}
		else
			while (from->count > from_index++)
				rrr(from, to);
	}
	else if ((from->count / 2) + 1 > from_index && (to->count / 2) + 1 > place)
	{
		if (place < from_index)
		{
			while (place--)
				rr(from, to);
		}
		else
			while (from_index--)
				rr(from, to);
	}
}

void	ft_insert_el(t_stack *to, t_stack *from, int place, int v)
{
	int	from_index;

	from_index = ft_get_index(from, v);
	ft_top_setter(to, from, place, from_index);
	from_index = ft_get_index(from, v);
	if ((from->count / 2) + 1 <= from_index)
		while (from->count > from_index++)
			rrb(from);
	else
		while (from_index--)
			rb(from);
	place = ft_get_place(to, v, 'a');
	if ((to->count / 2) + 1 <= place)
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

void	ft_insert_el_r(t_stack *to, t_stack *from, int place, int v)
{
	int	from_index;

	from_index = ft_get_index(from, v);
	ft_top_setter(to, from, place, from_index);
	from_index = ft_get_index(from, v);
	if ((from->count / 2) + 1 <= from_index)
		while (from->count > from_index++)
			rra(from);
	else
		while (from_index--)
			ra(from);
	place = ft_get_place(to, v, 'd');
	if ((to->count / 2) + 1 <= place)
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

void	ft_agamotto_eye(t_stack *to, t_stack *from, char direction, int range)
{
	int			i;
	t_candidate	tmp;
	t_candidate	cur;

	i = 0;
	ft_t_candidate_init(&tmp);
	ft_t_candidate_init(&cur);
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
