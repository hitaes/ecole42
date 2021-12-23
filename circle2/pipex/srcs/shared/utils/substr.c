/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:57:10 by pac-man           #+#    #+#             */
/*   Updated: 2021/12/23 17:44:18 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

char	*substr(char *s, int from, int to)
{
	char	*tmp_s;

	tmp_s = ft_strdup(s);
	tmp_s += from;
	tmp_s[to - from] = 0;
	return (tmp_s);
}
