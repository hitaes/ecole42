/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:44:37 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/27 17:53:33 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	ft_free_stack(t_stack *stk, int i)
{
	t_node	*tmp_n;

	if (i != 1)
	{
		while (stk->count)
		{
			tmp_n = stk->tail->prev;
			free(stk->tail);
			stk->tail = 0;
			stk->tail = tmp_n;
			stk->count--;
		}
	}
	if (i == 0)
		exit(0);
	if (i == 1)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}
