/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_duplicate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:23:25 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/27 14:47:59 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	validator_duplicate(int count, int *v_nums)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (count > ++i)
	{
		while (count > ++j)
			if (v_nums[i] == v_nums[j])
				ft_error_disposal();
		j = i + 1;
	}
}
