/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pacman <pacman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:59:53 by pac-man           #+#    #+#             */
/*   Updated: 2021/12/23 17:45:14 by pacman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*buff;

	len = ft_strlen(s);
	if (!ft_calloc((void **)(&buff), len + 1, sizeof(char)))
		return (NULL);
	ft_strlcpy(buff, s, len + 1);
	return (buff);
}

char	*ft_strndup(const char *src, size_t size)
{
	char	*dst;
	size_t	i;

	dst = malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (0);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
