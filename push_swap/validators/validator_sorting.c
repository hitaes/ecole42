/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:24:32 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/28 12:29:12 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void validator_sorting(int count, int *v_nums)
{
	int i;
	int sorted_el;

	i = -1;
	sorted_el = 0;
	while (++i < count)
		if (v_nums[i] < v_nums[i + 1])
			sorted_el++;
	if (i - 1 == sorted_el)
	{
		printf("✅ sorted!\n");
		exit(1);
	}
}
