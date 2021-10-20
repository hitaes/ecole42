/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:57:10 by pac-man           #+#    #+#             */
/*   Updated: 2021/10/20 17:57:57 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

char	*substr(t_arg *t, char *s, int from, int to)
{
	char	*tmp_s;
	char	*tmp;

	tmp_s = ft_strdup(s);
	tmp_s += from;
	tmp = (char *)malloc(sizeof(char) * (to - from));
	if (!tmp)
		error_disposal(t, MALERROR);
	tmp_s[to - from] = 0;
	tmp = tmp_s;
	return (tmp);
}