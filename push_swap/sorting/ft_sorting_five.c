/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 02:11:15 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/09 17:49:24 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 12회 이하로 정리

// void ft_sorting_double_pack(stack *s_a, stack *s_b)
// {
// 	if (s_a->head->value > s_a->head->next->value)
// 	{
// 		if (s_b->head->value < s_b->head->next->value)
// 			ss(s_a, s_b);
// 		else
// 			sa(s_a);
// 	}
// 	else if (s_b->head->value < s_b->head->next->value)
// 		sb(s_b);
// }

void ft_sorting_five(stack *s_a, stack *s_b)
{
	pb(s_a, s_b);
	pb(s_a, s_b);
	ft_sorting_three(s_a);
}
