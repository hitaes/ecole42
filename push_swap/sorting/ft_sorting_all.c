/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:12:38 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/25 18:05:32 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_get_sequence(t_stack *stk)
{
	t_stack	tmp_s;

	tmp_s = *stk;
	tmp_s.s_index = stk->head->value;
	while (tmp_s.head->value != stk->tail->value)
	{
		if (tmp_s.head->value > tmp_s.head->next->value)
		{
			if (tmp_s.s_count > stk->s_count)
			{
				stk->s_count = tmp_s.s_count;
				stk->s_index = tmp_s.s_index;
			}
			tmp_s.s_index = tmp_s.head->next->value;
			tmp_s.s_count = 1;
		}
		else
			tmp_s.s_count++;
		tmp_s.head = tmp_s.head->next;
	}
	if (tmp_s.s_count > stk->s_count)
	{
		stk->s_count = tmp_s.s_count;
		stk->s_index = tmp_s.s_index;
	}
}

int	ft_make_remaining(t_stack *s_a, t_stack *s_b)
{
	int	counter;
	int	p_counter;
	int	s_counter;

	counter = s_a->count - s_a->s_count + 2;
	p_counter = 0;
	s_counter = s_a->s_count + 1;
	while (--counter)
	{
		if (s_a->head->value == s_a->s_index)
			while (--s_counter)
				ra(s_a);
		else
		{
			pb(s_a, s_b);
			p_counter++;
		}
	}
	return (p_counter);
}

void	ft_sorting_all(t_stack *s_a, t_stack *s_b)
{
	int		counter;
	int		place;
	double	weight;
	int		p_counter;

	weight = 1.1;
	place = 0;
	counter = (s_a->count / weight) + 1;
	while (--counter)
		ft_agamotto_eye(s_b, s_a, 'd', s_a->count);
	ft_to_base(s_b, 'd');
	ft_get_sequence(s_a);
	p_counter = ft_make_remaining(s_a, s_b);
	while (--p_counter)
	{
		place = ft_get_place(s_a, s_b->head->value, 'a');
		ft_insert_el(s_a, s_b, place, s_b->head->value);
	}
	while (s_b->count)
		ft_agamotto_eye(s_a, s_b, 'a', s_b->count);
	ft_to_base(s_a, 'a');
}
