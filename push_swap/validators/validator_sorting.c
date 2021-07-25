/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:24:32 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/24 00:36:33 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void validator_sorting(int count, int *v_nums)
{
	int i;

	i = -1;
	while (count - ++i > 0)
		if (v_nums[i] < v_nums[i + 1])
		{
			printf("✅sorted!\n");
			exit(1);
		}
}
