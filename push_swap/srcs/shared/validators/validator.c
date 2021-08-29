/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:00:29 by taeskim           #+#    #+#             */
/*   Updated: 2021/08/30 00:10:15 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	validator(t_stack *stk, int the_number_of_els, char c)
{
	int	*i;

	i = &(stk->v_nums_count);
	stk->v_nums = (int *)malloc(sizeof(int) * the_number_of_els);
	if (!(stk->v_nums))
		ft_free(stk, STDERR_FILENO);
	if (!(stk->v_str[0]))
		ft_free(stk, STDERR_FILENO);
	while ((*i) < the_number_of_els)
	{
		stk->v_nums[*i] = validator_num(stk, *i, c);
		++(*i);
	}
	validator_duplicate(stk);
}
