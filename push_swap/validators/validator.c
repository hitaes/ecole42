/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:00:29 by taeskim           #+#    #+#             */
/*   Updated: 2021/07/24 00:29:41 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int *validator(int count, char **v_str)
{
	int i;
	int v_num;
	int *v_nums;

	i = -1;
	v_num = 0;
	v_nums = (int *)malloc(sizeof(int) * count);
	if (!(v_nums))
		return (NULL);
	while (count - ++i)
		v_nums[i] = validator_num(*(v_str + i));
	validator_duplicate(count, v_nums);
	validator_sorting(count, v_nums);
	return (v_nums);
}
