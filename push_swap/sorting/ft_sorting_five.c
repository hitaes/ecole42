/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:11:15 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/14 13:00:53 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_sorting_five(stack *s_a, stack *s_b)
{
	int start;

	start = ft_get_the_smallest_num(s_a);
	pb(s_a, s_b);
	pb(s_a, s_b);
	ft_sorting_three(s_a);
	while (s_b->count)
		ft_agamotto_eye(s_a, s_b);
	if (s_a->count + 1 / 2 < ft_get_place(s_a, start))
		while (s_a->head->value != start)
			rra(s_a);
	else
		while (s_a->head->value != start)
			ra(s_a);
}
