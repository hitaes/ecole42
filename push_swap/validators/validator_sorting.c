/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:24:32 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/13 11:26:02 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void validator_sorting(int count, int *v_nums)
{
	int i;
	int sorting_count;

	i = -1;
	sorting_count = 0;
	while (count - 1 > ++i)
	{
		if (v_nums[i] > v_nums[i + 1])
			break;
		else
			sorting_count++;
	}
	if (sorting_count == count - 1)
		exit(1);
}
