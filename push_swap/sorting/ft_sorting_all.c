/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:12:38 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/25 10:35:03 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_find_median(stack *stk)
{
	int i;
	int j;
	stack tmp_s;

	i = -1;
	j = -1;
	tmp_s.count = 0;
	tmp_s.head = stk->head;
	tmp_s.tail = stk->head;
	while (++i < stk->count)
	{
		while (++j < stk->count)
		{
			if (tmp_s.tail->value <= tmp_s.head->value)
				tmp_s.count++;
			tmp_s.head = tmp_s.head->next;
		}
		if (tmp_s.count == (stk->count / 2) + 1)
			stk->median = tmp_s.tail->value;
		tmp_s.count = 0;
		j = -1;
		tmp_s.tail = tmp_s.tail->next;
		tmp_s.head = stk->head;
	}
}

void ft_quick_sort(stack *s_a, stack *s_b)
{
	int counter;
	node *tmp_n;

	counter = s_b->count + 1;
	tmp_n = s_a->head;
	ft_find_median(s_a);
	while (--counter && s_b->count != 2)
	{
		if (tmp_n->value > s_a->median)
			pb(s_a, s_b);
		else
			tmp_n = tmp_n->next;
	}
	if (s_b->count != 2)
		ft_quick_sort(s_a, s_b);
}

void ft_fountation_setter(stack *s_a, stack *s_b)
{
	int counter;
	int rotation;

	counter = s_a->s_index + 1;
	rotation = s_a->s_count + 1;
	while (counter && --counter)
		pb(s_a, s_b);
	while (--rotation)
		ra(s_a);
	counter = s_a->count - s_a->s_count + 1;
	while (--counter)
		pb(s_a, s_b);
}

foundation ft_init_foundation(foundation *f)
{
	f->count = 1;
	f->index = 0;
	return (*f);
}

void ft_get_foundation(stack *stk)
{
	stack *tmp_s;

	tmp_s = stk;
	while (tmp_s->head != stk->tail)
	{
		if (tmp_s->head->value > tmp_s->head->next->value)
		{
			if (tmp_s->s_count > stk->s_count)
			{
				stk->s_count = tmp_s->s_count;
				stk->s_index = tmp_s->s_index;
			}
			tmp_s->s_count = 1;
			tmp_s->s_index = tmp_s->head->next->value;
		}
		else
			tmp_s->count++;
		tmp_s->head = tmp_s->head->next;
	}
	if (tmp_s->s_count > stk->s_count)
	{
		stk->s_count = tmp_s->s_count;
		stk->s_index = tmp_s->s_index;
	}
}

void ft_sorting_all(stack *s_a, stack *s_b)
{
	int counter;
	double weight;
	int place;
	// node *tmp_n;

	weight = 2;
	counter = (s_a->count / weight) + 1;
	place = 0;
	// tmp_n = s_a->head;
	// ft_find_median(s_a);
	// printf("✅s_a->s_index: %d, s_a->s_count: %d\n", s_a->s_index, s_a->s_count);

	// ft_fountation_setter(s_a, s_b);


	// while (s_a->count)
	// {
	// 	ft_agamotto_eye(s_b, s_a, 'd', s_a->count);
	// }

	ft_get_foundation(s_a);
	printf("✅s_a->s_index: %d, s_a->s_count: %d\n", s_a->s_index, s_a->s_count);
	while (--counter)
	{
		ft_agamotto_eye(s_b, s_a, 'd', s_a->count);
	}



	// ft_to_base(s_a, 'a');
	// counter = (s_b->count / weight) + 1;

	// while (--counter)
	// {
	// 	ft_agamotto_eye(s_a, s_b, 'a', counter);
	// }
	// counter = (s_b->count / weight) + 1;
	// while (--counter)
	// {
	// 	ft_agamotto_eye(s_a, s_b, 'a', counter);
	// }
	// counter = (s_b->count / weight) + 1;
	// while (--counter)
	// {
	// 	ft_agamotto_eye(s_a, s_b, 'a', counter);
	// }
	// counter = (s_b->count / weight) + 1;
	// while (--counter)
	// {
	// 	ft_agamotto_eye(s_a, s_b, 'a', counter);
	// }
	// while (s_b->count)
	// {
		// ft_agamotto_eye(s_a, s_b, 'a', s_b->count);
	// 	pa(s_b, s_a);
	// }
	// ft_to_base(s_a, 'a');
	// counter = (s_b->count / weight) + 1;
	// while (s_b->count)
	// {
	// 	ft_agamotto_eye(s_b, s_a, 'd', s_b->count);
	// }
	// counter = (s_b->count / weight) + 1;
	// while (s_b->count)
	// {
	// 	ft_agamotto_eye(s_b, s_a, 'd', s_b->count);
	// }
	// while (s_b->count)
	// {
	// 	pa(s_b, s_a);
	// }
	// ft_to_base(s_a, 'a');

	// while (s_b->count)
	// {
	// 	ft_agamotto_eye(s_a, s_b, 'a', s_b->count);
	// }
	// ft_to_base(s_a, 'a');
	// ft_find_median(s_a);
	// ft_quick_sort(s_a, s_b);
	// while (--counter)
	// {
	// 	ft_agamotto_eye(s_b, s_a, 'd', s_b->count);
	// }


	// counter = (s_b->count / 2) + 1;

	// printf("✅s_a->median: %d, counter: %d\n", s_a->median, counter);
	// while (--counter)
	// {
	// 	if (s_a->head->value > s_a->median)
	// 		ft_agamotto_eye(s_b, s_a, 'd', s_b->count);
	// 	else
	// 		tmp_n = tmp_n->next;
	// }

	// while (s_b->count)
	// 	ft_agamotto_eye(s_b, s_a, 'd', s_b->count);
}
