/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:12:38 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/17 22:20:12 by pac-man          ###   ########.fr       */
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
		if ((stk->count + 1) / 2 <= ft_get_index(stk, start))
			while (stk->head->value != start)
				rra(stk);
		else
			while (stk->head->value != start)
				ra(stk);
	}
	else
	{
		start = ft_get_the_biggest_num(stk);
		if ((stk->count + 1) / 2 <= ft_get_index(stk, start))
			while (stk->head->value != start)
				rrb(stk);
		else
			while (stk->head->value != start)
				rb(stk);
	}
}

void ft_sorting_all(stack *s_a, stack *s_b)
{
	int counter;
	char direction;

	counter = s_a->count;
	direction = 'd';
	// s_a->count = counter / 2;
	// while (s_a->count)
	// 	ft_agamotto_eye(s_b, s_a, direction, s_a->count);
	// ft_to_base(s_b, direction);
	// s_a->count = counter - s_b->count;
	// while (s_a->count)
	// 	pb(s_a, s_b);

	// int counter;
	// char direction;

	// counter = 0;
	// direction = 'd';
	while (s_a->count)
		ft_agamotto_eye(s_b, s_a, direction, s_a->count);
	ft_to_base(s_b, direction);
	while (s_b->count)
		pa(s_b, s_a);

	// while (s_a->count)
	// {
	// 	ft_agamotto_eye(s_b, s_a, direction, s_a->count);
	// 	counter++;
	// }
	// s_a->count = counter;
	// while (s_a->count)
	// 	pb(s_a, s_b);
	// // s_b->count = counter;
	// // direction = 'a';
	// // while (s_b->count)
	// // 	ft_agamotto_eye(s_a, s_b, direction, s_b->count);
	// // s_b->count = counter;

	// // printf("✅s_a->head->value: %d, s_b->head->value: %d\n", s_a->head->value, s_b->head->value);
}
