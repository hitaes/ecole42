/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 00:17:00 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/08 20:46:24 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_sorting_three(stack *s_a)
{
	int count;

	count = s_a->count;
	while (count--)
		if (s_a->head->value > s_a->head->next->value)
			sa(s_a);
		else if (s_a->head->next->value > s_a->head->next->next->value)
		{
			rra(s_a);
			if (s_a->head->value > s_a->head->next->value)
				sa(s_a);
		}
}
