/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:11:15 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/19 13:04:23 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_sorting_five(stack *s_a, stack *s_b)
{
	int counter;

	counter = 3;
	pb(s_a, s_b);
	pb(s_a, s_b);
	ft_sorting_three(s_a);
	while (--counter)
		ft_agamotto_eye(s_a, s_b, 'a', counter);
	if (s_a->count == 5)
		ft_to_base(s_a, 'a');
}
