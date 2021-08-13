/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:12:38 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/13 17:31:01 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_sorting_all(stack *s_a, stack *s_b)
{
	int i;
	int start;
	int the_number_of_els;

	i = -1;
	start = ft_get_the_smallest_num(s_a);
	the_number_of_els = s_a->count;
	while (++i < the_number_of_els - s_a->s_count)
		pb(s_a, s_b);
	while (s_b->count)
		ft_agamotto_eye(s_a, s_b);
	if (s_a->count / 2 < ft_get_place(s_a, start))
		while (s_a->head->value != start)
			rra(s_a);
	else
		while (s_a->head->value != start)
			ra(s_a);
}
