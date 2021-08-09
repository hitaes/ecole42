/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:24:32 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/08 15:05:20 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void validator_sorting(stack *stk)
{
	int sorted_el;
	int tmp_count;
	node *tmp;

	sorted_el = 0;
	tmp_count = stk->count;
	tmp = stk->head;
	while (tmp_count - 1 > 0)
	{
		if (tmp->value < tmp->next->value)
			sorted_el++;
		tmp_count--;
		tmp = tmp->next;
	}
	if (stk->count - 1 == sorted_el)
	{
		exit(1);
	}
}
