/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:10:24 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/30 17:08:41 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_sorting(stack *s_a, stack *s_b)
{
	if (s_a->count == 2)
		if (s_a->head->value < s_a->tail->value)
			sa(s_a);

	printf("✅s_a: %lld\n", (long long)s_a);
	printf("✅s_b: %lld\n", (long long)s_b);
}
