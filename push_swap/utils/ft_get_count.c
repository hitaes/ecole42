/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 23:40:06 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/23 23:40:52 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_get_count(int argc, char **argv)
{
	int i;
	int j;
	int count;

	i = 0;
	j = -1;
	count = 0;
	while (++i < argc)
	{
		while (argv[i][++j])
			if (argv[i][j] == ' ')
				count++;
		count++;
	}
	return (count);
}
