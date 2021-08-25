/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:21:59 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/26 01:33:06 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	validator_int(char *s)
{
	long long	num;
	int			s_len;

	num = 0;
	s_len = ft_strlen(s);
	if (s_len > 12)
	{
		ft_error_disposal();
	}
	else if (s_len >= 11 && (s[0] != '-' && s[0] != '+'))
	{
		ft_error_disposal();
	}
	else
	{
		num = ft_atoi(s);
		if (num <= INT_MAX && num >= INT_MIN)
			return ((int)num);
		else
			ft_error_disposal();
	}
	return (num);
}
