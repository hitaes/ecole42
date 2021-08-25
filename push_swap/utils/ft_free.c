/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:44:37 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/26 01:18:47 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_stack *stk)
{
	t_node	*tmp_n;

	while (stk->count)
	{
		tmp_n = stk->tail->prev;
		free(stk->tail);
		stk->tail = tmp_n;
		stk->count--;
	}
}
