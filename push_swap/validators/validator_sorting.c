/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:24:32 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/30 17:16:55 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void validator_sorting(stack *stk)
{
	int sorted_el;
	int tmp_count;

	sorted_el = 0;
	tmp_count = stk->count;
	while (tmp_count)
	{
		if (stk->head->value > stk->head->next->value)
			sorted_el++;
		tmp_count--;
		stk->head = stk->head->next;
	}
	if (stk->count - 1 == sorted_el)
	{
		printf("✅ sorted!\n");
		exit(1);
	}
}
