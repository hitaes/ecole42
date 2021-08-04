/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:10:24 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/04 17:53:19 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_sorting_two(stack *s_a)
{
	if (s_a->head->value > s_a->head->next->value)
		sa(s_a);
}

void ft_sorting_three(stack *s_a)
{
	int count;

	count = s_a->count;
	while (count--)
		if (s_a->head->value > s_a->head->next->value)
			sa(s_a);
		else if (s_a->head->next->value > s_a->head->next->next->value)
		{
			rra(s_a);
			if (s_a->head->value > s_a->head->next->value)
				sa(s_a);
		}
}

void ft_combine(stack *s_a, stack *s_b, int count)
{
	printf("✅start!\n");
	int total_length;
	int ra_count;
	int i;

	total_length = s_a->count + s_b->count;
	ra_count = 0;
	i = -1;
	if (s_a->head->value < s_b->head->value)
	{
		rb(s_b);
	}
	else
	{
		ra(s_a);
		ra_count++;
	}
	while (count-- > 1)
		ft_combine(s_a, s_b, count);
	pa(s_b, s_a);
	// while (++i < (total_length - ra_count))
	// 	ra(s_a);
}

void ft_swap_reverse_double(stack *s_a, stack *s_b)
{
	ss(s_a, s_b);
	rr(s_a, s_b);
	rr(s_a, s_b);
}

void ft_swap_reverse_s_a(stack *s_a)
{
	sa(s_a);
	ra(s_a);
	ra(s_a);
}

void ft_swap_reverse_s_b(stack *s_b)
{
	sb(s_b);
	rb(s_b);
	rb(s_b);
}

void ft_swap_node(stack *s_a, stack *s_b, int count)
{
	int i;

	i = -1;
	while (++i < count)
	{
		if (s_a->head->value > s_a->head->next->value)
			if (s_b->head->value < s_b->head->next->value)
				ft_swap_reverse_double(s_a, s_b);
		if (s_a->head->value > s_a->head->next->value)
			ft_swap_reverse_s_a(s_a);
		if (s_b->head->value < s_b->head->next->value)
			ft_swap_reverse_s_b(s_b);
	}
}

void ft_sorting_four(stack *s_a, stack *s_b)
{
	int i;
	int j;
	int tmp_count;

	i = 0;
	j = 0;
	tmp_count = s_a->count;
	while (++i <= tmp_count / 2)
		pb(s_a, s_b);
	ft_swap_node(s_a, s_b, s_a->count / 2);
	ft_combine(s_a, s_b, s_a->count);
	// while (++j <= s_a->count / 2)
	// 	ra(s_a);
}

void ft_sorting_all(stack *s_a, stack *s_b)
{
	int i;
	int tmp_count;

	i = 0;
	tmp_count = s_a->count;
	while (++i <= tmp_count / 2)
		pb(s_a, s_b);
	ft_swap_node(s_a, s_b, s_a->count / 2);
	// ft_combine(s_a, s_b, s_a->count);
}

void ft_sorting(stack *s_a, stack *s_b)
{
	if (s_a->count == 2)
		ft_sorting_two(s_a);
	else if (s_a->count == 3)
		ft_sorting_three(s_a);
	else if (s_a->count == 4)
		ft_sorting_four(s_a, s_b);
	else
		ft_sorting_all(s_a, s_b);
}
