/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 01:18:20 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/23 01:23:21 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void validator_sign(char *str)
{
	int i;
	int sign;

	i = -1;
	sign = 0;
	while (str[++i])
	{
		if (sign && (str[i] == '+' || str[i] == '-'))
			exit(1);
		if (str[i] == '+' || str[i] == '-')
			sign = str[i];
	}
}
