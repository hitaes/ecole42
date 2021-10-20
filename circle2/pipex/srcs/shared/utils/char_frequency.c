/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_frequency.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:39:40 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/20 14:46:34 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

size_t	char_frequency(char *s, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == c)
			count++;
	}
	return (count);
}
