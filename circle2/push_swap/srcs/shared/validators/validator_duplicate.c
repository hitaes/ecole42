/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_duplicate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:23:25 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/29 22:50:07 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	validator_duplicate(t_stack *stk)
{
	int	i;
	int	j;
	int	*v_nums;

	i = -1;
	j = 0;
	v_nums = stk->v_nums;
	while (stk->v_nums_count > ++i)
	{
		while (stk->v_nums_count > ++j)
			if (v_nums[i] == v_nums[j])
				ft_free(stk, STDERR_FILENO);
		j = i + 1;
	}
}
