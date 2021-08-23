/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:12:38 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/23 17:52:19 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_sorting_all(stack *s_a, stack *s_b)
{
	int counter;
	double weight;
	int i;

	weight = 2;
	counter = (s_a->count / weight) + 1;
	i = -1;

	while (++i < s_a->s_list_count)
	{
	}

	// counter = 51;
	// while (--counter)
	ft_agamotto_eye(s_b, s_a, 'd', s_a->count);
	// while (s_b->count)
	// {
	// 	ft_agamotto_eye(s_a, s_b, 'a', s_b->count);
	// }

	// counter = 0;
	// while (s_a->count)
	// {
	// 	pb(s_a, s_b);
	// 	counter++;
	// }
	// while (--counter)
	// {
	// 	place = ft_get_place(s_a, s_b->head->value, 'a');
	// 	ft_insert_el(s_a, s_b, place, s_b->head->value);
	// }
	// while (s_b->count)
	// {
	// 	ft_agamotto_eye(s_a, s_b, 'a', s_b->count);
	// }
	// ft_to_base(s_a, 'a');
}
