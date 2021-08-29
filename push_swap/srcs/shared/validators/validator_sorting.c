/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:24:32 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/30 01:07:22 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	validator_sorting(t_stack *stk)
{
	int		i;
	int		sorting_count;
	t_node	*n;

	i = -1;
	sorting_count = 0;
	n = stk->head;
	while (stk->count - 1 > ++i)
	{
		if (n->value > n->next->value)
			break ;
		else
			sorting_count++;
		n = n->next;
	}
	if (sorting_count == stk->count - 1)
		return (1);
	return (0);
}
