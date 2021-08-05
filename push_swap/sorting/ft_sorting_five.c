/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:11:15 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/05 16:35:10 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_sorting_five(stack *s_a, stack *s_b)
{
	int i;
	int tmp_count;

	i = -1;
	tmp_count = s_a->count;
	while (++i < tmp_count / 2)
		pb(s_a, s_b);
	i = -1;
	ft_sorting_three(s_a);
	while (s_b->count && ++i < tmp_count)
	{
		if (s_a->head->value < s_b->head->value)
		{
			ra(s_a);
		}
		else
			pa(s_b, s_a);
	}
	// printf("✅tmp_count: %d, i: %d\n", tmp_count, i);
	// // while (j-- > 0)
	// // 	ra(s_a);
}
