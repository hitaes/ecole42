/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:24:32 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/27 14:48:09 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	validator_sorting(int count, int *v_nums)
{
	int	i;
	int	sorting_count;

	i = -1;
	sorting_count = 0;
	while (count - 1 > ++i)
	{
		if (v_nums[i] > v_nums[i + 1])
			break ;
		else
			sorting_count++;
	}
	if (sorting_count == count - 1)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
}
