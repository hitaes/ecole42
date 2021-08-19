/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:12:38 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/19 17:33:38 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_sorting_all(stack *s_a, stack *s_b)
{
	while (s_a->count > 3)
		ft_agamotto_eye(s_b, s_a, 'd', s_a->count);
	ft_sorting_three(s_a);
	while (s_b->count)
		ft_agamotto_eye(s_a, s_b, 'a', s_b->count);
	ft_to_base(s_a, 'a');
	// printf("✅s_a->s_index: %d, s_a->s_count: %d\n", s_a->s_index, s_a->s_count);
}
