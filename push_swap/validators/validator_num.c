/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 00:20:32 by pac-man           #+#    #+#             */
/*   Updated: 2021/08/25 11:56:47 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	validator_num(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isdigit(s[i])) && s[0] != '-' && s[0] != '+' && s[i] != c)
			exit(1);
		i++;
	}
	while (*s == c)
		s++;
	return (validator_int(s));
}
