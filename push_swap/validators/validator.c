/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:00:29 by taeskim           #+#    #+#             */
/*   Updated: 2021/08/25 11:55:57 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*validator(int the_number_of_els, char **v_str, char c)
{
	int	i;
	int	v_num;
	int	*v_nums;

	i = -1;
	v_num = 0;
	v_nums = ft_calloc(sizeof(int), the_number_of_els);
	while (++i < the_number_of_els)
		v_nums[i] = validator_num(*(v_str + i), c);
	validator_duplicate(the_number_of_els, v_nums);
	validator_sorting(the_number_of_els, v_nums);
	return (v_nums);
}
