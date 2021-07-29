/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 23:40:06 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/28 10:46:34 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void state_change(int *state, int *count)
{
	*state = 0;
	(*count)++;
}

int ft_get_count(int argc, char **argv, char c)
{
	int l;
	int i;
	int j;
	int char_appear;

	l = 0;
	i = 0;
	j = -1;
	char_appear = 0;
	while (++i < argc)
	{
		while (argv[i][++j])
		{
			if (argv[i][j] != c)
				char_appear = 1;
			else if (char_appear)
				state_change(&char_appear, &l);
		}
		if (char_appear)
			state_change(&char_appear, &l);
		j = -1;
	}
	return (l);
}
