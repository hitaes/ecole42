/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pac-man <pac-man@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 02:03:05 by pac-man           #+#    #+#             */
/*   Updated: 2021/07/27 02:54:58 by pac-man          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(char *s)
{
	size_t len;
	char *buf;

	len = ft_strlen(s);
	buf = (char *)malloc(len + 1);
	if (!(buf))
		return (NULL);
	ft_strlcpy(buf, s, len + 1);
	return (buf);
}
