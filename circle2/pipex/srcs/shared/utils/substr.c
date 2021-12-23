/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:57:10 by pac-man           #+#    #+#             */
/*   Updated: 2021/12/23 10:40:05 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

char	*substr(char *s, int from, int to)
{
	char	*tmp_s;
	char	*tmp;

	tmp_s = ft_strdup(s);
	tmp_s += from;
	tmp = (char *)malloc(sizeof(char) * (to - from));
	if (!tmp)
		ft_putstr_fd("Error : [substr: Malloc Error]\n", STDERR_FILENO);
	tmp_s[to - from] = 0;
	tmp = tmp_s;
	return (tmp);
}
