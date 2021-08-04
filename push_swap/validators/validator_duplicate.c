/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_duplicate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:23:25 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/04 17:52:37 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void validator_duplicate(int count, int *v_nums)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (count - ++i > 0)
	{
		while (count - ++j > 0)
			if (v_nums[i] == v_nums[j])
			{
				ft_putstr("✅dup\n");
				exit(1);
			}
		j = i + 1;
	}
}
