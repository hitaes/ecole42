/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:10:24 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/29 18:00:00 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pb1(stack *s_a, stack *s_b)
{
	ft_append_node(s_b, s_a->head);
	ft_remove_node(s_a, s_a->head);
}

void ft_sorting(stack *s_a, stack *s_b)
{
	ft_append_node(s_b, s_a->head);
	ft_append_node(s_b, s_a->head->next);
	ft_append_node(s_b, s_a->head->next->next);
	// ft_append_node(s_b, s_a->head->next->next);
}
