/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:11:15 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/19 12:56:36 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_sorting(stack *s_a, stack *s_b)
{
	if (s_a->count == 2)
		ft_sorting_two(s_a);
	else if (s_a->count == 3)
		ft_sorting_three(s_a);
	else if (s_a->count == 5)
		ft_sorting_five(s_a, s_b);
	else
		ft_sorting_all(s_a, s_b);
}
