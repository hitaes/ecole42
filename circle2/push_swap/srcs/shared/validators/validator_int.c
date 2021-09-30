/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:21:59 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/29 21:41:37 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	validator_int(t_stack *stk, int i)
{
	long long	num;
	char		*s;
	int			s_len;

	num = 0;
	s = stk->v_str[i];
	s_len = ft_strlen(s);
	if (s_len > 12)
	{
		ft_free(stk, STDERR_FILENO);
	}
	else if (s_len >= 11 && (s[0] != '-' && s[0] != '+'))
	{
		ft_free(stk, STDERR_FILENO);
	}
	else
	{
		num = ft_atoi(s);
		if (num > INT_MAX || num < INT_MIN)
			ft_free(stk, STDERR_FILENO);
	}
	return ((int)num);
}
