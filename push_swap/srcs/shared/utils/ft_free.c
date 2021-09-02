/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:44:37 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/30 11:40:59 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	ft_free_str(char **str, int count)
{
	int	k;

	k = -1;
	while (++k < count)
	{
		free(str[k]);
		str[k] = 0;
	}
	free(str);
	str = 0;
}

void	ft_free_int(int *v_nums)
{
	free(v_nums);
	v_nums = 0;
}

void	ft_free_stack(t_stack *stk)
{
	t_node	*tmp_n;

	while (stk->count)
	{
		tmp_n = stk->tail->prev;
		free(stk->tail);
		stk->tail = 0;
		stk->tail = tmp_n;
		stk->count--;
	}
}

void	ft_free(t_stack *stk, int std_state)
{
	if (stk->v_str)
		ft_free_str(stk->v_str, stk->v_str_count);
	if (stk->v_nums)
		ft_free_int(stk->v_nums);
	if (stk)
		ft_free_stack(stk);
	if (std_state == 0)
		exit(0);
	if (std_state == 2)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(1);
	}
}
