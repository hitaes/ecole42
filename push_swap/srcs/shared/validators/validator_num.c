/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:20:32 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/29 22:33:07 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	validator_num(t_stack *stk, int i, char c)
{
	int		j;
	char	*s;

	j = 0;
	s = stk->v_str[i];
	while (s[j])
	{
		if (!(ft_isdigit(s[j])) && s[0] != '-' && s[0] != '+' && s[j] != c)
			ft_free(stk, STDERR_FILENO);
		j++;
	}
	while (*s == c)
		s++;
	return (validator_int(stk, i));
}
