/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:12:38 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/17 17:58:03 by pac-man          ###   ########.fr       */
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
	int i;
	char direction;
	int the_number_of_els;

	i = -1;
	direction = 'd';
	the_number_of_els = s_a->count;
	while (++i < the_number_of_els / 2)
		ft_agamotto_eye(s_b, s_a, direction);
	ft_to_base(s_b, direction);
	while (s_a->count)
		pb(s_a, s_b);
	direction = 'a';
	while (i++ < the_number_of_els)
		ft_agamotto_eye(s_a, s_b, direction);
	// ft_to_base(s_a, direction);
	// while (s_b->count)
	// 	pa(s_b, s_a);
	// ft_to_base(s_a, direction);
}
